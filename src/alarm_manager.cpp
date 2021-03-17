#include "alarm_manager.h"

// Class to compare different Alarms according to the priority.
class AlarmManager::CompareAlarm
{
public:
    bool operator()(Alarm *a1, Alarm *a2)
    {
        return (a1->getPriority()) > (a2->getPriority());
    }
};

// Compare alarms according to priority.
bool AlarmManager::compare(Alarm *a1, Alarm *a2)
{
    return (a1->getPriority()) > (a2->getPriority());
}

// Deletes alarm associated with a character(key press) if it already exists in the queue.
bool AlarmManager::deleteIfAlreadyExists(char ch)
{
    Alarm *alarm = NULL;
    bool removed = false;
    for (Alarm *a : queue)
    {
        if (a->getChar() == ch)
        {
            alarm = a;
            break;
        }
    }
    if (alarm != NULL)
    {
        alarm->stop();
        removed = true;
    }
    queue.erase(std::remove(queue.begin(), queue.end(), alarm), queue.end());
    resumeLastLowerPriority();
    return removed;
}

// Checks if the alarm already exists in the queue.
bool AlarmManager::checkIfAlreadyExists(char ch)
{
    return std::end(queue) != std::find_if(queue.begin(), queue.end(), [ch](Alarm *a) { return a->getChar() == ch; });
}

// Resumes last lower priority alarm from the queue.
void AlarmManager::resumeLastLowerPriority()
{

    auto it = std::max_element(queue.begin(), queue.end(), [](Alarm *a, Alarm *b) { return a->getPriority() < b->getPriority(); });

    if (it != queue.end())
    {
        Alarm *alarm = *it;
        if (alarm->isRunning())
            alarm->resume();
        else
            alarm->start();
    }
}

// Pauses lower all lower priority alarms than the number specified.
void AlarmManager::pauseLowerPriority(int priority)
{
    for (Alarm *a : queue)
    {
        if (a->getPriority() < priority)
        {
            a->pause();
        }
    }
}

// Checks if alarm is of high priority.
bool AlarmManager::isHighPriority(Alarm *alarm)
{
    return std::end(queue) == std::find_if(queue.begin(), queue.end(), [alarm](Alarm *a) { return a->getPriority() > alarm->getPriority(); });
}

// Function to create alarm and push it to the queue.
void AlarmManager::createAlarm(char c)
{
    Alarm *alarm = AlarmFactory::createAlarm(c);
    if (alarm != NULL)
    {
        if (isHighPriority(alarm))
        {
            pauseLowerPriority(alarm->getPriority());
            alarm->start();
        }
        queue.push_back(alarm);
    }
}

// This function is executed on different thread. Detects if key is pressed and plays particular alarm.
void AlarmManager::playAlarm()
{
    while (true)
    {
        if (ExecuteAlarmKeypress::key_pressed)
        {
            ExecuteAlarmKeypress::key_pressed = false;
            if (!checkIfAlreadyExists(ExecuteAlarmKeypress::input_char))
            {
                createAlarm(ExecuteAlarmKeypress::input_char);
            }
            else
            {
                deleteIfAlreadyExists(ExecuteAlarmKeypress::input_char);
            }
        }
    }
}