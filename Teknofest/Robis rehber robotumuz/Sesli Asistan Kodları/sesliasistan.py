from playsound import playsound
from datetime import datetime
import speech_recognition as sr
from gtts import gTTS
import random
import os
import time


#Kullanılan kütüphaneler;
##SpeechRecognition
#gTTS  (Google Text to Speech)
#playsound 1.3.3 kutuphanesı hata verdıgı ıcın
#pip install playsound==1.2.2 surumunu kullanıyorum
#PyAudio


r = sr.Recognizer()

def record(ask = False):
    with sr.Microphone() as source:
        if ask:
            print(ask)
        audio = r.listen(source)
        voice = ""
        try:
            voice = r.recognize_google(audio , language='tr-TR')
        except sr.UnknownValueError:
            print('anlayamadım')
            speak("anlayamadım")
        except sr.RequestError:
            print('sistem çalışmıyor')   
            speak('sistem çalışmıyor')      
        return voice


def response(voice):
     
        if 'merhaba' in voice:
            speak('merhaba')
        
        if 'nasılsın' in voice:
            speak('iyiyim sen nasılsın') 
           
        
        if 'bu projeyi kim yaptı' in voice:
            speak('Murat emiroğlu  mahmut kodas elif edanur sesli muhammedcan özcan ve akademisyen kadir tohmadan oluşan ekibimizin çalışmaları sonucu sizlere hizmet vermek için yapıldım ')

        if 'saat kaç' in voice:
            speak(datetime.now().strftime('%H:%M:%S'))

        if 'hangi yıl yapıldı' in voice:
            speak('iki bin yirmi iki yılında yapıldım') 

        if 'nerede yapıldı' in voice:
            speak('hatayda ekibimizin çalışmalarıyla yapıldım')

        if 'tura başlayalım'  in voice or  'tuğra başlayalım' in voice:
            speak('turumuz başlıyor')
            time.sleep(2) 
            speak('ilk eserimiz iskender lahdi')   
            speak('milattan önce dördüncü yızyılın sonlarına ait bir eserdir')
            speak('büyük iskenderin alçak kabartmalı tasviri yer alıyor')
            speak('eser oldukça iyi korunmuş ve yüksek estetik başarısı ile göze çarpıyor')
            speak('iskender lahdi olarak anılmasına rağmen iskender arafından göreve getirilen ve milattan önce üç yüz on bir yılında ölen sidon kralı abdalonymusa ait olduğu düşünülüyor')
            speak('sonraki eserimiz ile devam edelim')
            time.sleep(60) #1dk bekleme
            speak('sıradaki eserimiz sidamara lahdi') 
            speak('roma dönemi milattan sonra üçüncü yüzyılın ikinci yarısına ait bir eserdir')
            speak('ismini bulunduğu yerden alan ve bağımsız veya özgün bir grup olarak ele alınan sidamara lahdi, bin sekiz yüz yetmiş beş yılında bulundu')
            speak('anadoluda sıklıkla görülmesi sebebiyle anadolu kökenli bir lahit tipi olduğu düşünülmektedir')
            speak('sidamara lahdi otuz iki tonluk ağırlığı ile bilinen en ağır lahit olma özelliğini taşıyor') 
            speak('sonraki eserimiz ile devam edelim')
            time.sleep(60) #1dk bekleme
            speak('sıradaki eserimiz herakles lahdi')
            speak('perge antik kentinden kaçırılan ve isviçrede ele geçirildikten sonra türkiyeye iade edilen herakles lahdi nilattan sonra ikinci yüzyıl Roma dönemine ait ve üzerinde heraklesin on iki işi tasvir ediliyor')
            speak('arkeoloji literatüründe torre nove olarak adlandırılan tipte küçük asya lahit grubuna giren eser yaklaşık iki yüz otuz beş santimetre boyunda yüz on iki santimetre genişliğinde ve üç ton ağırlığındadır')
            time.sleep(1)
            speak('turumuzun sonuna geldik')
            speak('turumuza katılan herkese teşekkür ediyoruz')

        if 'neler yapabiliyorsun' in voice:
            speak('Sana birçok tarihi konuda bilgi verebilirim. Aynı zamanda merak ettiğin sorulara da cevap verebilirim.')  

        if 'kapat' in voice or 'sistem kapat'in voice:
            speak('görüşürüz') 
            exit() 
           
            #exıt yerıne
            #time.sleep(10) 10 sn bekle sonra sıstemı tekrar ac demek 
            #uyku moduna almak icin kullanilabilinir
            #yazan saniye sonrasi sistem otomatik tekrar calisacaktir

        
  

def speak(string):
    tts = gTTS(text=string, lang='tr', slow=False)
    rand = random.randint(1,10)
    #file="answer.mp3"
    file = str(rand)+'.mp3'
    tts.save(file)
    playsound(file)
    os.remove(file)   

speak('merhaba Ben avesta size nasıl yardımcı olabilirim')

while True:
    voice = record()
    if voice != "":
      voice= voice.lower()
      print(voice)
      response(voice)

#Muhammedcan ÖZCAN
#https://arkeofili.com/turkiye-muzelerinde-gorulmesi-gereken-50-eser/ eser kaynakçası