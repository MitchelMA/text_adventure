#include <iostream>
#include <map>
#include <string>

#include "scenarioProt.h"
#include "story.h"

void storySetup();

int main()
{
    while (true)
    {
        storySetup();

        std::cout << "Scene 1: " << scen_01 << std::endl;
        std::cout << "Scene 2: " << scen_02 << std::endl
                  << std::endl;

        std::cout << scen_01->getOptions();
        scen_01->testIt();
        std::cout << scen_02->getOptions();
        scen_02->testIt();

        delete scen_01;
        delete scen_02;
    }

    std::cout << "Test" << std::endl;
    return 0;
}

void storySetup()
{
    scen_01 = new Scenario("Dit is de Text");
    scen_02 = new Scenario("Dit is scenario 2");

    scen_01->setup({{"lol", scen_02}});
    scen_02->setup({{"ja man", scen_01}});
}