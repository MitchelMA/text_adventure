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
    this->test = (Scenario **)malloc(sizeof(Scenario) * this->optionsSize);
    for (int i = 0; i < this->optionsSize; i++)
    {
        this->test[i] = (Scenario *)malloc(sizeof(Scenario));
    }
}

std::string Scenario::getOptions(void)
{
    std::ostringstream os;
    auto iter = this->options.begin();
    for (; iter != this->options.end(); ++iter)
    {
        os << ">  " << iter->first << ": " << &(iter->second) << "\n";
    }
    return os.str();
}

void Scenario::setOptions(std::map<std::string, Scenario> options)
{
    this->options = options;
}
void Scenario::testSetup(Scenario **through)
{
    for (int i = 0; i < this->optionsSize; i++)
    {
        this->test[i] = through[i];
        std::cout << "TestSet: " << through[i] << std::endl;
    }
    std::cout << this->test[1] << " Testje" << std::endl;
}
void Scenario::testIt(void)
{
    std::cout << "It: " << this->test[1] << std::endl;
}