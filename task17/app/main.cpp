#include "my_library.h"


int main()
{
    std::string filename = askName();
    std::vector<std::string> switchedLines = switchLines(readLines(filename));
    writeFile(switchedLines, filename);
}
