#pragma once
#include "../Prototypes.hpp"
// questionpool
extern std::vector<Scenario *> questionPool;

void quizStart(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num);
void quizEnd(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num);
void quizHandle(Scenario *quiz, std::pair<const std::string, Scenario *> pair, int num);
/**
 * @brief Deletes all the scenario's in the pool and then clears it
 */
void clearQuestionPool(void);