#include <Arduino.h>
#include <output.h>
#include <status.h>
#include <ESPAsyncWebServer.h>
#include <secrets.h>

OutputClass output;
StatusDisplay status;
AsyncWebServer server(80);

void setup()
{
  status.begin();
  output.begin();

  Serial.begin(115200);

  WiFi.mode(WIFI_AP);
  WiFi.begin(SSID, SSIDpassword);
  WiFi.config(IPAddress(192, 168, 178, 230), IPAddress(192, 168, 178, 1), IPAddress(255, 255, 255, 0));

  while (!WiFi.isConnected()) {
    Serial.println("Connecting..");
    
    delay(100);
  }

  status.connected();

  Serial.println(WiFi.localIP());

  server.on("/state", HTTP_GET, [&](AsyncWebServerRequest *request) {
    Serial.println("Got state request ");

    request->send(200, "text/plain", output.state() ? "on" : "off");
  });


  server.on("/toggle", HTTP_POST, [&](AsyncWebServerRequest *request) {
    Serial.print("Got toggle request ");

    if(request->hasParam("state")) {
      auto state = request->getParam("state");

      Serial.print(state->value());

      auto isOn = state->value().equalsIgnoreCase("on");

      if (isOn) {
        status.switchedOn();
        output.switchedOn();
      }
      else {
        status.switchedOff();
        output.switchedOff();
      }
    }

    Serial.println();
    request->send(200);
  });

  server.begin();

  status.init();
}

void loop()
{
  delay(1000);
}
