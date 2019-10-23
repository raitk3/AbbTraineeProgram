#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#define QUOTATION_MARKS 34
#define SEMICOLON 59

std::string parser(std::string input_string);

void write(std::string filename, std::string text);
