#pragma once

#include <map>
#include <vector>

#define NIL 48
#define ONE 49
#define TWO 50
#define THREE 51
#define FOUR 52
#define FIVE 53
#define SIX 54
#define SEVEN 55
#define EIGHT 56
#define NINE 57

static std::map<int, std::vector<std::string>> charsMap
{
    {NIL, {
            " *** ",
            "*   *",
            "*  **",
            "* * *",
            "**  *",
            "*   *",
            " *** "
        }},
    {ONE, {
            "  *  ",
            " **  ",
            "* *  ",
            "  *  ",
            "  *  ",
            "  *  ",
            "*****"

        }},
    {TWO, {
            " *** ",
            "*   *",
            "    *",
            "   * ",
            "  *  ",
            " *   ",
            "*****"
        }},
    {THREE, {
            " *** ",
            "*   *",
            "    *",
            "  ** ",
            "    *",
            "*   *",
            " *** "
        }},
    {FOUR, {
            "   * ",
            "  ** ",
            " * * ",
            "*  * ",
            "*****",
            "   * ",
            "   * "
        }},
    {FIVE, {
            "*****",
            "*    ",
            "*    ",
            "**** ",
            "    *",
            "*   *",
            " *** "
        }},
    {SIX, {
            " *** ",
            "*   *",
            "*    ",
            "**** ",
            "*   *",
            "*   *",
            " *** "
        }},
    {SEVEN, {
            "*****",
            "*   *",
            "    *",
            "   * ",
            "  *  ",
            "  *  ",
            "  *  "
        }},
    {EIGHT, {
            " *** ",
            "*   *",
            "*   *",
            " *** ",
            "*   *",
            "*   *",
            " *** "
        }},
    {NINE, {
            " *** ",
            "*   *",
            "*   *",
            " ****",
            "    *",
            "*   *",
            " *** "
        }}
};
