#include "my_library.h"

int main()
{
    std::string source_text = readFile();
    if (source_text.length() == 0) return 1;
    auto [index, length, end] = getBeginEnd();
    std::string textToPrint = get_text(source_text, index, length, end);
    printText(textToPrint);
}
