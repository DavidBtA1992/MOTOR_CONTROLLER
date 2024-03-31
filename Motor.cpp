#include "Motor.hpp"
#include "Motor_pins.hpp"
#include <Arduino.h>

//! GLOBALS

int speed_pin = 0;
int speed_fb_pin = 0;
bool faulted = 0;

Motor::Motor(int motor, int speed, int accel_ramp, int decel_ramp)
    : _motor(motor), _speed(speed), _accel_ramp(accel_ramp), _decel_ramp(decel_ramp)
{
}

// !METHODS
// Init
void Motor::_init()
{
    _started = false;
    _stopped = false;
    _faulted = false;
    _atspeed = false;
}
// Start Motor

void Motor::start_motor()
{
Motor:
    motor_selection();

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

            if (analogRead(speed_fb_pin) == _speed)
            {
                _started = true;
                return;
            }
            failure_time++;

        } while (failure_time <= 10);
        _started = false;
        _faulted = true;
    }
    return;
}

// Stop Motor

void Motor::stop_motor()

{
Motor:
    motor_selection();

    if (_stopped != true)
    {
        int j = 0;
        int failure_time = 0;

        analogWrite(speed_pin, 0);

        do
        {
            do
            {
                j++;
            } while (j <= _decel_ramp);

            if (analogRead(speed_fb_pin) == 0)
            {
                _stopped = true;
                return;
            }
            failure_time++;

        } while (failure_time <= 10);
        _stopped = false;
        _faulted = true;
    }
    return;
}

// Motor selection

void Motor::motor_selection()
{
    switch (_motor)
    {
    case 1:
        speed_pin = MOTOR1_PWM_PIN;
        speed_fb_pin = MOTOR1_FB_PIN;
        break;
    case 2:
        speed_pin = MOTOR2_PWM_PIN;
        speed_fb_pin = MOTOR2_FB_PIN;
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
    return (analogRead(speed_fb_pin));
}
int Motor::motor_selected()
{
    return (_motor);
}