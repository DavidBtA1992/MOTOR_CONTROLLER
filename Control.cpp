#include "Control.hpp"
#include "Motor_pins.hpp"
#include <Arduino.h>

//! GLOBALS

int start_pin = 0;
int stop_pin = 0;
int analog_pin = 0;

Control::Control()
{
}

//! METHODS

void Control::_init()
{
    _motor = 0;
}

void Control::motor_selection()
{
    if (digitalRead(MOTOR_SELECTION) == 0)
    {
        _motor = 1;
    }
    else
    {
        _motor = 2;
    }

    switch (_motor)
    {
    case 1:
        start_pin = MOTOR1_START_PIN;
        stop_pin = MOTOR1_STOP_PIN;
        analog_pin = MOTOR1_SPEED;
        break;
    case 2:
        start_pin = MOTOR2_START_PIN;
        stop_pin = MOTOR2_STOP_PIN;
        analog_pin = MOTOR2_SPEED;
        break;
    default:
        break;
    }
    return;
}

void Control::start_button_pressed()
{
    motor_selection();
    if (digitalRead(start_pin) == true && digitalRead(stop_pin) == false)
    {
        Control::_startstate = true;
        Control::_stopstate = false;
    }
}

void Control::stop_button_pressed()
{
    motor_selection();
    if (digitalRead(stop_pin) == true)
    {
        Control::_stopstate = true;
        Control::_startstate = false;
    }
}

int Control::read_analog_input()
{
    motor_selection();
    return analogRead(analog_pin);
}

// Getters

bool Control::startstate()
{
    return _startstate;
}

bool Control::stopstate()
{
    return _stopstate;
}

int Control::analoginputstate()
{
    return _analoginput;
}

int Control::motorselected()
{
    return _motor;
}