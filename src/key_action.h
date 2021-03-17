#ifndef KEY_ACTION_H
#define KEY_ACTION_H

#include<iostream>

//Base class to detect keypress.
class keyAction
{
private:
    char exit_char; //Represents the exit character. When this character is pressed, application is closed.

public:
    keyAction(char exit_char = 'q') : exit_char{exit_char} {}

    //Contains code to detect a keypress
    void detectKeypress();

    void operator()()
    {
        this->detectKeypress();
    }

    //This function will be executed when a character is pressed.
    virtual void executeAction(char c) = 0;
};

#endif