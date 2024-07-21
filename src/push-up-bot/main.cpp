#include "push_up_bot.h"
#include <fstream>
#include <sstream>
#include <iostream>

int main()
{
    std::ifstream infile("../tokens.txt");

    std::string line;
    std::getline(infile, line);
    std::istringstream iss(line);

    std::string endpoint;
    std::string configName;
    std::string logName;
    int64_t channelID;
    int64_t adminID;

    if (!(iss >> endpoint >> configName >> logName >> channelID >> adminID))
    {
        std::cerr << "Incorrect token!" << std::endl;
        return 1;
    }

    PushUpBot(endpoint, configName, logName, channelID, adminID).Run();
}