#include "alarm.h"

// Function to generate alarm pattern. Generates pattern according to certain parameters. e.g. x_x_x_x_x_
void AlarmPattern::generateBeep()
{
    double time = 0;
    bool is_beeping = true;
    int counter = 0;
    this->running = true;
    while (true)
    {
        if (!running)
        {
            return;
        }
        if (counter >= this->number && this->number != 0)
            return;
        if (!paused)
        {
            preciseSleep(TIME_UNIT);
            if (is_beeping)
            {
                std::cout << BEEP << std::flush;
                time += TIME_UNIT;
                counter++;
                if (time >= this->beepTime)
                {
                    is_beeping = false;
                }
            }
            else
            {
                std::cout << NO_BEEP << std::flush;
                time += TIME_UNIT;
                if (time >= this->period)
                {
                    time = 0;
                    is_beeping = true;
                }
            }
        }
    }
}

// Function to stop alarm for certain amount of time after generating a particular pattern.
// e.g. X_X_X_X_X_______X_X_X_X_X_______X_X_X_X_X
void InterleavedAlarm::generateBeep()
{
    double time = 0;
    bool is_beeping = true;
    this->running = true;
    int counter = 0;
    while (true)
    {
        if (!running)
        {
            break;
        }
        if (counter >= this->number_repeat && this->number_repeat != 0)
            return;
        if (!paused)
        {
            if (is_beeping)
            {
                AlarmPattern::generateBeep();
                counter++;
                is_beeping = false;
            }
            else
            {
                preciseSleep(Alarm::TIME_UNIT);
                std::cout << Alarm::NO_BEEP << std::flush;
                time += TIME_UNIT;
                if (time >= this->wait)
                {
                    time = 0;
                    is_beeping = true;
                }
            }
        }
    }
}