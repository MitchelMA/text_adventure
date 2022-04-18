#pragma once
#include <string>
#include <map>

struct Scenario
{
    // Display text of the scenario
    std::string text = "Lorum Ipsum Dolor Sit Amet.";
    // Options of the scenario
    std::map<std::string, Scenario *> options;

    // Scenario constructor
    Scenario(std::string text);
    // Scenario constructor
    Scenario(std::string text, std::map<std::string, Scenario *> options);

    // Get the options as a string
    std::string getOptions(void);

    // Setup of the options
    void setup(std::map<std::string, Scenario *> options);
    void testIt(void);
};