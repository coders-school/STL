#include <algorithm>
#include <cmath>
#include <vector>

#include "advancedCalculator.hpp"
#include "gtest/gtest.h"

bool cmp(double first, double second, double epsilon = 0.5) {
    return (fabs(first - second) < epsilon);
}

TEST(advancedCalculatorTest, ShouldAdd) {
    double result = 0;

    ASSERT_EQ(process("5+ 11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 16));
    ASSERT_EQ(process("43.21+11.54", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 54.75));
    ASSERT_EQ(process("-54.31 + 11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -43.31));
    ASSERT_EQ(process("28.43 +-810.43", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -782));
    ASSERT_EQ(process("-11.230 + -77.321", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -88.551));
}

TEST(advancedCalculatorTest, ShouldSubstract) {
    double result = 0;

    ASSERT_EQ(process("5- 11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -6));
    ASSERT_EQ(process("43.21 -11.54", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 31.67));
    ASSERT_EQ(process("-54.31-11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -65.31));
    ASSERT_EQ(process("28.43 - -810.43", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 838.86));
    ASSERT_EQ(process("-11.230 --77.321", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 66.091));
}

TEST(advancedCalculatorTest, ShouldMultiply) {
    double result = 0;

    ASSERT_EQ(process("5 * 11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 55));
    ASSERT_EQ(process("43.21 *11.54", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 498.643));
    ASSERT_EQ(process("-54.31* 11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -597.41));
    ASSERT_EQ(process("28.43 *-810.43", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -23040.5));
    ASSERT_EQ(process("-11.230*-77.321", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 868.315));
}

TEST(advancedCalculatorTest, ShouldDivide) {
    double result = 0;

    ASSERT_EQ(process("5 /11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 0.454545));
    ASSERT_EQ(process("43.21/ 11.54", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 3.74437));
    ASSERT_EQ(process("-54.31/11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -4.93727));
    ASSERT_EQ(process("28.43 /-810.43", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -0.0350801));
    ASSERT_EQ(process("-11.230/-77.321", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 0.145239));
}

TEST(advancedCalculatorTest, ShouldPower) {
    double result = 0;

    ASSERT_EQ(process("5 ^2", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 25));
    ASSERT_EQ(process("4.5^ 3", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 91.125));
    ASSERT_EQ(process("-5 ^3", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -125));
    ASSERT_EQ(process("24.5^-2", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 0.00166597));
    ASSERT_EQ(process("-2 ^ -10", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 0.000976562));
}

TEST(advancedCalculatorTest, ShouldCalculateSqrt) {
    double result = 0;

    ASSERT_EQ(process("225 $3", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 8.77915e-08));
    ASSERT_EQ(process("1024$ 2", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 9.53674e-07));
    ASSERT_EQ(process("1024$4", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 9.09495e-13));
    ASSERT_EQ(process("13.71 $-4", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 35330.5));
    ASSERT_EQ(process("2.5 $ 2.5", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 0.101193));
}

TEST(advancedCalculatorTest, ShouldModulo) {
    double result = 0;

    ASSERT_EQ(process("225 %1000", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 225.0));
    ASSERT_EQ(process("7% 3", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 1.0));
    ASSERT_EQ(process("1024%7", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 2.0));
    ASSERT_EQ(process("1378 % 91", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 13.0));
    ASSERT_EQ(process("-2091% 67", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -14.0));
    ASSERT_EQ(process("-2091 %-67", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -14.0));
    ASSERT_EQ(process("2091%-67", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 14.0));
}

TEST(advancedCalculatorTest, ShouldFactorial) {
    double result = 0;

    ASSERT_EQ(process("5!", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 120));
    ASSERT_EQ(process("6.7!", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 3048.33));
    ASSERT_EQ(process("3.435!", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 12.0027));
    ASSERT_EQ(process("-13!", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 1));
    ASSERT_EQ(process("-12.4!", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 1));
}

TEST(advancedCalculatorTest, ShouldReturnBadFormat) {
    double result = 0;

    ASSERT_EQ(process("5,1!", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("11,3 + 12.4", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("13.4 ++ 12.43", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("13.2 + 12.3 + 13.0", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("-12.4! + 2", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("11 / 13.4+", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("+8 - 32.1", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("12 ^% 3", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("+ 3 4", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("12.4.3 + 12.3", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("-98 + 12.3 =", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("123 -#- 4", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("qwert + 123", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("123,4 ; 345", &result), ErrorCode::BadFormat);
    ASSERT_EQ(process("123.4 ! 345", &result), ErrorCode::BadFormat);
}

TEST(advancedCalculatorTest, ShouldReturnBadCharacter) {
    double result = 0;

    ASSERT_EQ(process("123 #- 123", &result), ErrorCode::BadCharacter);
    ASSERT_EQ(process("123 @- 123", &result), ErrorCode::BadCharacter);
    ASSERT_EQ(process("123 &- 123", &result), ErrorCode::BadCharacter);
    ASSERT_EQ(process("123 ? 123", &result), ErrorCode::BadCharacter);
    ASSERT_EQ(process("123 \\ 123", &result), ErrorCode::BadCharacter);
    ASSERT_EQ(process("-123 [ -123", &result), ErrorCode::BadCharacter);
    ASSERT_EQ(process("-123 ] 123", &result), ErrorCode::BadCharacter);
}

TEST(advancedCalculatorTest, ShouldReturnDivideBy0) {
    double result = 0;

    ASSERT_EQ(process("123 / 0", &result), ErrorCode::DivideBy0);
    ASSERT_EQ(process("123 / 0.0", &result), ErrorCode::DivideBy0);
    ASSERT_EQ(process("123 / -0", &result), ErrorCode::DivideBy0);
    ASSERT_EQ(process("123 / -0.0", &result), ErrorCode::DivideBy0);
    ASSERT_EQ(process("-123 / -0.0", &result), ErrorCode::DivideBy0);
    ASSERT_EQ(process("0.0 / 0", &result), ErrorCode::DivideBy0);
}

TEST(advancedCalculatorTest, ShouldReturnModuleOfNonIntegerValue) {
    double result = 0;

    ASSERT_EQ(process("123 % 0.1", &result), ErrorCode::ModuleOfNonIntegerValue);
    ASSERT_EQ(process("123 % 0.0005", &result), ErrorCode::ModuleOfNonIntegerValue);
    ASSERT_EQ(process("123.1 % 0", &result), ErrorCode::ModuleOfNonIntegerValue);
    ASSERT_EQ(process("123.1 % 0.1", &result), ErrorCode::ModuleOfNonIntegerValue);
}

TEST(advancedCalculatorTest, ShouldReturnSqrtOfNagativeNumber) {
    double result = 0;

    ASSERT_EQ(process("-123 $ -1", &result), ErrorCode::SqrtOfNagativeNumber);
    ASSERT_EQ(process("-123.4 $ -1", &result), ErrorCode::SqrtOfNagativeNumber);
    ASSERT_EQ(process("-123.2 $ 1", &result), ErrorCode::SqrtOfNagativeNumber);
    ASSERT_EQ(process("-123 $ 1", &result), ErrorCode::SqrtOfNagativeNumber);
}

TEST(advancedCalculatorTest, ShouldEraseAllSpaces) {

    ASSERT_EQ(eraseSpaces("-123 $ -1"), "-123$-1");
    ASSERT_EQ(eraseSpaces("+8 - 32.  1"), "+8-32.1");
}

TEST(advancedCalculatorTest, ShouldReturnBadCharacterOrOK) {
    ASSERT_EQ(allowedCharacters("123 #- 123"), ErrorCode::BadCharacter);
    ASSERT_EQ(allowedCharacters("123 @- 123"), ErrorCode::BadCharacter);
    ASSERT_EQ(allowedCharacters("123 &- 123"), ErrorCode::BadCharacter);
    ASSERT_EQ(allowedCharacters("123 ? 123"), ErrorCode::BadCharacter);
    ASSERT_EQ(allowedCharacters("123 \\ 123"), ErrorCode::BadCharacter);
    ASSERT_EQ(allowedCharacters("-123 [ -123"), ErrorCode::BadCharacter);
    ASSERT_EQ(allowedCharacters("-123 ] 123"), ErrorCode::BadCharacter);
    ASSERT_EQ(allowedCharacters("5+11"), ErrorCode::OK);
    ASSERT_EQ(allowedCharacters("43.21+11.54"), ErrorCode::OK);
    ASSERT_EQ(allowedCharacters("-54.31+11"), ErrorCode::OK);
}

TEST(advancedCalculatorTest, ShouldReturnBadFormatOrOK) {
    ASSERT_EQ(allowedFormat("123+--123"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("--123+123"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("*123"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("123*"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("123.*-123.10"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("-123/-123."), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("-123+*-123"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("1.2.3+123"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("123+1.2.3"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("-123/123.-"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("-123//123"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("12.3**1.23"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("5!!"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("5"), ErrorCode::BadFormat);
    ASSERT_EQ(allowedFormat("5+11"), ErrorCode::OK);
    ASSERT_EQ(allowedFormat("43.21+11.54"), ErrorCode::OK);
    ASSERT_EQ(allowedFormat("-54.31/-11"), ErrorCode::OK);
    ASSERT_EQ(allowedFormat("-54.1*-11"), ErrorCode::OK);
    ASSERT_EQ(allowedFormat("54.3122+11"), ErrorCode::OK);
    ASSERT_EQ(allowedFormat("-54.31+11"), ErrorCode::OK);
    ASSERT_EQ(allowedFormat("5!"), ErrorCode::OK);
    ASSERT_EQ(allowedFormat("-5!"), ErrorCode::OK);
    ASSERT_EQ(allowedFormat("5.1!"), ErrorCode::OK);
    ASSERT_EQ(allowedFormat("-5.55!"), ErrorCode::OK);
}