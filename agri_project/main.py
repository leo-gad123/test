# app.py - YOLOv8 Prediction API with Flask
# Fixed OpenCV type errors by early PIL → numpy BGR conversion

from flask import Flask, request, jsonify
from ultralytics import YOLO
from PIL import Image
import io
import base64
import cv2
import numpy as np
import logging

app = Flask(__name__)

# Optional: better logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

# Load model once at startup (critical for performance)
try:
    # Change this to your actual model path
    model = YOLO("yolov8s.pt")           # or "path/to/best.pt"
    device = str(model.device)           # 'cuda:0' or 'cpu'
    logger.info(f"YOLOv8 model loaded successfully on {device}")
except Exception as e:
    logger.error(f"Failed to load model: {e}")
    raise e


def draw_boxes(results) -> str:
    """
    Use Ultralytics .plot() to draw boxes → return base64 JPEG
    """
    try:
        # results[0].plot() returns annotated numpy array (BGR)
        annotated_img = results[0].plot()
        success, buffer = cv2.imencode(".jpg", annotated_img)
        if not success:
            return ""
        jpg_base64 = base64.b64encode(buffer).decode("utf-8")
        return f"data:image/jpeg;base64,{jpg_base64}"
    except Exception as e:
        logger.error(f"Failed to draw boxes: {e}")
        return ""


@app.route("/predict", methods=["POST"])
def predict():
    if "file" not in request.files:
        return jsonify({"error": "No file part in request"}), 400

    file = request.files["file"]
    if file.filename == "":
        return jsonify({"error": "No selected file"}), 400

    if not file.content_type.startswith("image/"):
        return jsonify({"error": "Uploaded file must be an image"}), 400

    try:
        # Read and open image
        contents = file.read()
        pil_img = Image.open(io.BytesIO(contents)).convert("RGB")

        # Convert to OpenCV format early → prevents numpy/array errors in Ultralytics/OpenCV
        img_cv = cv2.cvtColor(np.array(pil_img), cv2.COLOR_RGB2BGR)

        # Run YOLOv8 inference
        results = model.predict(
            img_cv,
            conf=0.25,          # ← tune as needed
            iou=0.45,
            imgsz=640,
            verbose=False
            # half=True,        # FP16 → faster on GPU (uncomment if needed)
            # device="cpu",     # force cpu if you want
        )

        # Parse detections
        detections = []
        for r in results:
            for box in r.boxes:
                x1, y1, x2, y2 = box.xyxy[0].tolist()
                conf = float(box.conf)
                cls_id = int(box.cls)
                class_name = r.names[cls_id]   # model.names also works

                detections.append({
                    "class": class_name,
                    "confidence": round(conf, 4),
                    "bbox": [round(x1), round(y1), round(x2), round(y2)],
                })

        # Optional: annotated image with boxes (base64)
        annotated_base64 = draw_boxes(results)

        response = {
            "num_detections": len(detections),
            "detections": detections,
        }

        if annotated_base64:
            response["image_with_boxes"] = annotated_base64

        return jsonify(response)

    except Exception as e:
        logger.error(f"Prediction failed: {str(e)}")
        return jsonify({"error": str(e)}), 500


@app.route("/")
def home():
    return jsonify({
        "message": "YOLOv8 Flask API is running",
        "endpoint": "/predict (POST multipart/form-data with key 'file')",
        "example_curl": "curl -X POST -F 'file=@image.jpg' http://localhost:5000/predict"
    })


if __name__ == "__main__":
    # For development only → use gunicorn in production
    app.run(host="0.0.0.0", port=5000, debug=False, threaded=True)