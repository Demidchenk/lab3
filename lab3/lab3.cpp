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
        size++;
    }
    void pop()
    {
        for (int i = 1; i < size - 1; i++)
        {
            ar[i] = ar[i - 1];
        }
        ar[size - 1] = NULL;
        size--;
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
        cout << map[i] << endl;
        i++;
    }

    int x1, y1, x2, y2;
    cout << "Input starting coordinates\n";
    cin >> x1, y1;
    cout << "Input ending coordinates\n";
    cin >> x2, y2;

    int mark[30][30] = { 10000 };
    int x3 = x1, y3 = y1;
    
    
}
