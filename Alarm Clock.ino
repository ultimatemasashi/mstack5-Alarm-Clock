#include <M5Stack.h>
#define NOTE_D0 -1
#define NOTE_D1 294
#define NOTE_D2 330
#define NOTE_D3 350
#define NOTE_D4 393
#define NOTE_D5 441
#define NOTE_D6 495
#define NOTE_D7 556

#define NOTE_DL1 147
#define NOTE_DL2 165
#define NOTE_DL3 175
#define NOTE_DL4 196
#define NOTE_DL5 221
#define NOTE_DL6 248
#define NOTE_DL7 278

#define NOTE_DH1 589
#define NOTE_DH2 661
#define NOTE_DH3 700
#define NOTE_DH4 786
#define NOTE_DH5 882
#define NOTE_DH6 990
#define NOTE_DH7 112

#include <M5Stack.h>
#include <WiFi.h>
#define TFT_GREY 0x5AEB
#include <stdio.h>
#include <string>
const char *ssid = "*****";
const char *password = "*****";
uint8_t hh;
uint8_t mm;
uint8_t ss;
byte omm = 60;
byte oss = 60;
byte xcolon;
byte xsecs;
struct tm timeInfo;
#define NOTE_D0 -1
#define NOTE_D1 294
#define NOTE_D2 330
#define NOTE_D3 350
#define NOTE_D4 393
#define NOTE_D5 441
#define NOTE_D6 495
#define NOTE_D7 556

#define NOTE_DL1 147
#define NOTE_DL2 165
#define NOTE_DL3 175
#define NOTE_DL4 196
#define NOTE_DL5 221
#define NOTE_DL6 248
#define NOTE_DL7 278

#define NOTE_DH1 589
#define NOTE_DH2 661
#define NOTE_DH3 700
#define NOTE_DH4 786
#define NOTE_DH5 882
#define NOTE_DH6 990
#define NOTE_DH7 112

int a = 0;
int b = 0;
unsigned int guiBtnA_Cnt;
unsigned int guiBtnB_Cnt;
unsigned int guiBtnC_Cnt;
void setup(void) {
  
  M5.begin();
  M5.Power.begin();
  M5.Lcd.printf("M5Stack Speaker test:\r\n");
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
  M5.Lcd.setBrightness(7);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  guiBtnA_Cnt = 7;
  guiBtnB_Cnt = 0;
  guiBtnC_Cnt = 0;
 
  M5.Lcd.setCursor(10,10);
  M5.Lcd.printf("hour  : %d",guiBtnA_Cnt);
  
  M5.Lcd.setCursor(10,20);
  M5.Lcd.printf("minute : %d",guiBtnB_Cnt);
  
  M5.Lcd.setCursor(10,30);
  M5.Lcd.printf("second : %d",guiBtnC_Cnt); 

  
  if(WiFi.begin(ssid, password) != WL_DISCONNECTED) {
    ESP.restart();
  }
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  configTime(9*3600L,0,"ntp.nict.jp","time.google.com","ntp.jst.mfeed.ad.jp");
}

void loop() {
  
  getLocalTime(&timeInfo);
  hh = timeInfo.tm_hour;
  mm = timeInfo.tm_min;
  ss = timeInfo.tm_sec;
  if (oss != ss) {
    int xpos = 0;
    int ypos = 85;
    int ysecs = ypos + 24;
    if (omm != mm) {
      omm = mm;
      if (hh < 10) xpos += M5.Lcd.drawChar('0', xpos, ypos, 8);
      xpos += M5.Lcd.drawNumber(hh, xpos, ypos, 8);
      xcolon = xpos;
      xpos += M5.Lcd.drawChar(':', xpos, ypos - 8, 8);
      if (mm < 10) xpos += M5.Lcd.drawChar('0', xpos, ypos, 8);
      xpos += M5.Lcd.drawNumber(mm, xpos, ypos, 8);
      xsecs = xpos;
    }
    if (oss != ss) {
      oss = ss;
      xpos = xsecs;
      M5.Lcd.drawChar(':', xcolon, ypos - 8, 8);
      xpos += M5.Lcd.drawChar(':', xsecs, ysecs, 6);
      if (ss < 10) xpos += M5.Lcd.drawChar('0', xpos, ysecs, 6);
      M5.Lcd.drawNumber(ss, xpos, ysecs, 6);


   if (ss == guiBtnC_Cnt && mm == guiBtnB_Cnt && hh == guiBtnA_Cnt) {
  
    
     M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100);
     M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100);
 M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100);
     M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100);
 M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100);
     M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100);
 M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100);
     M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100);
 M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100);
     M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100); M5.Speaker.tone(NOTE_DH5, 200);
    delay(100);
     M5.Speaker.tone(NOTE_DH3, 200);
     delay(100);
    M5.Speaker.beep(); //beep
     delay(100000);


     }
   M5.update();
  if (M5.BtnA.wasPressed()) {
      
      guiBtnA_Cnt++;
      
      M5.Lcd.setCursor(10,10);
      M5.Lcd.printf("hour  : %d",guiBtnA_Cnt);
    }
   
    if (M5.BtnB.wasPressed()) {
   
      guiBtnB_Cnt++;
      
      M5.Lcd.setCursor(10,20);
      M5.Lcd.printf("minute : %d",guiBtnB_Cnt);
    }
   
    if (M5.BtnC.wasPressed()) {
      
      guiBtnC_Cnt++;
      
      M5.Lcd.setCursor(10,30);
      M5.Lcd.printf("second : %d",guiBtnC_Cnt);
    }
  
    
    }
  }
}
