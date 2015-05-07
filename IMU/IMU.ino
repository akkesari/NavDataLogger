// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include "Wire.h"

#include "I2Cdev.h"
#include "ITG3200.h"
#include "HMC5883L.h"
#include "ADXL345.h"

ITG3200 gyro;
HMC5883L mag;
ADXL345 accel;

int16_t gx, gy, gz;
int16_t mx, my, mz;
int16_t ax, ay, az;

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();

    // initialize serial communication
    // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
    // it's really up to you depending on your project)
    Serial.begin(38400);

    // initialize device
    Serial.println("Initializing I2C devices...");
    gyro.initialize();
    mag.initialize(); 
    accel.initialize();   
    
    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(gyro.testConnection() ? "ITG3200 connection successful" : "ITG3200 connection failed");
    Serial.println(mag.testConnection() ? "HMC5883L connection successful" : "HMC5883L connection failed");
    Serial.println(accel.testConnection() ? "ADXL345 connection successful" : "ADXL345 connection failed");
}

void loop() {
    // read raw measurements from devices
    gyro.getRotation(&gx, &gy, &gz);
    mag.getHeading(&mx, &my, &mz);
    accel.getAcceleration(&ax, &ay, &az);

    // display tab-separated x/y/z values for gyro, mag and accel
      Serial.print("gyro:\t");
      Serial.print(gx); Serial.print("\t");
      Serial.print(gy); Serial.print("\t");
      Serial.print(gz); Serial.print("\t");
      Serial.print("mag:\t");
      Serial.print(mx); Serial.print("\t");
      Serial.print(my); Serial.print("\t");
      Serial.print(mz); Serial.print("\t");
      Serial.print("accel:\t");
      Serial.print(ax); Serial.print("\t");
      Serial.print(ay); Serial.print("\t");
      Serial.print(az); Serial.print("\n");
}
