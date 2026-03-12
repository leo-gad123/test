from flask import Flask, render_template, request, redirect, url_for
import os
import torch
from PIL import Image

app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = 'static/uploads'
app.config['DETECTION_FOLDER'] = 'static/detections'

# Load YOLO model (replace 'best.pt' with your trained weights)
model = torch.hub.load(
    path='yolov5us.pt', 
    force_reload=True, 
    trust_repo=True
)
@app.route('/', methods=['GET', 'POST'])
def index():
    detected_image_url = None
    if request.method == 'POST':
        # Check if file was uploaded
        if 'image' not in request.files:
            return redirect(request.url)
        file = request.files['image']
        if file.filename == '':
            return redirect(request.url)
        
        # Save uploaded image
        img_path = os.path.join(app.config['UPLOAD_FOLDER'], file.filename)
        file.save(img_path)

        # Run YOLO detection
        results = model(img_path)
        # Render results on image
        results.save(save_dir=app.config['DETECTION_FOLDER'])
        
        detected_image_url = url_for('static', filename=f'detections/{file.filename}')
    
    return render_template('index.html', detected_image=detected_image_url)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)