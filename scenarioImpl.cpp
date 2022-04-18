#include "prototypes.hpp"

// playerInventory
std::vector<std::string> *myInv = new std::vector<std::string>();

// vector checking

#pragma region vectorhandling
void addToVector(std::vector<std::string> &vec, std::vector<std::string> add)
{
    // check for doubles
    if (vec.size() == 0)
    {
        for (auto i : add)
            vec.push_back(i);
        return;
    }
    for (auto i : vec)
    {
        for (auto j : add)
        {
            if (i == j)
                continue;
            vec.push_back(j);
        }
    }
}
bool vectorContains(std::vector<std::string> &vec, std::string cont)
{
    for (auto i : vec)
    {
        if (i == cont)
            return true;
    }
    return false;
}
#pragma endregion

// scenario prototypes
#pragma region sceanrios
Scenario::Scenario(std::string text)
{
    this->text = text;
}
Scenario::Scenario(std::string text, std::map<std::string, Scenario *> options)
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

void Scenario::setup(std::map<std::string, Scenario *> options, std::map<Scenario *, void (*)(Scenario *, std::pair<const std::string, Scenario *>, int)> handlers)
{
    this->options = options;
    this->handlers = handlers;
}
void Scenario::testIt(void)
{
    for (auto iter = options.begin(); iter != options.end(); ++iter)
    {
        std::cout << iter->first << std::endl;
    }
}

void Scenario::initScene(void)
{
    system("cls");
    // std::cout << myInv->size() << std::endl;
    std::cout << text << std::endl;
    std::cout << getOptions() << std::flush;
    handleInput();
}

void Scenario::handleInput()
{
    std::getline(std::cin, lastInput);
    // regions for commands like "inventory" etc
    if (lastInput == "inventory")
    {
        std::cout << "inventory: " << std::endl;
        std::cout << myInv->size() << std::endl;
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
            auto handler = handlers.at(iter->second);
            handler(this, *iter, inpNum);
            return;
        }
    }
    // fallback
    initScene();
}

void Scenario::setGet(std::map<Scenario *, std::string> setget)
{
    this->gets = setget;
}
void Scenario::setNeed(std::map<Scenario *, std::string> setneed)
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
        // try catch to see if the chosen option has a "need"
        try
        {
            std::string need = scene->needs.at(pair.second);
            if (!vectorContains(*myInv, need))
            {
                std::cout << "Helaas, je mist een voorwerp: " << need << std::endl;
                std::cin.get();
                scene->initScene();
                return;
            }
        }
        catch (...)
        {
        }
    }
    if (scene->gets.size() > 0)
    {
        // try catch to see if the chosen options has a "get"
        try
        {
            std::string get = scene->gets.at(pair.second);
            addToVector(*myInv, {get});
            std::cout << "je hebt verkregen: " << get << std::endl;
            std::cin.get();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    pair.second->initScene();
}

#pragma endregion