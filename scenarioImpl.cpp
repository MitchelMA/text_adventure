#include "scenarioProt.h"
#include <string>
#include <sstream>
#include <iostream>
#include <map>

Scenario::Scenario(std::string text)
{
    this->text = text;
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
void Scenario::testSetup(Scenario *through, int size)
{
    this->test = through;
    std::cout << this->test << " Testje" << std::endl;
    this->optsSize = size;
}
void Scenario::testIt(void)
{
    std::cout << this->test << std::endl;
}