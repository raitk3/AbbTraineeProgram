#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

#define NEW_LINE 10
#define QUOTATION_MARK 34
#define COMMA 44

void print_Table(std::map<int, std::vector<std::string>> rows, int max_length, int number_of_rows);

std::string getTextFromCsv(std::string myFileName);

std::map<int, std::vector<std::string>> parser(std::string text, int& row_index, int& max_length);
