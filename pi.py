import openai
from gpiozero import LED
from flask import Flask, request, jsonify

# Initialize ChatGPT
openai.api_key = "YOUR_OPENAI_API_KEY"

# Example GPIO pins
light = LED(17)  # GPIO17

# Flask API for voice/text chat
app = Flask(__name__)

def ask_chatgpt(prompt):
    response = openai.ChatCompletion.create(
        model="gpt-4",
        messages=[
            {"role": "system", "content": "You're a home assistant controlling lights and fans."},
            {"role": "user", "content": prompt}
        ]
    )
    return response.choices[0].message['content']

def control_devices(command):
    cmd = command.lower()
    if "turn on the light" in cmd:
        light.on()
        return "Light turned on."
    elif "turn off the light" in cmd:
        light.off()
        return "Light turned off."
    else:
        return ask_chatgpt(command)

@app.route("/chat", methods=["POST"])
def chat():
    user_input = request.json.get("message")
    response = control_devices(user_input)
    return jsonify({"response": response})

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
