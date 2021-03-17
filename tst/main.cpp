#include "alarm.h"
#include "gtest/gtest.h"

//Test for checking medium priority alarm
TEST (AlarmTest, AlarmRunMediumTest) { 
    testing::internal::CaptureStdout();
    AlarmPattern pattern{0.25, 1, 'm', 5,1};
    pattern.generateBeep();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "X___X___X___X___X");
}


//Test for checking high priority alarm
TEST (AlarmTest, AlarmRunHighTest) { 
    testing::internal::CaptureStdout();
    InterleavedAlarm alarm{0.25, 0.5, 'h', 5, 2, 2, 2};
    alarm.generateBeep();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "X_X_X_X_X________X_X_X_X_X");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}