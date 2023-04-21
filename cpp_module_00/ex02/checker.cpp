#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int main(void) {
    std::ifstream originalLog("19920104_091532.log");
    std::ifstream todayLog("today.log");

    int index = 1;
    int ret = 0;
    std::string originalLine("");
    std::string todayLine("");

    while (true) {
        if (!originalLog.eof()) {
            std::getline(originalLog, originalLine);
        }

        if (!todayLog.eof()) {
            std::getline(todayLog, todayLine);
        }

        if (originalLog.eof() || todayLog.eof()) {
            break;
        }
        
        while (!originalLine.empty() && *originalLine.begin() != ' ')
            originalLine.erase(originalLine.begin());
        while (!todayLine.empty() && *todayLine.begin() != ' ')
            todayLine.erase(todayLine.begin());

        if (originalLine != todayLine)
            ret = 1;

        std::cout 
            << std::setfill('0')
            << std::setw(2) 
            << index
            << ": ["
            << (originalLine == todayLine ? "OK" : "Error")
            << "] "
            << originalLine
            << " | "
            << todayLine
            << std::endl;

        index++;
    }

    if (!(originalLog.eof() && todayLog.eof())) {
        std::cout << "The files doesn't have the same number of lines" << std::endl;
        ret = 1;
    }
    return ret;
}
