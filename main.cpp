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

    std::cout << scen_01->text << std::endl;
    std::cout << scen_01->getOptions() << std::endl
              << std::endl;

    // std::cout << scen_01->options.begin()->second.text << std::endl;
    // scen_02->text = "testen";
    // std::cout << scen_01->options.begin()->second.text << std::endl;

    scen_02->testIt();
    scen_02->testIt();
    scen_02->testIt();

    scen_02->text = "kanus";
    std::cout << scen_02->test[0]->text << std::endl;

    // std::cout << scen_02->text << std::endl;
    // std::cout << scen_02->getOptions() << std::endl;

    // free(scen_01);
    // free(scen_02);
    return 0;
}

void storySetup()
{
    scen_01 = new Scenario("Dit is de Text", 1);
    scen_02 = new Scenario("Dit is scenario 2", 2);

    scen_01->setOptions({{"Lol", *scen_02}});
    scen_02->setOptions({{"Lol man", *scen_01}});

    Scenario *sc[2] = {scen_01, scen_02};
    scen_02->testSetup(sc);
}