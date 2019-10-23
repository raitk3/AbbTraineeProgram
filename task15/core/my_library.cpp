#include "my_library.h"


std::vector<std::string> generateWords(std::string number) {
    std::vector<std::string>answer;
    char numberToDo = number[0];
    if (number.size() == 1) {
        for (std::string &chr:values.at(numberToDo)) {
            answer.push_back(chr);
        }
    } else {
        std::vector<std::string>previousAnswer = generateWords(number.substr(1));
        for (std::string &chr: values.at(numberToDo)) {
            for (std::string &prev:previousAnswer) {
                answer.push_back(chr + prev);
            }
        }
    }
    return answer;
}
