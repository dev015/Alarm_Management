<!-- ABOUT THE PROJECT -->
## Alarm Management System

Implementation to play different alarm audio sequences: High, Medium and Low. 

The audio sequences are as follow:
* High: Five beeps every 500ms with duration of 250ms each, then wait for 2s with no beep. Repeat Continuously.
* MEDIUM: One beep every second, with a beep duration of 250ms. Repeat continuously
* LOW: One beep every 30s, with a beep duration of 1s. Repeat continuously

There are different rules regarding the alarm management:
* Only one alarm sequence played at a time.
* Only the highest priority alarm is played at a time. 
* Alarms can be started and stopped.

The application output:
* The output displays characters simulating the buzzer state.
* One character represents 250ms.
* 'X' represents beep, and '_' represents no beep.

Unit Testing:
* Google Test is used for unit testing.

<!-- GETTING STARTED -->
## Getting Started

### Structure of the directory
```
${Alarm_Management}
|-- build/
|-- CMakeLists.txt
|-- lib/
|   `-- googletest 
|-- src/
|   |-- CMakeLists.txt
|   |-- alarm.cpp
|   |-- alarm.h
|   |-- alarm_manager.cpp
|   |-- alarm_manager.h
|   |-- custom_alarm.h
|   |-- execute_alarm_keypress.h
|   |-- key_action.cpp
|   |-- key_action.h
|   |-- utility.h
|   `-- main.cpp
`-- tst/
    |-- CMakeLists.txt
    `-- main.cpp
```

### Requirements

* Linux/MacOS
* **CMake >= 3.12**: https://cmake.org/download/

### To Compile on Linux

1. Clone the repo
   ```sh
   git clone https://github.com/dev015/Alarm_Management.git
   ```
2. Open a shell terminal inside the cloned repository and launch:


   ```sh
   ./build.sh
   ```
3. You now have two executable files.

   * Run the Project:

   ```sh
   ./AlarmSystem_run
   ```

   * Run the Project Test:

   ```sh
   ./AlarmSystem_test
   ```








