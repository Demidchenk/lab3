#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class myQueue
{
    int ar[200];
public:
    int size = sizeof(ar) / sizeof(int);
    int front()
    {
        return ar[0];
    }
    void push(int n)
    {
        ar[size] = n;
        size++;
    }
    void pop()
    {
        for (int i = 0; i < size - 1; i++)
        {
            ar[i] = ar[i + 1];
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
    cin >> x1 >> y1;
    cout << "Input ending coordinates\n";
    cin >> x2 >> y2;

    pair<int, int> vert[300];
    bool v[30][30];
    int mark[30][30];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'X') mark[i][j] = 10000;
            else
            {
                mark[i][j] = 1000;
                v[i][j] = false;
            }
        }
    }

    int k = 0;
    int x3 = x1, y3 = y1;
    vert[0].first = x3;
    vert[0].second = y3;
    myQueue q;
    q.push(0);
    mark[x3][y3] = 0;
    while (x3 != x2 || y3 != y2)
    {
        v[x3][y3] = true;
        if (map[x3 + 1][y3] == ' ' && !v[x3 + 1][y3] && mark[x3][y3] + 1 < mark[x3+1][y3])
        {
            mark[x3 + 1][y3] = mark[x3][y3] + 1;
            k++;
            vert[k].first = x3 + 1;
            vert[k].second = y3;
            q.push(k);
        }
        if (map[x3 - 1][y3] == ' ' && !v[x3 - 1][y3] && mark[x3][y3] + 1 < mark[x3 - 1][y3])
        {
            mark[x3 - 1][y3] = mark[x3][y3] + 1;
            k++;
            vert[k].first = x3 - 1;
            vert[k].second = y3;
            q.push(k);
        }
        if (map[x3][y3 + 1] == ' ' && !v[x3][y3 + 1] && mark[x3][y3] + 1 < mark[x3][y3 + 1])
        {
            mark[x3][y3 + 1] = mark[x3][y3] + 1;
            k++;
            vert[k].first = x3;
            vert[k].second = y3 + 1;
            q.push(k);
        }
        if (map[x3][y3 - 1] == ' ' && !v[x3][y3 - 1] && mark[x3][y3] + 1 < mark[x3][y3 - 1])
        {
            mark[x3][y3 - 1] = mark[x3][y3] + 1;
            k++;
            vert[k].first = x3;
            vert[k].second = y3 - 1;
            q.push(k);
        }
        q.pop();
        x3 = vert[q.front()].first;
        y3 = vert[q.front()].second;
    }

    while (x3 != x1 || y3 != y1)
    {
        if (mark[x3][y3] <= 9) map[x3][y3] = '0' + mark[x3][y3];
        else map[x3][y3] = 'a' + (mark[x3][y3] - 10);

        if (mark[x3 + 1][y3] == mark[x3][y3] - 1)
        {
            x3++;
            continue;
        }
        if (mark[x3 - 1][y3] == mark[x3][y3] - 1)
        {
            x3--;
            continue;
        }
        if (mark[x3][y3 + 1] == mark[x3][y3] - 1)
        {
            y3++;
            continue;
        }
        if (mark[x3][y3 - 1] == mark[x3][y3] - 1)
        {
            y3--;
            continue;
        }
    }

    ofstream outFile("output.csv");
    for (int i = 0; i < n; i++)
    {
        outFile << map[i] << endl;
        cout << map[i] << endl;
    }
}
