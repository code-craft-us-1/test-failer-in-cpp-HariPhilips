#include <assert.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);

int printColorMap(std::ostream& out)
{
    int i = 0, j = 0;
    for (i = 0; i < numberOfMajorColors; i++)
    {
        for (j = 0; j < numberOfMinorColors; j++)
        {
            out  << i * numberOfMinorColors + j << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return i * j;
}

void testPrintColorMap() 
{
    std::stringstream output;
    int result = printColorMap(output);

    assert(result == 25);

    std::vector<std::string> expectedLines = {
        "0 | White | Blue", "1 | White | Orange", "2 | White | Green", "3 | White | Brown", "4 | White | Slate",
        "5 | Red | Blue", "6 | Red | Orange", "7 | Red | Green", "8 | Red | Brown", "9 | Red | Slate",
        "10 | Black | Blue", "11 | Black | Orange", "12 | Black | Green", "13 | Black | Brown", "14 | Black | Slate",
        "15 | Yellow | Blue", "16 | Yellow | Orange", "17 | Yellow | Green", "18 | Yellow | Brown", "19 | Yellow | Slate",
        "20 | Violet | Blue", "21 | Violet | Orange", "22 | Violet | Green", "23 | Violet | Brown", "24 | Violet | Slate"
    };

    std::string line;
    int lineNumber = 0;
    while (std::getline(output, line))
    {
        assert(line == expectedLines[lineNumber]);
        lineNumber++;
    }

     assert(lineNumber == 25);
}

int main()
{
    testPrintColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
