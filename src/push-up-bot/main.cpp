#include "push_up_bot.h"
#include <fstream>
#include <sstream>

int main()
{
    std::ifstream infile("../tokens.txt");

    std::string line;
    std::getline(infile, line);
    std::istringstream iss(line);

    std::string endpoint;
    std::string configName;
    int64_t channelID;
    int64_t adminID;

    if (!(iss >> endpoint >> configName >> channelID >> adminID))
    {
        return 1;
    }

    PushUpBot(endpoint, configName, channelID, adminID).Run();
}