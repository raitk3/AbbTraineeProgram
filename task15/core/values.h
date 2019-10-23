#pragma once

#include <map>
#include <string>
#include <list>
// #48-57 - 0-9
static std::map<char, std::list<std::string>> values = {
        {48, {" "}},
        {49, {""}},
        {50, {"a", "b", "c"}},
        {51, {"d", "e", "f"}},
        {52, {"g", "h", "i"}},
        {53, {"j", "k", "l"}},
        {54, {"m", "n", "o"}},
        {55, {"p", "q", "r", "s"}},
        {56, {"t", "u", "v"}},
        {57, {"w", "x", "y", "z"}}
};
