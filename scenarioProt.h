#pragma once
#include <string>
#include <map>

struct Scenario
{

public:
    std::string text = "Lorum Ipsum Dolor Sit Amet.";
    // Scenario **sceneOptions;
    // std::string *sceneTexts;
    std::map<std::string, Scenario *> options;
    // int optionsSize;

    Scenario(std::string text);
    // ~Scenario();

    std::string getOptions(void);

    void setup(std::map<std::string, Scenario *> options);
    void testIt(void);
};