#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define UP_LEFT 5
#define UP_RIGHT 6
#define DOWN_LEFT 7
#define DOWN_RIGHT 8
#define TURN_LEFT 9
#define TURN_RIGHT 10
#define STOP 0

#define FRONT_RIGHT_MOTOR 0
#define BACK_RIGHT_MOTOR 1
#define FRONT_LEFT_MOTOR 2
#define BACK_LEFT_MOTOR 3

#define FORWARD 1
#define BACKWARD -1

struct MOTOR_PINS
{
  int pinIN1;
  int pinIN2;    
};

std::vector<MOTOR_PINS> motorPins = 
{
  {16, 17},  //FRONT_RIGHT_MOTOR
  {25, 33},  //BACK_RIGHT_MOTOR
  {5, 18},  //FRONT_LEFT_MOTOR
  {27, 26}  //BACK_LEFT_MOTOR   
};

const char* ssid     = "MyWiFiCar";
const char* password = "12345678";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");


const char* htmlHomePage PROGMEM = R"HTMLHOMEPAGE(
<!DOCTYPE html>
<html>
  <head>
    <meta
      name="viewport"
      content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no"
    />
    <style>
      * {
        -webkit-box-sizing: border-box;
        -moz-box-sizing: border-box;
        box-sizing: border-box;
        margin: 0;
        padding: 0;
      }

      .nav {
        list-style: none;
        text-align: center;
      }

      .nav td {
        position: relative;
        display: inline-block;
        margin-right: -4px;
      }

      .nav td:before {
        content: "";
        display: block;
        border-top: 1px solid #ddd;
        border-bottom: 1px solid #fff;
        width: 100%;
        height: 1px;
        position: absolute;
        top: 50%;
        z-index: -1;
      }

      .nav .a {
        display: block;
        text-decoration: none;
        background-color: #f7f7f7;
        background-image: -webkit-gradient(
          linear,
          left top,
          left bottom,
          from(#f7f7f7),
          to(#e7e7e7)
        );
        background-image: -webkit-linear-gradient(top, #f7f7f7, #e7e7e7);
        background-image: -moz-linear-gradient(top, #f7f7f7, #e7e7e7);
        background-image: -ms-linear-gradient(top, #f7f7f7, #e7e7e7);
        background-image: -o-linear-gradient(top, #f7f7f7, #e7e7e7);
        color: #313030;
        margin: 26px;
        width: 64px;
        height: 64px;
        position: relative;
        text-align: center;
        line-height: 64px;
        font-size: 30px;
        border-radius: 50%;
        box-shadow: 0px 3px 8px #aaa, inset 0px 2px 3px #fff;
        border: solid 1px transparent;
      }

      .nav .a:before {
        content: "";
        display: block;
        background: #fff;
        border-top: 2px solid #ddd;
        position: absolute;
        top: -18px;
        left: -18px;
        bottom: -18px;
        right: -18px;
        z-index: -1;
        border-radius: 50%;
        box-shadow: inset 0px 8px 48px #ddd;
      }

      .nav .a:hover {
        text-decoration: none;
        color: #555;
        background: #f5f5f5;
      }
      .noselect {
        /* background-image: url("https://res.cloudinary.com/dtp5uqey3/image/upload/v1714779681/WhatsApp_Image_2024-05-03_at_08.09.52_hr8hpv.jpg");
        background-position: center;
        backdrop-filter: blur(10px); */
        /* height: 110vh; */
        background-color: white;
        display: flex;
        justify-content: center;
        align-items: center;
        flex-direction: column;
        gap: 10px;
      }
      .end {
        position: absolute;
        bottom: 0;
        left: 50%;
        transform: translateX(-50%);
        font-size: 15px;
        width: 300px;
        color: #555;
      }
      .nav .a.touched {
        box-shadow: 0px 3px 4px #aaa inset, 0px 2px 3px #fff;
      }
      .icon-home {
        user-select: none;
        -webkit-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
      }
    </style>
  </head>
  <body class="noselect" align="center">
    <h1 style="color: teal; text-align: center">ELECTRIC VEHICLE TECHNOLOGY</h1>
    <h2 style="color: teal; text-align: center">TESLA &#128663; TRUCK</h2>

    <table id="mainTable" cellspacing="10">
      <tr class="nav">
        <td
          ontouchstart='onTouchStartAndEnd("5")'
          ontouchend='onTouchStartAndEnd("0")'
        >
          <span class="a">
            <span class="icon-home">&#11017;</span>
          </span>
        </td>
        <td
          ontouchstart='onTouchStartAndEnd("1")'
          ontouchend='onTouchStartAndEnd("0")'
        >
          <span class="a">
            <span class="icon-home">&#8679;</span>
          </span>
        </td>
        <td
          ontouchstart='onTouchStartAndEnd("6")'
          ontouchend='onTouchStartAndEnd("0")'
        >
          <span class="a">
            <span class="icon-home">&#11016;</span>
          </span>
        </td>
      </tr>

      <tr class="nav">
        <td
          ontouchstart='onTouchStartAndEnd("3")'
          ontouchend='onTouchStartAndEnd("0")'
        >
          <span class="a">
            <span class="icon-home">&#8678;</span>
          </span>
        </td>
        <td>
          <span class="a">
            <span class="icon-home"></span>
          </span>
        </td>
        <td
          ontouchstart='onTouchStartAndEnd("4")'
          ontouchend='onTouchStartAndEnd("0")'
        >
          <span class="a">
            <span class="icon-home">&#8680;</span>
          </span>
        </td>
      </tr>

      <tr class="nav">
        <td
          ontouchstart='onTouchStartAndEnd("7")'
          ontouchend='onTouchStartAndEnd("0")'
        >
          <span class="a">
            <span class="icon-home">&#11019;</span>
          </span>
        </td>
        <td
          ontouchstart='onTouchStartAndEnd("2")'
          ontouchend='onTouchStartAndEnd("0")'
        >
          <span class="a">
            <span class="icon-home">&#8681;</span>
          </span>
        </td>
        <td
          ontouchstart='onTouchStartAndEnd("8")'
          ontouchend='onTouchStartAndEnd("0")'
        >
          <span class="a">
            <span class="icon-home">&#11018;</span>
          </span>
        </td>
      </tr>

      <tr class="nav">
        <td
          ontouchstart='onTouchStartAndEnd("9")'
          ontouchend='onTouchStartAndEnd("0")'
        >
          <span class="a">
            <span class="icon-home">&#8634;</span>
          </span>
        </td>
        <td style="background-color: white; box-shadow: none"></td>
        <td
          ontouchstart='onTouchStartAndEnd("10")'
          ontouchend='onTouchStartAndEnd("0")'
        >
          <span class="a">
            <span class="icon-home">&#8635;</span>
          </span>
        </td>
      </tr>
    </table>
    <p class="end">Created with <span style="color: red;">&#10084;</span> by - <br> Sree, Kuladeep, Arpit, Sai Ram</p>
    <script>
      var webSocketUrl = "ws:\/\/" + window.location.hostname + "/ws";
      var websocket;

      function initWebSocket() {
        websocket = new WebSocket(webSocketUrl);
        websocket.onopen = function (event) {};
        websocket.onclose = function (event) {
          setTimeout(initWebSocket, 2000);
        };
        websocket.onmessage = function (event) {};
      }

      function onTouchStartAndEnd(value) {
        var links = document.getElementsByClassName("a");
        for (var i = 0; i < links.length; i++) {
          links[i].classList.remove("touched");
        }
        var link = event.target.closest(".a");
        link.classList.add("touched");
        websocket.send(value);
      }

      window.onload = initWebSocket;
      document
        .getElementById("mainTable")
        .addEventListener("touchend", function (event) {
          event.preventDefault();
        });
    </script>
  </body>
</html>
)HTMLHOMEPAGE";


void rotateMotor(int motorNumber, int motorDirection)
{
  if (motorDirection == FORWARD)
  {
    digitalWrite(motorPins[motorNumber].pinIN1, HIGH);
    digitalWrite(motorPins[motorNumber].pinIN2, LOW);    
  }
  else if (motorDirection == BACKWARD)
  {
    digitalWrite(motorPins[motorNumber].pinIN1, LOW);
    digitalWrite(motorPins[motorNumber].pinIN2, HIGH);     
  }
  else
  {
    digitalWrite(motorPins[motorNumber].pinIN1, LOW);
    digitalWrite(motorPins[motorNumber].pinIN2, LOW);       
  }
}

void processCarMovement(String inputValue)
{
  Serial.printf("Got value as %s %d\n", inputValue.c_str(), inputValue.toInt());  
  switch(inputValue.toInt())
  {

    case UP:
      rotateMotor(FRONT_RIGHT_MOTOR, FORWARD);
      rotateMotor(BACK_RIGHT_MOTOR, FORWARD);
      rotateMotor(FRONT_LEFT_MOTOR, FORWARD);
      rotateMotor(BACK_LEFT_MOTOR, FORWARD);                  
      break;
  
    case DOWN:
      rotateMotor(FRONT_RIGHT_MOTOR, BACKWARD);
      rotateMotor(BACK_RIGHT_MOTOR, BACKWARD);
      rotateMotor(FRONT_LEFT_MOTOR, BACKWARD);
      rotateMotor(BACK_LEFT_MOTOR, BACKWARD);   
      break;
  
    case LEFT:
      rotateMotor(FRONT_RIGHT_MOTOR, FORWARD);
      rotateMotor(BACK_RIGHT_MOTOR, BACKWARD);
      rotateMotor(FRONT_LEFT_MOTOR, BACKWARD);
      rotateMotor(BACK_LEFT_MOTOR, FORWARD);   
      break;
  
    case RIGHT:
      rotateMotor(FRONT_RIGHT_MOTOR, BACKWARD);
      rotateMotor(BACK_RIGHT_MOTOR, FORWARD);
      rotateMotor(FRONT_LEFT_MOTOR, FORWARD);
      rotateMotor(BACK_LEFT_MOTOR, BACKWARD);  
      break;
  
    case UP_LEFT:
      rotateMotor(FRONT_RIGHT_MOTOR, FORWARD);
      rotateMotor(BACK_RIGHT_MOTOR, STOP);
      rotateMotor(FRONT_LEFT_MOTOR, STOP);
      rotateMotor(BACK_LEFT_MOTOR, FORWARD);  
      break;
  
    case UP_RIGHT:
      rotateMotor(FRONT_RIGHT_MOTOR, STOP);
      rotateMotor(BACK_RIGHT_MOTOR, FORWARD);
      rotateMotor(FRONT_LEFT_MOTOR, FORWARD);
      rotateMotor(BACK_LEFT_MOTOR, STOP);  
      break;
  
    case DOWN_LEFT:
      rotateMotor(FRONT_RIGHT_MOTOR, STOP);
      rotateMotor(BACK_RIGHT_MOTOR, BACKWARD);
      rotateMotor(FRONT_LEFT_MOTOR, BACKWARD);
      rotateMotor(BACK_LEFT_MOTOR, STOP);   
      break;
  
    case DOWN_RIGHT:
      rotateMotor(FRONT_RIGHT_MOTOR, BACKWARD);
      rotateMotor(BACK_RIGHT_MOTOR, STOP);
      rotateMotor(FRONT_LEFT_MOTOR, STOP);
      rotateMotor(BACK_LEFT_MOTOR, BACKWARD);   
      break;
  
    case TURN_LEFT:
      rotateMotor(FRONT_RIGHT_MOTOR, FORWARD);
      rotateMotor(BACK_RIGHT_MOTOR, FORWARD);
      rotateMotor(FRONT_LEFT_MOTOR, BACKWARD);
      rotateMotor(BACK_LEFT_MOTOR, BACKWARD);  
      break;
  
    case TURN_RIGHT:
      rotateMotor(FRONT_RIGHT_MOTOR, BACKWARD);
      rotateMotor(BACK_RIGHT_MOTOR, BACKWARD);
      rotateMotor(FRONT_LEFT_MOTOR, FORWARD);
      rotateMotor(BACK_LEFT_MOTOR, FORWARD);   
      break;
  
    case STOP:
      rotateMotor(FRONT_RIGHT_MOTOR, STOP);
      rotateMotor(BACK_RIGHT_MOTOR, STOP);
      rotateMotor(FRONT_LEFT_MOTOR, STOP);
      rotateMotor(BACK_LEFT_MOTOR, STOP);    
      break;
  
    default:
      rotateMotor(FRONT_RIGHT_MOTOR, STOP);
      rotateMotor(BACK_RIGHT_MOTOR, STOP);
      rotateMotor(FRONT_LEFT_MOTOR, STOP);
      rotateMotor(BACK_LEFT_MOTOR, STOP);    
      break;
  }
}

void handleRoot(AsyncWebServerRequest *request) 
{
  request->send_P(200, "text/html", htmlHomePage);
}

void handleNotFound(AsyncWebServerRequest *request) 
{
    request->send(404, "text/plain", "File Not Found");
}


void onWebSocketEvent(AsyncWebSocket *server, 
                      AsyncWebSocketClient *client, 
                      AwsEventType type,
                      void *arg, 
                      uint8_t *data, 
                      size_t len) 
{                      
  switch (type) 
  {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      //client->text(getRelayPinsStatusJson(ALL_RELAY_PINS_INDEX));
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      processCarMovement("0");
      break;
    case WS_EVT_DATA:
      AwsFrameInfo *info;
      info = (AwsFrameInfo*)arg;
      if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) 
      {
        std::string myData = "";
        myData.assign((char *)data, len);
        processCarMovement(myData.c_str());       
      }
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
    default:
      break;  
  }
}

void setUpPinModes()
{
  for (int i = 0; i < motorPins.size(); i++)
  {
    pinMode(motorPins[i].pinIN1, OUTPUT);
    pinMode(motorPins[i].pinIN2, OUTPUT);  
    rotateMotor(i, STOP);  
  }
}


void setup(void) 
{
  setUpPinModes();
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", HTTP_GET, handleRoot);
  server.onNotFound(handleNotFound);
  
  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop() 
{
  ws.cleanupClients(); 
}
