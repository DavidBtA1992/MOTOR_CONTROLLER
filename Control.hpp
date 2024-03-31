#ifndef Control_h
#define Control_h
#include "Arduino.h"

class Control
{
private:
    bool _startstate;
    bool _stopstate;
    int _motor;
    int _analoginput;

public:
    Control();
    void _init();
    void motor_selection();
    void start_button_pressed();
    void stop_button_pressed();
    int read_analog_input();
    bool startstate();
    bool stopstate();
    int analoginputstate();
    int motorselected();
};

#endif