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
        std::cout << '\b';
        system("stty cooked");
        this->executeAction(c);

        if (c == this->exit_char)
        {
            system("stty cooked");
            exit(0);
        }
    }
}