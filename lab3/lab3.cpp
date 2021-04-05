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
    int n = 0;
    while (!inFile.eof())
    {
        getline(inFile, map[n], '\n');
        cout << map[n] << endl;
        n++;
    }
    int m = map[0].length();

    int x1, y1, x2, y2;
    cout << "Input starting coordinates\n";
    cin >> x1, y1;
    cout << "Input ending coordinates\n";
    cin >> x2, y2;

    pair<int, int> vert[300];
    bool v[300];
    int mark[30][30];
    int x3 = x1, y3 = y1;
    int k = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'X') mark[i][j] = 10000;
            else
            {
                mark[i][j] = 1000;
                v[k] = false;
                k++;
            }
        }
    }
}
