//Nho add board ESP8266 va chon board ESP8266.
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <ESP8266WebServer.h>
const char* ssid = "<SSID>";
const char* password = "Password";
ESP8266WebServer server(80);
const char* www_username = "<Name Access>";
const char* www_password = "<Password Access>";
String webPage;
void setup() {
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(14, OUTPUT);
   pinMode(16, OUTPUT);
  webPage += "<h1>GPIO4 - Relay1</h1><p>Socket #1 <a href=\"ON1\"><button>ON</button></a>&nbsp;<a href=\"OFF1\"><button>OFF</button></a></p>";
  webPage += "<h1>GPIO5 - Relay2</h1><p>Socket #1 <a href=\"ON2\"><button>ON</button></a>&nbsp;<a href=\"OFF2\"><button>OFF</button></a></p>";
  webPage += "<h1>GPIO12 - Relay3</h1><p>Socket #1 <a href=\"ON3\"><button>ON</button></a>&nbsp;<a href=\"OFF3\"><button>OFF</button></a></p>";
  webPage += "<h1>GPIO14 - Relay4</h1><p>Socket #1 <a href=\"ON4\"><button>ON</button></a>&nbsp;<a href=\"OFF4\"><button>OFF</button></a></p>";
  webPage += "<h1>GPIO16 - Relay5</h1><p>Socket #1 <a href=\"ON5\"><button>ON</button></a>&nbsp;<a href=\"OFF5\"><button>OFF</button></a></p>";
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  ArduinoOTA.begin();
  html();
  server.begin();
}
void loop() {
  ArduinoOTA.handle();
  server.handleClient();
}
void html(){
  server.on("/", []() {
    if (!server.authenticate(www_username, www_password)) {
      return server.requestAuthentication();
    }
    server.send(200, "text/html", webPage);
  });
  server.on("/ON1", []() {
    if (server.authenticate(www_username, www_password)) {
      server.send(200, "text/html", webPage);
      digitalWrite(4,HIGH);
      delay(200);
    }
  });
  server.on("/OFF1", []() {
    if (server.authenticate(www_username, www_password)) {
      server.send(200, "text/html", webPage);
      digitalWrite(4,LOW);
      delay(200);
    }
  });
  server.on("/ON2", []() {
    if (server.authenticate(www_username, www_password)) {
      server.send(200, "text/html", webPage);
      digitalWrite(5,HIGH);
      delay(200);
    }
  });
  server.on("/OFF2", []() {
    if (server.authenticate(www_username, www_password)) {
      server.send(200, "text/html", webPage);
      digitalWrite(5,LOW);
      delay(200);
    }
  });
  server.on("/ON3", []() {
    if (server.authenticate(www_username, www_password)) {
      server.send(200, "text/html", webPage);
      digitalWrite(12,HIGH);
      delay(200);
    }
  });
  server.on("/OFF3", []() {
    if (server.authenticate(www_username, www_password)) {
      server.send(200, "text/html", webPage);
      digitalWrite(12,LOW);
      delay(200);
    }
  });
  server.on("/ON4", []() {
    if (server.authenticate(www_username, www_password)) {
      server.send(200, "text/html", webPage);
      digitalWrite(14,HIGH);
      delay(200);
    }
  });
  server.on("/OFF4", []() {
    if (server.authenticate(www_username, www_password)) {
      server.send(200, "text/html", webPage);
      digitalWrite(14,LOW);
      delay(200);
    }
  });
  server.on("/ON5", []() {
    if (server.authenticate(www_username, www_password)) {
      server.send(200, "text/html", webPage);
      digitalWrite(16,HIGH);
      delay(200);
    }
  });
  server.on("/OFF5", []() {
    if (server.authenticate(www_username, www_password)) {
      server.send(200, "text/html", webPage);
      digitalWrite(16,LOW);
      delay(200);
    }
  });
}
