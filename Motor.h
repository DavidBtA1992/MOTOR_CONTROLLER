#ifndef Motor_h
#define Motor_h
#include "Arduino.h"

class Motor
{
private:
    bool _started;
    bool _stopped;
    bool _faulted;
    bool _atspeed;

    // *User Inputs
    int _motor;
    int _speed;
    int _accel_ramp;
    int _decel_ramp;

public:
    Motor(int motor, int speed, int accel_ramp, int decel_ramp);
    bool started();
    bool stopped();
    bool faulted();
    bool at_speed(); 
    void _init();
    void start_motor();
    void stop_motor();
    void motor_selection();
    int speed_set(int x);
    int accel_ramp_set(int x);
    int decel_ramp_set(int x);
    int motor_speed();
};

#endif