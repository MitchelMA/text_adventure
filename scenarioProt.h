#pragma once
#include <string>
#include <map>

struct Scenario
{

public:
    std::string text = "Lorum Ipsum Dolor Sit Amet.";
    Scenario **sceneOptions = nullptr;
    std::string *sceneTexts = nullptr;
    int optionsSize;

    Scenario(std::string text, int optionsSize);
    ~Scenario();

    std::string getOptions(void);

    void setup(Scenario **sceneOptions, std::string *sceneTexts);
};