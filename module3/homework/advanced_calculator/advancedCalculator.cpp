#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <map>
#include <regex>

const std::map<std::string, std::function<double(double, double)>> operationsMap{
    {"+", std::plus<double>()},
    {"-", std::minus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"%", std::modulus<int>()},
    {"!", [](double number, double zero) { return (number <= 0 ? 1.0 : tgamma(number + 1.0)); }},
    {"^", [](double base, double exponent) { return pow(base, exponent); }},
    {"$", [](double num, double root) { return pow(num, 1.0 / root); }}};

bool checkCharacters(std::string input) {
    std::string allowedSigns{" ,.!+/%$-+*^"};

    return std::any_of(input.begin(), input.end(), [&allowedSigns](char letter) {
        return std::find(allowedSigns.begin(), allowedSigns.end(), letter) == allowedSigns.end() && !isdigit(letter);
    });
};

bool isInteger(double number) {
    double integer = 0;
    double rest = std::modf(number, &integer);
    return integer == number;
};

ErrorCode process(std::string input, double* out) {
    if (checkCharacters(input)) {
        return ErrorCode::BadCharacter;
    }

    std::smatch regexMatch;

    std::regex expressionRegex("([-]?\\s?\\d+\\.?\\d*)\\s?([-+*\\/^$%])?\\s?([-]?\\d+\\.?\\d*)?$");
    std::regex factorialRegex("([-]?\\s?\\d+\\.?\\d*)\\s?([!])?");

    if (std::regex_search(input, regexMatch, expressionRegex)) {
        if (regexMatch[0] != input) {
            return ErrorCode::BadFormat;
        };
        double firstNumber = std::stod(regexMatch[1]);
        double secondNumber = std::stod(regexMatch[3]);
        std::string operationType = regexMatch[2];
        if (operationType == "$" && firstNumber < 0) {
            return ErrorCode::SqrtOfNegativeNumber;
        } else if (operationType == "/" && secondNumber == 0) {
            return ErrorCode::DivideBy0;
        } else if (operationType == "%" && (!isInteger(firstNumber) || !isInteger(secondNumber))) {
            return ErrorCode::ModuleOfNonIntegerValue;
        } else {
            *out = operationsMap.at(operationType)(firstNumber, secondNumber);
            return ErrorCode::OK;
        }
    } else if (std::regex_search(input, regexMatch, factorialRegex)) {
        if (regexMatch[0] != input) {
            return ErrorCode::BadFormat;
        };
        double number = std::stod(regexMatch[1]);
        std::string operationType = regexMatch[2];
        double zeroValue = 0;
        *out = operationsMap.at(operationType)(number, zeroValue);
        return ErrorCode::OK;
    }
    return ErrorCode::BadFormat;
}
