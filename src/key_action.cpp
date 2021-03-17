#include "key_action.h"

//Function to detect a keypress.
void keyAction::detectKeypress()
{
    char c;
    // Set the terminal to raw model
    while (true)
    {
        system("stty raw");
        c = getchar();
        #if defined(__linux__)
        std::cout << '\b';
        #endif
        system("stty cooked");
        this->executeAction(c);

        if (c == this->exit_char)
        {
            system("stty cooked");
            exit(0);
        }
    }
}