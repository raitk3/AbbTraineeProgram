#pragma once

#include <iostream>
#include <fstream>
#include <tuple>

std::string readFile();

std::tuple<char, int, char> getBeginEnd();

std::string get_text(std::string source_text, char index, int length, char end);

void printText(std::string text);
