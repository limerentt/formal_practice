#include "gtest/gtest.h"
#include "../src/Max_substring.h"

TEST(Check_dot, BaseCase0) {
    testing::internal::CaptureStdout();
    Max_substring::find_substring("aa.a.a.", 'a');
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("4", output);
}

TEST(Check_asterisk, BaseCase1) {
    testing::internal::CaptureStdout();
    Max_substring::find_substring("a*", 'a');
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("INF", output);
}

TEST(Check_plus, BaseCase2) {
    testing::internal::CaptureStdout();
    Max_substring::find_substring("ab+", 'a');
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("1", output);
}

TEST(Check_wrong_regex, BaseCase3) {
    testing::internal::CaptureStdout();
    Max_substring::find_substring("a..", 'a');
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("ERROR", output);
}

TEST(Check_epsilon, BaseCase4) {
    testing::internal::CaptureStdout();
    Max_substring::find_substring("a1+1a+.", 'a');
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("2", output);
}

TEST(Check_asterisk, BaseCase5) {
    testing::internal::CaptureStdout();
    Max_substring::find_substring("b*a.", 'a');
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("1", output);
}

TEST(Check_asterisk, BaseCase6) {
    testing::internal::CaptureStdout();
    Max_substring::find_substring("ab.", 'a');
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("1", output);
}

TEST(Check_wrong_regex, BaseCase7) {
    testing::internal::CaptureStdout();
    Max_substring::find_substring("aa", 'a');
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("ERROR", output);
}
