#include <iostream>
#include <Windows.h>
#include "prototypes.hpp"
#include "story/story.hpp"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    storySetup();
    scen_01->initScene();

    return 0;
}