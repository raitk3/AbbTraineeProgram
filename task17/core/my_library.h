#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string askName();

std::vector<std::string> readLines(std::string filename);

std::vector<std::string> switchLines (std::vector<std::string> lines);

void writeFile(std::vector<std::string> lines, std::string filename);
