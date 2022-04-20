#pragma once

#include <string>
#include <vector>
#include <utility>
#include <map>

// extern of the inventory
extern std::vector<std::string> *myInv;

#pragma region Scenario

/**
 * @brief Structure containing the information about a scenario.
 * Link them together to create a story
 */
struct Scenario
{
    // Display text of the scenario
    std::string text = "Lorum Ipsum Dolor Sit Amet.";
    // Options of the scenario
    std::vector<std::pair<std::string, Scenario *>> options;

    // last input string
    std::string lastInput;

    // boolean value: clear the screen towards this path or not
    bool clear = true;

    // linked parent
    Scenario *parent;

    // gets of the scenario
    std::map<int, std::string> gets;
    // needs of the scenario
    std::map<int, std::string> needs;
    // handlers of the scenario
    std::vector<void (*)(Scenario *, std::pair<const std::string, Scenario *>, int)> handlers;

    /**
     * @brief Construct a new Scenario object
     *
     * @param text
     * The display text of the scenario
     */
    Scenario(std::string text);

    /**
     * @brief Construct a new Scenario object
     *
     * @param text
     * The display text of the scenario
     * @param clear
     * boolean which determines if the command-line should be cleared of proceeding to this scenario
     */
    Scenario(std::string text, bool clear);

    /**
     * @brief Get the options as a string
     *
     * @return A string containing the options of the scenario
     */
    std::string getOptions(void);

    /**
     * @brief Setup for the options
     *
     * @param options
     * A vector consiting of pairs, where the first is a string, and the second a Scenario pointer.
     * The string is the display-text of the option and
     * the Scenario * is a pointer to the scenario that will be initialized by choosing this path
     * @param handlers
     * A vector containg function-pointers, which are respectively orderd with the options
     */
    void setup(std::vector<std::pair<std::string, Scenario *>> options, std::vector<void (*)(Scenario *, std::pair<const std::string, Scenario *>, int)> handlers);

    /**
     * @brief Displays Info about the scenario:
     * address of the scenario;
     * text of scenario;
     * options of the scenario;
     * what you will get from this scenario;
     * what you need for this scenario to be able to proceed to the next scenario;
     * address of the scenario linked with the option
     */
    void info(void);

    /**
     * @brief Sets the gets of the scenario
     * @param setget
     * Map with an integer and a string, where the integer corresponds
     * with the option index, and the string with the item you will get
     */
    void setGet(std::map<int, std::string> setget);

    /**
     * @brief Sets the needs of the scenario
     * @param setneed
     * Map with an integer and a string, where the integer corresponds
     * with the option index, and the string with the item you need
     */
    void setNeed(std::map<int, std::string> setneed);

    /**
     * @brief Initializes the current scene
     * i.e: clears the screen if clear is set to true;
     * displays the text of the scenario;
     * displays the options.
     * At the end, it will listen to the player's input
     */
    void initScene(void);

    /**
     * @brief Handles the input of the player
     * This method will call the corresponding function-pointer given in the setup
     */
    void handleInput();

    /**
     * @brief Removes an option from the scenario
     *
     * @param optionIndex
     * index of the option that will be removed
     */
    void removeOption(unsigned int optionIndex);
};

#pragma endregion

#pragma region vectorHandling

/**
 * @brief Add elements to a vector
 * @tparam T Type of the vector
 * @tparam A Allocater type of the vector
 * @param vec Vector to which you want to add the elements
 * @param add Vector from which the elements will be added
 */
template <typename T, typename A>
void addToVector(std::vector<T, A> &vec, std::vector<T, A> add);

/**
 * @brief Inverts a vector
 *
 * @tparam T Type of the vector
 * @tparam A Allocater type of the vector
 * @param vec The vector you want to invert
 */
template <typename T, typename A>
void vectorInvert(std::vector<T, A> &vec);

/**
 * @brief Checks if an element is present a vector
 *
 * @tparam T Type of the vector
 * @tparam A Allocator type of the vector
 * @param vec The vector you want to check
 * @param cont The element that you want to test the vector on
 * @return true if the element was present in the vector
 * @return false if the element wasn't present in the vector
 */
template <typename T, typename A>
bool vectorContains(const std::vector<T, A> &vec, T cont);

#pragma endregion

#pragma region input
/**
 * @brief Method to clear the inputBuffer
 */
void clearInputBuffer(void);
/**
 * @brief Method to convert char to integer
 * i.e '1' -> 1
 * @param ch char you want to convert
 * @return char converted to int ('1' -> 1)
 */
int charToNum(char ch);

void normInput(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num);
void testInput(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num);
void testRem(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num);

#pragma endregion
