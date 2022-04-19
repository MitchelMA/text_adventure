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
    // std::map<std::string, Scenario *> options;
    std::vector<std::pair<std::string, Scenario *>> options;

    // last input string
    std::string lastInput;

    // get and neccesities
    std::map<int, std::string> gets;
    std::map<int, std::string> needs;
    std::map<int, void (*)(Scenario *, std::pair<const std::string, Scenario *>, int)> handlers;

    // Scenario constructor
    Scenario(std::string text);

    // Scenario constructor
    Scenario(std::string text, std::vector<std::pair<std::string, Scenario *>> options);

    // Get the options as a string
    std::string getOptions(void);

    // Setup of the options
    void setup(std::vector<std::pair<std::string, Scenario *>> options, std::map<int, void (*)(Scenario *, std::pair<const std::string, Scenario *>, int)> handlers);
    void testIt(void);

    // setup for get
    void setGet(std::map<int, std::string> setget);

    // setup for need
    void setNeed(std::map<int, std::string> setneed);

    // init scenario
    void initScene(void);

    void handleInput();
};

#pragma endregion

#pragma region vectorHandling

template <typename T, typename A>
void addToVector(std::vector<T, A> &vec, std::vector<T, A> add);

template <typename T, typename A>
void vectorInverse(std::vector<T, A> &vec);

template <typename T, typename A>
bool vectorContains(std::vector<T, A> &vec, T cont);

#pragma endregion

#pragma region input

void clearInputBuffer(void);
int charToNum(char ch);
void normInput(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num);
void testInput(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num);

#pragma endregion

#endif