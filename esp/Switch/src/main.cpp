#include <Arduino.h>
#include <status.h>
#include <ESPAsyncWebServer.h>

StatusDisplay Status;

AsyncWebServer server(80);

void setup()
{
  Status.begin();
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.softAP("ESP32", "password");
  WiFi.softAPConfig(IPAddress(10, 0, 0, 10), IPAddress(10, 0, 0, 201), IPAddress(255, 0, 0, 0));

  server.on("/toggle", HTTP_POST, [&](AsyncWebServerRequest *request) {
    Serial.print("Got toggle request ");

    Status.connected();

    if(request->hasParam("state")) {
      auto state = request->getParam("state");

      Serial.print(state->value());

      auto isOn = state->value().equalsIgnoreCase("on");

      if (isOn) {
        Status.switchedOn();
      }
      else {
        Status.switchedOff();
      }
    }

    Serial.println();
    request->send(200);
  });

  server.begin();

  Status.init();
}

void loop()
{
  delay(1000);
}
