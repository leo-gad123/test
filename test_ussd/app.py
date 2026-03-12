from flask import Flask, request

app = Flask(__name__)

@app.route('/ussd', methods=['POST'])
def ussd():

    session_id = request.form.get("sessionId")
    service_code = request.form.get("serviceCode")
    phone_number = request.form.get("phoneNumber")
    text = request.form.get("text")

    if text == "":
        response = "CON Welcome to my USSD App\n"
        response += "1. My Account\n"
        response += "2. My Phone Number"

    elif text == "1":
        response = "END Your account is active"

    elif text == "2":
        response = f"END Your phone number is {phone_number}"

    else:
        response = "END Invalid choice"

    return response


if __name__ == '__main__':
    app.run(port=5000, debug=True)