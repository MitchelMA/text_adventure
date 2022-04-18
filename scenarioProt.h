#pragma once
#include <string>
#include <map>

struct Scenario
{

public:
    std::string text = "Lorum Ipsum Dolor Sit Amet.";
    std::map<std::string, Scenario> options;
    Scenario *test;
    int optsSize;

    Scenario(std::string text);

    void setOptions(std::map<std::string, Scenario> options);

    std::string getOptions(void);

    void testSetup(Scenario *through, int size);

    void testIt(void);
};