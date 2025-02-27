#include "MotorDriver.h"

MotorDriver::MotorDriver(int systemFrequency, int maxARR) {
    _systemFrequency = systemFrequency;
    _maxARR = maxARR;
}

Result MotorDriver::findPrescalerAndArr(int targetFrequency) {
    Result result = {0, 0, 0};
    for (int prescaler = 1; prescaler <= _maxARR; prescaler++) {
        int rawARR = _systemFrequency / (prescaler * targetFrequency);
        int arr = rawARR;

        if (arr <= _maxARR && arr > 1) {
            result.prescaler = prescaler;
            result.arr = arr;
            result.outputFrequency = _systemFrequency / (prescaler * arr);
            return result;
        }
    }
    return result;
}
