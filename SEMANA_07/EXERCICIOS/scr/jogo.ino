#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>
// set pin numbers
const int buttonPin = 12;  // the number of the pushbutton pin
const int ledPin =  11;    // the number of the LED pin

// variable for storing the pushbutton status 
int buttonState = 0;


const char *ssid = "Ex7Carol";
const char *password = "carol1234";

WebServer server(80);

void rootPoint(){
String html = "";
  html +="<!DOCTYPE html> <html lang='en'> <head> <meta charset='UTF-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1.0'> <style> .panel { height: 100vh; display: flex; flex-direction: column; justify-content: center; align-items: center; } .question-container { margin: 10px; padding: 5px; width: 80vw; height: 10vh; font-size: x-large; text-align: center; } .result { margin: 10px; padding: 5px; width: 80vw; height: 10vh; text-align: center; font-size: 50px; } .option-container { display: flex; justify-content: space-around; margin: 10px; padding: 5px; width: 80vw; height: 20vh; } .option { padding: 10px; width: 15vw; height: 10vh; font-size: larger; } .option:hover { background-color: lightgoldenrodyellow; } </style> </head> <body> <div class='rules'> </div> <div class='panel'> <div id='result'> </div> <div class='question-container' id='question'> Quem vai ganhar a copa? </div> <div class='option-container'> <button className='option' value=\"true\" onclick=\"check()\" id='op1'>Brasil</button> <button className='option' value=\"false\" onclick=\"error()\" id='op2'>Alemanha</button> <button className='option' value=\"false\" onclick=\"error()\" id='op3'>Portugal</button> <button className='option' value=\"false\" onclick=\"error()\" id='op4'>Espanha</button> </div> <div class='navigation'></div> </div> <script> function check() { var result = document.getElementById('result'); result.innerHTML = 'Certa'; result.style.color='green';window.location.href='/blue'; } function error(){ var result = document.getElementById('result'); result.innerHTML = 'Errada'; result.style.color='red'; } </script> </body> </html>";

  server.send(200,"text/html",html);
}

// void end(){
// String html = "";
//   html += 
//   server.send(200,"text/html",html);
// }



void setup() {
Serial.begin(115200);

WiFi.softAP(ssid,password);
IPAddress myIP = WiFi.softAPIP();
Serial.print("SSID: ");
Serial.println(ssid);
Serial.print("AP IP address: ");
Serial.println(myIP);

server.on("/",rootPoint);
server.on("/blue", bluePoint);


server.begin();
Serial.println("Servidor Iniciado");

  // initialize the pushbutton pin as an input
pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
pinMode(ledPin, OUTPUT);
}

void bluePoint(){
  digitalWrite(ledPin,1);
  delay(1000);
  rootPoint();
}

void loop() {
server.handleClient(); 
delay(2);

  digitalWrite(ledPin, LOW);
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == 1) {
    // turn LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off
      digitalWrite(ledPin,LOW);
}
}