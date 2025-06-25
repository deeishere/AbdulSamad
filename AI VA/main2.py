import sounddevice as sd
import queue
import vosk
import json

# brew install wget
# wget https://alphacephei.com/vosk/models/vosk-model-small-en-us-0.15.zip
# unzip vosk-model-small-en-us-0.15.zip

model = vosk.Model("vosk-model-small-en-us-0.15")
q = queue.Queue()

def callback(indata, frames, time, status):
    q.put(bytes(indata))

with sd.RawInputStream(samplerate=16000, blocksize=8000, dtype='int16',
                       channels=1, callback=callback):
    rec = vosk.KaldiRecognizer(model, 16000)
    print("Speak into the mic...")
    while True:
        data = q.get()
        if rec.AcceptWaveform(data):
           result_dict = json.loads(rec.Result())  # dict
           text = result_dict.get("text", "").strip()  # string
           print("You said:", text)
           break
    






import os
from azure.ai.inference import ChatCompletionsClient
from azure.ai.inference.models import SystemMessage, UserMessage
from azure.core.credentials import AzureKeyCredential

#token = "ghu_yFX6B90SeHDlwlNGkq2ikLIJZAnDOK4WXRSI"

endpoint = "https://models.github.ai/inference"
model = "mistral-ai/mistral-medium-2505"

client = ChatCompletionsClient(
    endpoint=endpoint,
    credential=AzureKeyCredential(token),
)

while True:
    #user_input = input("Enter ingredients (comma-separated): ")
    ingredients = [item.strip() for item in text.split('and') if item.strip()]
    answer = input("Do you want to edit ingredients? Yes or No\n")
    if answer.lower() == "no":
        break

# Formulate the prompt
prompt_content = (
    "Please create a recipe using the following ingredients: "
    f"{'and'.join(ingredients)}. "
    "The approximate time to do it 'Approximate Time:'"
    "Include a creative name with 'Recipe Title:', "
    "an introduction with 'Introduction:', "
    "ingredients with 'Ingredients:', and "
    "cooking steps with 'Cooking Steps:'."
)




response = client.complete(
    messages=[
        SystemMessage("You are a bilingual helpful assistant for a drone and robotics club. Always respond in short and concise manner."),
        UserMessage(prompt_content),
    ],
    max_tokens=1000,
    model=model
)
generated_text=response.choices[0].message.content
from gtts import gTTS
import os

# Text-to-speech output
tts = gTTS(generated_text, lang='en')
tts.save("speech.mp3")
os.system("mpg321 speech.mp3")  # use afplay on macOS if mpg321 not installed
