#include "scenarioProt.h"
#include <string>
#include <sstream>
#include <cstdio>
#include <iostream>
#include <map>

Scenario::Scenario(std::string text, int optionsSize)
{
    this->text = text;
    this->optionsSize = optionsSize;
    this->sceneOptions = (Scenario **)malloc(sizeof(Scenario) * this->optionsSize);
    this->sceneTexts = (std::string *)malloc(sizeof(std::string) * this->optionsSize);
    for (int i = 0; i < this->optionsSize; i++)
    {
        this->sceneOptions[i] = (Scenario *)malloc(sizeof(Scenario));
    }
}

Scenario::~Scenario()
{
    for (int i = 0; i < optionsSize; i++)
    {
        free(sceneTexts);
    }
    free(sceneOptions);
    free(this);
}

std::string Scenario::getOptions(void)
{
    std::ostringstream os;
    for (int i = 0; i < optionsSize; i++)
    {
        os << "> " << sceneTexts[i] << ": " << sceneOptions[i] << "\n";
    }
    return os.str();
}

void Scenario::setup(Scenario **through, std::string *optionsTexts)
{
    for (int i = 0; i < this->optionsSize; i++)
    {
        this->sceneOptions[i] = through[i];
        this->sceneTexts[i] = optionsTexts[i];
    }
}