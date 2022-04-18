#pragma once
#ifndef PROTOTYPES
#define PROTOTYPES

#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <map>

#pragma region Scenario

struct Scenario
{
    // Display text of the scenario
    std::string text = "Lorum Ipsum Dolor Sit Amet.";
    // Options of the scenario
    std::map<std::string, Scenario *> options;

    // last input string
    std::string lastInput;

    // get and neccesities
    std::map<Scenario *, std::string> gets;
    std::map<Scenario *, std::string> needs;
    std::map<Scenario *, void (*)(Scenario *, std::pair<const std::string, Scenario *>, int)> handlers;

    // Scenario constructor
    Scenario(std::string text);

    // Scenario constructor
    Scenario(std::string text, std::map<std::string, Scenario *> options);

    // Get the options as a string
    std::string getOptions(void);

    // Setup of the options
    void setup(std::map<std::string, Scenario *> options, std::map<Scenario *, void (*)(Scenario *, std::pair<const std::string, Scenario *>, int)> handlers);
    void testIt(void);

    // setup for get
    void setGet(std::map<Scenario *, std::string> setget);

    // setup for need
    void setNeed(std::map<Scenario *, std::string> setneed);

    // init scenario
    void initScene(void);

    void handleInput();
};

#pragma endregion

#pragma region vectorHandling

void addToVector(std::vector<std::string> &vec, std::vector<std::string> add);
bool vectorContains(std::vector<std::string> &vec, std::string);

#pragma endregion

#pragma region input

void clearInputBuffer(void);
int charToNum(char ch);
void normInput(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num);

#pragma endregion

#endif