#include "MotorDriver.h"

int main() {
    MotorDriver motor(100000000, 65535);

    for (int targetFreq = 1; targetFreq <= 2000; targetFreq++) {
        Result result = motor.findPrescalerAndArr(targetFreq);
        if (result.prescaler != 0 && result.arr != 0) {
            std::cout << "Hedef Frekans: " << targetFreq
                      << " Hz -> Prescaler: " << result.prescaler
                      << ", ARR: " << result.arr
                      << ", Cikti Frekansi: " << result.outputFrequency << " Hz\n";
        } else {
            std::cout << "Hedef Frekans: " << targetFreq << " Hz icin uygun cozum bulunamadi.\n";
        }
    }

    return 0;
}
