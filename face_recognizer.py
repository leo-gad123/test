import cv2
import mediapipe as mp  #this is who i am

# Initialize MediaPipe face detection
mp_face = mp.solutions.face_detection
mp_drawing = mp.solutions.drawing_utils

# Start webcam
cap = cv2.VideoCapture(0)

with mp_face.FaceDetection(model_selection=0, min_detection_confidence=0.5) as face_detection:
    while True:
        ret, frame = cap.read()
        if not ret:
            break

        # Convert image to RGB (MediaPipe requires RGB)
        rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # Detect faces
        results = face_detection.process(rgb)

        # Draw detection results
        if results.detections:
            for detection in results.detections:
                mp_drawing.draw_detection(frame, detection)

        # Display
        cv2.imshow("MediaPipe Face Detection", frame)

        # Quit when 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

cap.release()
cv2.destroyAllWindows()
