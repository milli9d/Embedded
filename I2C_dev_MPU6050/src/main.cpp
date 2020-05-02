#include <mbed.h>
#include <MPU6050.h>
#include <Serial.h>


int main()
{
  // put your setup code here, to run once:
  // Make new MPU Object
  MPU6050 *mpu = new MPU6050();
  Serial *debug = new Serial(USBTX, USBRX);

  while (1)
  {
    // Test connection to MPU , if found then inititalize MPU
    if (mpu->testConnection())
    {
      mpu->initialize();
      break;
    }
    // Wait 100ms before trying reconnection
    wait_ms(100);
  }

  while (1)
  {
// Long Double type because range is large enough for values
    long double temp_c, accel_x, accel_y, accel_z;
    // Set Accelerometer Range
    mpu->setFullScaleAccelRange(MPU6050_ACCEL_FS_2);
    // Come out of sleep mode and wait for devices to start
    mpu->setSleepEnabled(false);
    wait_ms(100);
    // Get Temperature
    int16_t temp = mpu->getTemperature();
    // Get Acceleration , read pointers to use this function , you need to enter pointers to buffers in getAcceleration as parameters
    int16_t acc_x, acc_y, acc_z;
    mpu->getAcceleration(&acc_x, &acc_y, &acc_z);
    // Calculate result from 2's Complement form
    accel_x = acc_x / 16384.0f;
    accel_y = acc_y / 16384.0f;
    accel_z = acc_z / 16384.0f;
    temp_c = (temp / 340.0f) + 36.53f;
    // Print to Serial Monitor
    debug->printf("Temp = %f c\n", temp_c);
    debug->printf("|X:%f | Y:%f | Z:%f |\n", accel_x, accel_y, accel_z);
    // mpu->setSleepEnabled(true);
    // Wait to delay readings. 
    wait_ms(200);
  }
}
