#include "prototypes.hpp"

// playerInventory
std::vector<std::string> *myInv = new std::vector<std::string>();

// vector checking
#pragma region vectorhandling

// recursive add function
template <typename T, typename A>
void addToVector(std::vector<T, A> &vec, std::vector<T, A> add)
{
    if (add.size() <= 0)
        return;

    bool in = vectorContains(vec, add.front());
    if (!in)
        vec.push_back(add.front());

    // pop the front element of the add vector
    vectorInverse(add);
    add.pop_back();
    vectorInverse(add);

    addToVector(vec, add);
}

template <typename T, typename A>
bool vectorContains(std::vector<T, A> &vec, T cont)
{
    for (auto i : vec)
    {
        if (i == cont)
            return true;
    }
    return false;
}

template <typename T, typename A>
void vectorInverse(std::vector<T, A> &vec)
{
    auto start = vec.begin();
    auto end = vec.end() - 1;
    while (start < end)
    {
        T tmp;
        tmp = *start;
        *start = *end;
        *end = tmp;

        --end;
        ++start;
    }
}

#pragma endregion

// scenario prototypes
#pragma region sceanrios
Scenario::Scenario(std::string text)
{
    this->text = text;
    this->clear = true;
}
Scenario::Scenario(std::string text, bool clear)
{
    this->text = text;
    this->clear = clear;
}
Scenario::Scenario(std::string text, std::vector<std::pair<std::string, Scenario *>> options)
{
    this->text = text;
    this->options = options;
}

std::string Scenario::getOptions(void)
{
    std::ostringstream os;
    auto iter = options.begin();
    for (int i = 1; iter != options.end(); ++iter, ++i)
    {
        os << "   " << i << ". " << iter->first << "\n";
    }
    return os.str();
}

void Scenario::setup(std::vector<std::pair<std::string, Scenario *>> options, std::map<int, void (*)(Scenario *, std::pair<const std::string, Scenario *>, int)> handlers)
{
    this->options = options;
    this->handlers = handlers;
}
void Scenario::info(void)
{
    std::cout << text << std::endl;
    std::cout << "options:" << std::endl;
    auto iter = options.begin();
    for (int i = 0; iter != options.end(); ++iter, ++i)
    {
        std::cout << iter->first << ": {" << (gets[i].empty() ? "..." : gets[i]) << ", " << (needs[i].empty() ? "..." : needs[i]) << "}" << std::endl;
    }
}

void Scenario::initScene(void)
{
    if (clear)
        system("cls");
    std::cout << text << std::endl;
    std::cout << this->getOptions() << std::flush;
    handleInput();
}

void Scenario::handleInput()
{
    std::getline(std::cin, lastInput);
    // regions for commands like "inventory" etc
    if (lastInput == "inventory")
    {
        std::cout << "inventory (" << myInv->size() << "): " << std::endl;
        for (auto i : *myInv)
        {
            std::cout << " " << i << std::endl;
        }
        std::cin.get();
        initScene();
        return;
    }
    else if (lastInput == "exit")
    {
        std::cout << "bedankt voor het spelen!" << std::endl;
        std::cin.get();
        exit(0);
    }
    //-----------------------

    int inpNum = charToNum(lastInput[0]);
    std::string chosen;
    auto iter = options.begin();
    for (int i = 0; iter != options.end(); ++iter, ++i)
    {
        if (i + 1 == inpNum)
        {
            auto handler = handlers.at(i);
            handler(this, *iter, inpNum);
            return;
        }
    }
    // fallback
    initScene();
}

void Scenario::setGet(std::map<int, std::string> setget)
{
    this->gets = setget;
}
void Scenario::setNeed(std::map<int, std::string> setneed)
{
    this->needs = setneed;
}

#pragma endregion

#pragma region input

void clearInputBuffer()
{
    std::string tmp;
    std::getline(std::cin, tmp);
}

int charToNum(char ch)
{
    return ch & 15;
}

void normInput(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num)
{
    std::string chosen = pair.first;
    if (scene->needs.size() > 0)
    {
        // check if you need something for this options
        std::string need = scene->needs[num - 1];
        if (!need.empty() && !vectorContains(*myInv, need))
        {
            std::cout << "Helaas, je mist een voorwerp: " << need << std::endl;
            std::cin.get();
            scene->initScene();
            return;
        }
    }
    if (scene->gets.size() > 0)
    {
        // check if the player gets somehting from this option
        std::string get = scene->gets[num - 1];
        if (!get.empty() && !vectorContains(*myInv, get))
        {
            addToVector(*myInv, {get});
            std::cout << "je hebt verkregen: " << get << std::endl;
            std::cin.get();
        }
    }
    pair.second->initScene();
}

void testInput(Scenario *scene, std::pair<const std::string, Scenario *> pair, int num)
{
    std::cout << "Huidig: " << scene << std::endl;
    std::cout << num << ". " << pair.first << ": " << pair.second << std::endl;
    std::cout << "Dit is een test input handler" << std::endl;
}

#pragma endregion