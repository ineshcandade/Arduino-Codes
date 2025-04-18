#include <IRremote.h> //this was given by chatgpt

#define IR_RECEIVER_PIN 5  // IR sensor data pin

// Replace these with actual IR command values from your remote
#define CMD_BUTTON_0         7
#define CMD_BUTTON_1         10
#define CMD_BUTTON_2         27
#define CMD_PLAY_PAUSE       1

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVER_PIN);
  Serial.println("IR Receiver Ready");
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned int command = IrReceiver.decodedIRData.command;
    
    // Optional: Print raw info to help you find real command values
    Serial.print("Received Command: ");
    Serial.println(command);

    switch (command) {
      case CMD_BUTTON_0:
        Serial.println("Button 0 was pressed");
        break;
      case CMD_BUTTON_1:
        Serial.println("Button 1 was pressed");
        break;
      case CMD_BUTTON_2:
        Serial.println("Button 2 was pressed");
        break;
      case CMD_PLAY_PAUSE:
        Serial.println("Play/Pause button was pressed");
        break;
      default:
        Serial.println("Unknown button was pressed");
        break;
    }

    IrReceiver.resume(); // Get ready for the next signal
  }
}

/* #include <IRremote.h>

#define IR_RECEIVER_PIN 5

#define IR_BUTTON_PIN_0 7
#define IR_BUTTON_PIN_1 10
#define IR_BUTTON_PIN_2 27
#define IR_BUTTON_PIN_PLAY_PAUSE 1


void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVER_PIN);  

}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();

    int command = IrReceiver.decodedIRData.command;

    if (command = IR_BUTTON_PIN_0) {
      Serial.println("button 0 was pressed");
    }
    else if (command = IR_BUTTON_PIN_1) {
      Serial.println("button 11 was pressed");
    }
    else if (command = IR_BUTTON_PIN_2) {
      Serial.println("button 2 was pressed");
    }
    else if (command = IR_BUTTON_PIN_PLAY_PAUSE) {
      Serial.println("button play/pause was pressed");
    }
    else {
      Serial.println("wrong button was pressed");
    }
    //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); use this to find values
    //Serial.println(IrReceiver.decodedIRData.command);
    //Serial.println("---");
  

  }
  
}...what is wrong with this 
