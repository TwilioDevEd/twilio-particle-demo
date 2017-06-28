/* 
Basic example of sending a SMS with Twilio and a Particle Photon.

Author: Paul Kamp, Twilio Developer Education
License: MIT
*/

String body = "Hey, this is your Particle Photon!";

void setup() {
  Particle.publish("twilio_sms", body, PRIVATE);
  Serial.begin(115200);
}

void loop() {
    Serial.println("That's all!  You can restart or edit the code now.");
    delay(60000);
}