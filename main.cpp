#include <iostream>
#include <map>
#include <string>

#include "scenarioProt.h"
#include "story.h"

void storySetup();

int main()
{
    storySetup();

    std::cout << "Scene 1: " << scen_01 << std::endl;
    std::cout << "Scene 2: " << scen_02 << std::endl
              << std::endl;

    std::cout << scen_01->options.begin()->second->text << std::endl;
    scen_02->text = "Veranderd!";
    std::cout << scen_01->options.begin()->second->text << std::endl;

    delete scen_01;
    delete scen_02;
    return 0;
}

void storySetup()
{
    // initializing the prototypes
    scen_01 = new Scenario("Dit is de Text");
    scen_02 = new Scenario("Dit is scenario 2");

    // setup of the options of the scenarios
    scen_01->setup({{"lol", scen_02}});
    scen_02->setup({{"ja man", scen_01}});
}