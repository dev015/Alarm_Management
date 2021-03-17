/*
This file contains code for generating alarm pattern.
*/
#ifndef ALARM_H
#define ALARM_H

#include<iostream>
#include "utility.h"

//Base class for all the alarms. We can create any type of alarm by extending this class.
class Alarm {
private:
    char ch;
    int priority;
protected:
    std::thread *th{NULL};
    double beepTime; 
    double period;
    int number;
    bool running;
    bool paused;
public:
    const double TIME_UNIT = 0.25;
    const char BEEP = 'X';
    const char NO_BEEP = '_';

    Alarm(double beepTime, double period, char ch, int number = 0, int priority = 0) : beepTime{beepTime}, period{period}, number{number}, priority{priority}, running{false}, paused{false}, ch{ch} {}

    virtual ~Alarm() {
        this->stop();
        if(th != NULL) {
            if(th->joinable())
                th->join();
            delete th;
        }
    }

    char getChar() {
        return ch;
    }

    bool isRunning() {
        return running;
    }

    //Starts printing the output using a different thread
    virtual void start() {
        th = new std::thread(&Alarm::generateBeep, this);
    }

    //function to generate alarm pattern
    virtual void generateBeep() = 0;

    void stop() {
        this->running = false;
    }

    void resume() {
        this->paused = false;
    }

    void pause() {
        this->paused = true;
    }

    int getPriority() {
        return priority;
    }
};

//This class contains code to print alarm. Generates output according to different parameters set.
class AlarmPattern: public Alarm {
public:

    AlarmPattern(double beepTime, double period, char ch, int number = 0, int priority = 0) : Alarm{beepTime,period,ch,number,priority} {}

    //Starts printing the output using a different thread
    void start() override {
        th = new std::thread(&AlarmPattern::generateBeep, this);
    }

    void generateBeep() override;
};

//This class contains code to stop alarm for certain amount of time after generating a particular pattern.
class InterleavedAlarm: public AlarmPattern {
private:
    double wait;
    int number_repeat;
public:
    InterleavedAlarm(double beepTime, double period, char ch, int number, int priority, double wait, int number_repeat = 0):AlarmPattern{beepTime, period, ch, number, priority}, wait{wait}, number_repeat{number_repeat} {}

    //Starts printing the output using a different thread
    void start() override {
        th = new std::thread(&InterleavedAlarm::generateBeep, this);
    }

    void generateBeep() override;
};

#endif