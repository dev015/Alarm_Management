#pragma once

//Low priority alarm
class Low: public AlarmPattern {
public:
    Low():AlarmPattern{1, 30,'l', 0, 0} {}
};

//Medium priority alarm
class Medium: public AlarmPattern {
public:
    Medium():AlarmPattern{0.25, 1, 'm', 0,1} {}
};

//High priority alarm
class High: public InterleavedAlarm {
public:
    High():InterleavedAlarm{0.25, 0.5, 'h', 5, 2, 2} {}
};

//Returns alarm object according to the character pressed
class AlarmFactory {
public:
    static Alarm* createAlarm(char c) {
        Alarm *alarm = NULL;
        switch (c)
        {
            case 'h':
            alarm = new High();
            break;
            case 'm':
            alarm = new Medium();
            break;
            case 'l':
            alarm = new Low();
            break;
        }
        return alarm;
    }
};