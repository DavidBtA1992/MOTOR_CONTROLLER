#include "Motor_pins.h"
#include "Motor.h"

//! INSTANCES
Motor motor_derecho(1,300, 10, 10);
Motor motor_izquierdo(2,300, 10, 10);

void setup()
{

    //! PIN MODES
    pinMode(MOTOR1_START_PIN, INPUT);
    pinMode(MOTOR1_STOP_PIN, INPUT);
    pinMode(MOTOR2_START_PIN, INPUT);
    pinMode(MOTOR2_STOP_PIN, INPUT);
    pinMode(MOTOR1_PWM_PIN, OUTPUT);
    pinMode(MOTOR2_PWM_PIN, OUTPUT);
    pinMode(MOTOR1_FAULT, OUTPUT);

    //! INITS
    motor_derecho._init();
    motor_izquierdo._init();
}

void loop()
{
    motor_derecho.motor_selection();
    motor_derecho.start_motor();
}
