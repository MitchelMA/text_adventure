#include "quiz.hpp"

// the questionspool
std::vector<Scenario *> questionPool;

void quizStart(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num)
{
    // quiz questions
    Scenario *q_01 = new Scenario("Vraag 1", false);
    Scenario *q_02 = new Scenario("Vraag 2", false);

    questionPool.push_back(q_01);
    questionPool.push_back(q_02);

    q_01->parent = scene;
    q_02->parent = scene;

    q_01->setup({{"Antwoord 1", scene}, {"Antwoord 2", q_02}}, {quizEnd, quizHandle});
    q_02->setup({{"Antwoord 1", pair.second}}, {quizEnd});
    q_01->initScene();
}

void quizEnd(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num)
{
    clearQuestionPool();
    if (pair.second == scene->parent)
        std::cout << "Dat was het verkeerde antwoord" << std::endl;
    else
        std::cout << "Dat was het goede antwoord\nJe hebt de quiz behaald!" << std::endl;

    if (pair.second == nullptr)
        return;
    std::cin.get();
    pair.second->initScene();
}

void quizHandle(Scenario *quiz, std::pair<const std::string, Scenario *> pair, int num)
{
    if (pair.second == nullptr)
        return;

    std::cout << "Dat was het goede antwoord" << std::endl;
    clearInputBuffer();

    pair.second->initScene();
    return;
}

void clearQuestionPool(void)
{
    for (auto i : questionPool)
    {
        delete i;
    }
    questionPool.clear();
}