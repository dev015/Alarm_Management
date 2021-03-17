#include<iostream>
#include <thread>
#include "execute_alarm_keypress.h"
#include "alarm_manager.h"

int main() {
    std::cout << "Check cmake \n" << std::endl;
    std::cout << "Alarm Management System: High, Medium and Low \n" << std::endl;
    std::cout << "High Priority Alarm: Press 'H' to activate/deactivate the alarm" << std::endl;
    std::cout << "Medium Priority Alarm: Press 'M' to activate/deactivate the alarm" << std::endl;
    std::cout << "Low Priority Alarm: Press 'L' to activate/deactivate the alarm \n" << std::endl;
    std::cout << "Press 'Q' to quit the application" << std::endl;
    std::cout << "Waiting for user input:\n" << std::endl;
    keyAction *key = new ExecuteAlarmKeypress();
    AlarmManager manager;
    std::thread key_detect_thread(std::ref(*key)); //runs key detection logic on one thread.
    std::thread alarm_manage_thread(std::ref(manager)); // runs application logic on other thread.
    key_detect_thread.join();
    alarm_manage_thread.join();
}