#include "Control.hpp"
#include "Motor_pins.hpp"
#include <Arduino.h>

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
    return;
}

void Control::start_button_pressed()
{
    if (digitalRead(MOTOR_START_PIN) == true && digitalRead(MOTOR_STOP_PIN) == false)
    {
        Control::_startstate = true;
        Control::_stopstate = false;
    }
    return;
}

void Control::stop_button_pressed()
{
    if (digitalRead(MOTOR_STOP_PIN) == true)
    {
        Control::_stopstate = true;
        Control::_startstate = false;
    }
}

int Control::read_analog_input()
{
    _analoginput = analogRead(MOTOR_SPEED);
    return _analoginput;
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