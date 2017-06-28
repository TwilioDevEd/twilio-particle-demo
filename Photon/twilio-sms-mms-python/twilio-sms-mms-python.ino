/* 
More complex example of sending a MMS with Twilio and a Particle Photon.

We can publish to two event names:
- twilio_sms, which works like the basic example
- twilio_mms, which adds picture_url support

Author: Paul Kamp, Twilio Developer Education
License: MIT
*/

String body = "Hey, this owl was sent from a Particle Photon!";
String img  = "https://upload.wikimedia.org/wikipedia/commons/thumb/9/98/GreatHornedOwl-Wiki.jpg/800px-GreatHornedOwl-Wiki.jpg";

/* 
 * Function to send either a MMS or a SMS depending on the content of 'image'
 *
 * Note that your application will have to mind character encodings and limits.
 * The '"' character, in particular, will need to be escaped.
 */
void sendMessage(const String& body, const String& image)
{
    if ( image.length() > 0 ) {
        String json = \
            String(
                "{\"body\": \"" + String(body) +
                "\", \"image\": \"" + String(image) +"\"}"
            );
        Particle.publish("twilio_mms", json, PRIVATE);
    } else {
        Particle.publish("twilio_sms", body, PRIVATE);
    }
    
}

void setup() 
{
    sendMessage(body, img);
    Serial.begin(115200);
}

void loop() 
{
    Serial.println("That's all!  You can restart or edit the code now.");
    delay(60000);
}