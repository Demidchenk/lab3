#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class myQueue
{
    int ar[200];
public:
    int size = sizeof(ar) / sizeof(int);

    int front = ar[0];
    int back = ar[size - 1];
    void push(int n)
    {
        ar[size] = n;
    }
    void pop()
    {
        for (int i = 0; i < size - 1; i++)
        {
            ar[i] = ar[i - 1];
        }
        ar[size - 1] = NULL;
    }
};

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
