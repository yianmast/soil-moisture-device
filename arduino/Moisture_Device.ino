#include <U8g2lib.h>
#include <Wire.h>
//U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
const int moisturePin = A2;

void setup() {
u8g2.begin();
Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(moisturePin);
  moistureValue = constrain(moistureValue, 180,460);
  moistureValue = map(moistureValue,180,460,100,0);
  Serial.print("Moisture: ");
  Serial.println(moistureValue);

  u8g2.clearBuffer();
  //do{
    u8g2.setFont(u8g_font_9x18);
    u8g2.setCursor(0,10);
    //u8g2.drawStr(0, 20,"Moisture: ");
    u8g2.setCursor(0, 20);
    u8g2.print("Moisture: ");
    u8g2.print(moistureValue);
    //u8g2.print(moistureValue);
    u8g2.print(" %");

    //u8g.setPrintPos(0,40);

    if(moistureValue<30){
      u8g2.setFont(u8g_font_6x12);
      u8g2.drawStr(0,40, "Too Dry!");
    //   u8g2.setPrintPos(0,40);
    // u8g2.print("Too Dry!");
    u8g2.drawStr(0, 50, "Water me,");
    // u8g2.setPrintPos(0,50);
    // u8g2.print("Water me,");
    u8g2.drawStr(0,60,"or I'll die!");
    // u8g2.setPrintPos(0,60);
    // u8g2.print("or I'll die!");    
    draw_X_Smiley();
    }

    else if (moistureValue >= 30 && moistureValue <= 60) {
      u8g2.setFont(u8g_font_6x12);
      u8g2.drawStr(0,40,"Optimal Level!");
      // u8g2.setPrintPos(0,40);
      // u8g2.print("Optimal Level!");
      u8g2.drawStr(0,50,"Thank you,");
      //u8g2.setPrintPos(0,50,"Thank you,");
      //u8g2.print("Thank you,");
      u8g2.drawStr(0, 60,"Plant Parent" );
      // u8g2.setPrintPos(0,60);
      // u8g2.print("Plant Parent");
      draw_HappySmille();

  } else {
    u8g2.setFont(u8g_font_6x12);
    u8g2.drawStr(0,40,"Too Wet!");
      u8g2.setCursor(0,40);
      u8g2.print("Too Wet!");
      u8g2.setCursor(0,50);
      u8g2.print("Let me dry,");
      u8g2.setCursor(0,60);
      u8g2.print("or I'll die");
      draw_ScaredSmille();

  }
  //} while (u8g2.nextPage());
  u8g2.sendBuffer();
  delay(200);  // Delay for 1 second before reading moisture again
  
}

void draw_X_Smiley() {
  u8g2.setColorIndex(1);  // Set color index to 1 (on)

  // Draw the face circle
  u8g2.drawCircle(96,48,15);
  

  u8g2.drawLine(89,40,93,47);
  u8g2.drawLine(89,47,93,40);

  u8g2.drawLine(89+12,40,93+12,47);
  u8g2.drawLine(89+12,47,93+12,40);

  u8g2.drawLine(89+6,40+12,93+6,47+12);
  u8g2.drawLine(89+6,47+12,93+6,40+12);
}


void draw_HappySmille(){
  u8g2.setColorIndex(1);  // Set color index to 1 (on)

  // Draw the face circle
  u8g2.drawCircle(96,48,15);
  u8g2.drawEllipse(90, 44, 5,2);
  u8g2.drawEllipse(90+12, 44, 5,2);
  // Draw the mouth
  int cx = 96;  // X-coordinate of the center of the arc
  int cy = 55;  // Y-coordinate of the center of the arc
  int radius = 5;  // Radius of the arc
  int startAngle = 20;  // Starting angle of the arc
  int endAngle = 160;  // Ending angle of the arc
  int numSegments = 20;  // Number of line segments to approximate the arc

  float angleStep = (endAngle - startAngle) / float(numSegments - 1);
  for (int i = 0; i < numSegments; i++) {
    float angle = startAngle + i * angleStep;
    float x1 = cx + radius * cos(angle * PI / 180.0);
    float y1 = cy + radius * sin(angle * PI / 180.0);
    float x2 = cx + radius * cos((angle + angleStep) * PI / 180.0);
    float y2 = cy + radius * sin((angle + angleStep) * PI / 180.0);
    u8g2.drawLine(x1, y1, x2, y2);

  };

}

void draw_ScaredSmille(){
  u8g2.setColorIndex(1);  // Set color index to 1 (on)

  // Draw the face circle
  u8g2.drawCircle(96,48,15);
  u8g2.drawDisc(90, 44, 3);
  u8g2.drawDisc(90+12, 44, 3);
  u8g2.drawEllipse(96, 55, 3,7);
  
  

}