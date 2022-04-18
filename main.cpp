#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "prototypes.hpp"

Scenario *scen_01;
Scenario *scen_02;
Scenario *scen_03;

void storySetup();

int main()
{

    storySetup();
    scen_01->initScene();

    delete scen_01;
    delete scen_02;
    delete scen_03;

    // delete playerInventory;
    return 0;
}

void storySetup()
{
    // playerInventory = new std::vector<std::string>();
    // initializing the prototypes
    scen_01 = new Scenario("Dit is de Text");
    scen_02 = new Scenario("Dit is scenario 2");
    scen_03 = new Scenario("Dit is Scenario 3");

    // setup of the options of the scenarios
    scen_01->setup({{"lol", scen_02}, {"lol ja man", scen_03}}, {{scen_02, normInput}, {scen_03, normInput}});
    scen_02->setup({{"Kanus man", scen_03}, {"Nee man", scen_01}}, {{scen_03, normInput}, {scen_01, normInput}});
    scen_03->setup({{"Terug", scen_01}}, {{scen_01, normInput}});

    // needs and gets
    scen_01->setGet({{scen_02, "Paspoort"}});
    scen_02->setNeed({{scen_03, "Paspoort"}});
}