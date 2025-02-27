#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <iostream>

typedef struct {
    int prescaler;
    int arr;
    int outputFrequency;
} Result;

class MotorDriver {
public:
    MotorDriver(int systemFrequency, int maxARR);
    Result findPrescalerAndArr(int targetFrequency);

private:
    int _systemFrequency;
    int _maxARR;
};

#endif // MOTOR_DRIVER_H

