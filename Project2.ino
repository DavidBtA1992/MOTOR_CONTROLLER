#include "Motor_pins.hpp"
#include "Motor.hpp"
#include "Control.hpp"

//! INSTANCES

Control control;
Motor motor_derecho(1, 0, 10, 10);
Motor motor_izquierdo(2, 0, 10, 10);

void setup()
{

    //! PIN MODES
    pinMode(MOTOR_START_PIN, INPUT);
    pinMode(MOTOR_STOP_PIN, INPUT);
    pinMode(MOTOR_SELECTION, INPUT);
    pinMode(MOTOR1_PWM_PIN, OUTPUT);
    pinMode(MOTOR2_PWM_PIN, OUTPUT);
    pinMode(MOTOR1_FAULT, OUTPUT);
    pinMode(MOTOR2_FAULT, OUTPUT);

    //! INITS
    control._init();
    motor_derecho._init();
    motor_izquierdo._init();
}

void loop()
{
    control.motor_selection();
    control.start_button_pressed();
    control.stop_button_pressed();
    control.read_analog_input();

    if (control.motorselected() == motor_derecho.motor_selected())
    {
        if (control.startstate())
        {
            motor_derecho.speed_set(control.analoginputstate());
            motor_derecho.start_motor();
        }
    }
    
    if (control.motorselected() == motor_izquierdo.motor_selected())
    {
        if (control.startstate())
        {
            motor_izquierdo.speed_set(control.analoginputstate());
            motor_izquierdo.start_motor();
        }
    }
}
