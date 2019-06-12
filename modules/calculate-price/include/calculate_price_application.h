// Copyright 2019 Astafeva Irina

#ifndef MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_APPLICATION_H_
#define MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_APPLICATION_H_

#include <string>
#include <vector>

class CalculatePriceApplication {
 public:
    CalculatePriceApplication() = default;
    std::string operator()(int argc, const char ** argv);
 private:
    void Help(const char *appname);
    bool ValidateNambersOfArguments(int argc, const char ** argv);
    bool IsArgumentsInteger(const char ** argv);
    std::string message_;
    std::vector <int> books;
};

#endif  // MODULES_CALCULATE_PRICE_INCLUDE_CALCULATE_PRICE_APPLICATION_H_
