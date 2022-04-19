#include "quiz.hpp"

void quizStart(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num)
{
    // quiz questions
    Scenario *q_01 = new Scenario("Vraag 1", false);
    Scenario *q_02 = new Scenario("Vraag 2", false);

    q_01->setup({{"Antwoord 1", scene}, {"Antwoord 2", q_02}}, {{0, normInput}, {1, quizHandle}});
    q_02->setup({{"Antwoord 1", nullptr}}, {{0, quizHandle}});
    q_01->initScene();

    delete q_01;
    delete q_02;

    std::cout << "Je hebt de quiz gehaald!!" << std::endl;
    std::cin.get();
    pair.second->initScene();
}

void quizHandle(Scenario *quiz, std::pair<const std::string, Scenario *> pair, int num)
{
    if (pair.second == nullptr)
        return;

    pair.second->initScene();
}