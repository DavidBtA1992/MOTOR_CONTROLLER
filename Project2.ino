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
    pinMode(MOTOR_STARTED, OUTPUT);
    pinMode(MOTOR_FAULTED, OUTPUT);

    //! INITS
    control._init();
    motor_derecho._init();
    motor_izquierdo._init();
}

//! FUNCTIONS

void motor_controller(Control selected_control, Motor selected_motor)
{
    if (selected_control.motorselected() == selected_motor.motor_selected())
    {
        if (selected_control.startstate())
        {
            selected_motor.speed_set(selected_control.analoginputstate());
            selected_motor.start_motor();

        }
        if (selected_control.stopstate())
        {
            selected_motor.stop_motor();
        }
        
    }

    if (selected_motor.faulted())
    {
        digitalWrite(MOTOR_FAULTED, HIGH);
    }

    if (selected_motor.started())
    {
        digitalWrite(MOTOR_STARTED, HIGH);
    }

    if (selected_motor.stopped())
    {
        digitalWrite(MOTOR_STARTED, LOW);
    }
    
    
    
}


void loop()
{
    control.motor_selection();
    control.start_button_pressed();
    control.stop_button_pressed();
    control.read_analog_input();

    motor_controller(control,motor_derecho);
    motor_controller(control,motor_izquierdo);
}
