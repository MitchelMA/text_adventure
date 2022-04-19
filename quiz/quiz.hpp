#pragma once
#include "../Prototypes.hpp"
// questionpool
extern std::vector<Scenario *> questionPool;
void quizStart(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num);
void quizEnd(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num);
void quizHandle(Scenario *quiz, std::pair<const std::string, Scenario *> pair, int num);
void clearQuestionPool(void);