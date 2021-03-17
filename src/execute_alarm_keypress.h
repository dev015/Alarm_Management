#pragma once

#include "key_action.h"

//Subclass of KeyAction. Specifies a function which contains code to do an action once a key is pressed.
class ExecuteAlarmKeypress: public keyAction {
private:

    //checks if character pressed si valid or not.
    bool isValidChar(char ch) {
        if(ch == 'l' || ch == 'L' || ch == 'm' || ch =='M' || ch=='h' || ch == 'H')
            return true;
        return false;
}

public:
    inline static char input_char{'\0'};//represents the character which was pressed.

    inline static bool key_pressed{false}; //variable used to detect there is a keypress or not.

    //executed when a key is pressed.
    void executeAction(char c) override {
        if(this->isValidChar(c)) {
            input_char = c;
            key_pressed = true;
        }
    }
};