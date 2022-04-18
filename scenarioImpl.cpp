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
    this->sceneTexts = (std::string *)malloc(sizeof(std::string) * this->optionsSize);
    this->sceneOptions = (Scenario **)malloc(sizeof(Scenario) * this->optionsSize);
    for (int i = 0; i < this->optionsSize; i++)
    {
        this->sceneOptions[i] = (Scenario *)malloc(sizeof(Scenario));
    }
}

std::string Scenario::getOptions(void)
{
    std::ostringstream os;
    for (int i = 0; i < optionsSize; i++)
    {
        os << "> " << this->sceneTexts[i] << "\n";
    }
    return os.str();
}

void Scenario::setup(Scenario **through, std::string *optionsTexts)
{
    // this->sceneOptions = through;
    // this->sceneTexts = optionsTexts;
    for (int i = 0; i < this->optionsSize; i++)
    {
        this->sceneOptions[i] = through[i];
        this->sceneTexts[i] = optionsTexts[i];
    }
}
void Scenario::testIt(void)
{
    for (int i = 0; i < this->optionsSize; i++)
    {
        std::cout << this->sceneOptions[i] << std::endl;
    }
    std::cout << "Eind" << std::endl;
}