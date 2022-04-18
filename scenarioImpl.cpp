#include "scenarioProt.h"
#include <string>
#include <sstream>
#include <iostream>
#include <map>

Scenario::Scenario(std::string text)
{
    this->text = text;
}
Scenario::Scenario(std::string text, std::map<std::string, Scenario *> options)
{
    this->text = text;
    this->options = options;
}

std::string Scenario::getOptions(void)
{
    std::ostringstream os;
    auto iter = options.begin();
    for (; iter != options.end(); ++iter)
    {
        os << "> " << iter->first << "\n";
    }
    return os.str();
}

void Scenario::setup(std::map<std::string, Scenario *> options)
{
    this->options = options;
}
void Scenario::testIt(void)
{
    for (auto iter = options.begin(); iter != options.end(); ++iter)
    {
        std::cout << iter->second << std::endl;
    }
}