#include "Control.hpp"
#include "Motor_pins.hpp"
#include <Arduino.h>

//! GLOBALS

bool switch_change;
bool switch_past_state = 0;

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
    switch_change = digitalRead(MOTOR_SELECTION);
    if (switch_past_state != switch_change)
    {
        Control::_startstate = false;
        Control::_stopstate = false;
        switch_past_state = switch_change;
    }
    
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