#include "Motor.h"
#include "Motor_pins.h"
#include <Arduino.h>

//! GLOBALS

int speed_pin = 0;
int speed_fb = 0;
bool faulted = 0;

Motor::Motor(int motor, int speed, int accel_ramp, int decel_ramp)
    : _motor(motor), _speed(speed), _accel_ramp(accel_ramp), _decel_ramp(decel_ramp)
{
}

// !METHODS
// Init
void Motor::_init()
{
    _started = 0;
    _stopped = 0;
    _faulted = 0;
    _atspeed = 0;
    _accel_ramp = 0;
    _decel_ramp = 0;
}
// Start Motor

void Motor::start_motor()
{
    if (_started != true)
    {
        int j = 0;
        int failure_time = 0;

        analogWrite(speed_pin, _speed);

        do
        {
            do
            {
                j++;
            } while (j <= _accel_ramp);

            if (analogRead(speed_fb) == _speed)
            {
                _started = true;
                return;
            }
            failure_time++;

        } while (failure_time <= 100);
        _started = false;
        _faulted = true;
    }
    return;
}

// Stop Motor

void Motor::stop_motor()
{
    if (_stopped != true)
    {
        analogWrite(speed_pin, 0);
        _started = false;
        _stopped = true;
    }
};

// Motor selection

void Motor::motor_selection()
{
    switch (_motor)
    {
    case 1:
        speed_pin = MOTOR1_PWM_PIN;
        speed_fb = MOTOR1_FB_PIN;
        //MOTOR1_FAULT;
        break;
    case 2:
        speed_pin = MOTOR2_PWM_PIN;
        speed_fb = MOTOR2_FB_PIN;
        //MOTOR2_FAULT;
        break;
    default:
        break;
    }
    return;
}

// Setters and Getters

int Motor::speed_set(int x)
{
    _speed = x;
}
int Motor::accel_ramp_set(int x)
{
    _accel_ramp = x;
}
int Motor::decel_ramp_set(int x)
{
    _accel_ramp = x;
}
bool Motor::started()
{
    return _started;
}
bool Motor::stopped()
{
    return _stopped;
}
bool Motor::faulted()
{
    return _faulted;
}
bool Motor::at_speed()
{
    return _atspeed;
}
int Motor::motor_speed()
{
    return (analogRead(speed_fb));
}