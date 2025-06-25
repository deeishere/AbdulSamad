from gtts import gTTS
import os

tts = gTTS("Hello, this is Google TTS speaking", lang='en')
tts.save("speech.mp3")
os.system("mpg321 speech.mp3")
