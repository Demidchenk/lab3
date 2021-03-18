#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string map[50];
    ifstream inFile("input.csv");
    int i = 0;
    while (!inFile.eof())
    {
        getline(inFile, map[i], '\n');
        i++;
    }
}
