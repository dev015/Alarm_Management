#ifndef ALARM_MANAGER_H
#define ALARM_MANAGER_H

#include <iostream>
#include <thread>
#include <math.h>
#include <vector>
#include <cstdarg>
#include <string>
#include <algorithm>
#include "alarm.h"
#include "custom_alarm.h"
#include "execute_alarm_keypress.h"

//This class contains code for actual logic of the application.
class AlarmManager {
private:

    class CompareAlarm;

    std::vector<Alarm*> queue; //Queue for the alarms

    //Compares two alarms
    bool compare(Alarm *a1, Alarm *a2);

    //Deletes alarm associated a character(key press) if it already exists in the queue.
    bool deleteIfAlreadyExists(char ch);

    //Checks if the alarm already exists in the queue.
    bool checkIfAlreadyExists(char ch);

    //Resumes last lower priority alarm from the queue.
    void resumeLastLowerPriority();

    //Pauses lower all lower priority alarms than the number specified.
    void pauseLowerPriority(int priority);

    //Checks if alarm is of high priority.
    bool isHighPriority(Alarm *alarm);

    //Function to create alarm and push it to the queue.
    void createAlarm(char c);
public:

    //This function is executed on different thread. Detects if key is pressed and plays particular alarm.
    void playAlarm();

    void operator ()() { 
        this->playAlarm();
    } 
};

#endif