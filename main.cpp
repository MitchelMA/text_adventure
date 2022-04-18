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

    std::cout << scen_01->getOptions();
    std::cout << scen_02->getOptions();
    scen_02->text = "Veranderd!";
    std::cout << scen_01->sceneOptions[0]->text << std::endl;

    delete scen_01;
    delete scen_02;
    return 0;
}

void storySetup()
{
    scen_01 = new Scenario("Dit is de Text", 1);
    scen_02 = new Scenario("Dit is scenario 2", 1);

    Scenario *sc_one[1] = {scen_02};
    std::string sct_one[1] = {"Ja"};
    scen_01->setup(sc_one, sct_one);

    Scenario *sc_two[1] = {scen_01};
    std::string sct_two[1] = {"LOL"};
    scen_02->setup(sc_two, sct_two);
}