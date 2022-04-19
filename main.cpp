#include <iostream>
#include "prototypes.hpp"

Scenario *scen_01;
Scenario *scen_02;
Scenario *scen_03;
Scenario *scen_04;

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
    // initializing the prototypes
    scen_01 = new Scenario("Dit is de Text");
    scen_02 = new Scenario("Dit is scenario 2");
    scen_03 = new Scenario("Dit is Scenario 3");
    scen_04 = new Scenario("Dit is Scenario 4");

    // setup of the options of the scenarios
    scen_01->setup({{"lol", scen_02}, {"lol ja man", scen_03}}, {{0, normInput}, {1, testInput}});
    scen_02->setup({{"Kanus man", scen_03}, {"Nee man", scen_01}}, {{0, normInput}, {1, normInput}});
    scen_03->setup({{"naar 4", scen_04}, {"terug naar 1", scen_01}}, {{0, normInput}, {1, normInput}});
    scen_04->setup({{"Terug naar 1", scen_01}, {"Test Handler:", nullptr}}, {{0, normInput}, {1, testInput}});

    // needs and gets
    scen_01->setGet({{0, "Paspoort"}});
    scen_02->setNeed({{0, "Paspoort"}});
    scen_02->setGet({{1, "Geld"}});

    scen_01->info();
    std::cout << std::endl;
    scen_02->info();
    std::cout << std::endl;
    scen_03->info();
    std::cout << std::endl;
    scen_04->info();
    std::cout << std::endl;

    std::cin.get();
}
