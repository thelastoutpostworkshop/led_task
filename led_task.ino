//Youtube tutorial : https://youtu.be/382p1NT1Wcs
#include <Arduino.h>

#define LED_1_PIN 5
#define LED_2_PIN 16
#define LED_3_PIN 3

void setup() {
    xTaskCreatePinnedToCore(
        led1_sketch,     // Task function
        "taskName",      // Task name
        8192,                  // Stack size
        NULL,                  // Task input parameters
        1,                     // Task priority, be carefull when changing this
        NULL,                  // Task handle, add one if you want control over the task (resume or suspend the task) 
        0                      // Core to run the task on
    );
    xTaskCreatePinnedToCore(
        led2_sketch,     // Task function
        "taskName",      // Task name
        8192,                  // Stack size
        NULL,                  // Task input parameters
        1,                     // Task priority, be carefull when changing this
        NULL,                  // Task handle, add one if you want control over the task (resume or suspend the task) 
        1                      // Core to run the task on
    );
    xTaskCreatePinnedToCore(
        led3_sketch,     // Task function
        "taskName",      // Task name
        8192,                  // Stack size
        NULL,                  // Task input parameters
        1,                     // Task priority, be carefull when changing this
        NULL,                  // Task handle, add one if you want control over the task (resume or suspend the task) 
        1                      // Core to run the task on
    );
}

void led1_sketch(void *parameter) {
    // Setup start here
    pinMode(LED_1_PIN, OUTPUT);
    
    // End of your setup
    
    // Loop function, run repeatedly
    for (;;) {
        int led = digitalRead(LED_1_PIN);
        digitalWrite(LED_1_PIN, !led);
        delay(1000); // Allow other tasks to run, adjust as needed
    }
}
void led2_sketch(void *parameter) {
    // Setup start here
    pinMode(LED_2_PIN, OUTPUT);
    
    // End of your setup
    
    // Loop function, run repeatedly
    for (;;) {
        int led = digitalRead(LED_2_PIN);
        digitalWrite(LED_2_PIN, !led);
        delay(350); // Allow other tasks to run, adjust as needed
    }
}
void led3_sketch(void *parameter) {
    // Setup start here
    pinMode(LED_3_PIN, OUTPUT);
    
    // End of your setup
    
    // Loop function, run repeatedly
    for (;;) {
        int led = digitalRead(LED_3_PIN);
        digitalWrite(LED_3_PIN, !led);
        delay(50); // Allow other tasks to run, adjust as needed
    }
}

void loop() {
}
