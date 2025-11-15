import cv2
import numpy as np
from tensorflow.keras.models import load_model

# =====================================================
# 1️⃣ Load your trained model
# ======================================================
model = load_model('image_classifier2.h5')  # path to your trained model
classes = ['Human', 'Animal', 'Items']    # same order as training

# ======================================================
# 2️⃣ Open webcam
# ======================================================
cap = cv2.VideoCapture(0)  # 0 = default webcam

if not cap.isOpened():
    print("❌ Cannot open webcam")
    exit()

# ======================================================
# 3️⃣ Real-time video loop
# ======================================================
while True:
    ret, frame = cap.read()
    if not ret:
        print("❌ Failed to grab frame")
        break

    # Preprocess frame for model
    img_resized = cv2.resize(frame, (150, 150))  # same as training
    img_array = np.expand_dims(img_resized.astype(np.float32)/255.0, axis=0)

    # Predict
    pred = model.predict(img_array)
    predicted_class = classes[np.argmax(pred)]
    confidence = np.max(pred) * 100

    # Display prediction on frame
    cv2.putText(frame, f'{predicted_class} ({confidence:.1f}%)', (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    # Show the frame
    cv2.imshow('Real-Time Classifier', frame)

    # Press 'q' to quit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# ======================================================
# 4️⃣ Release resources
# ======================================================
cap.release()
cv2.destroyAllWindows()
