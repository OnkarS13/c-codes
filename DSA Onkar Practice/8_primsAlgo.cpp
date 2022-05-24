#include <iostream>
#include <stdlib.h>
using namespace std;

#define ROW 10
#define COL 10
#define infi 9999

class Prims
{
    int graph[ROW][COL];
    int nodes;

public:
    void createGraph();
    void primsAlgo();
};

void Prims::createGraph()
{
    int i, j;
    cout << "Enter Total Offices: ";
    cin >> nodes;
    cout << "\nEnter Adjacency Matrix: \n";
    for (int i = 0; i < nodes; i++)
    {
        for (int j = i; j < nodes; j++)
        {
            cout << "Enter distance between " << i << " and " << j << endl;
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = infi;
            }
        }
    }
}

void Prims::primsAlgo()
{
    int selected[ROW], i, j, ne = 0;
    int zero = 0, one = 1, min = 0, x, y;
    int cost = 0;

    for (int i = 0; i < nodes; i++)
    {
        selected[i] = zero;
    }

    selected[0] = one;

    while (ne < nodes - 1)
    {
        min = infi;

        for (int i = 0; i < nodes; i++)
        {
            if (selected[i] == one)
            {
                for (int j = 0; j < nodes; j++)
                {
                    if (selected[j] == zero)
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = one;
        cout << "\n"
             << x << " --> " << y;
        cost += graph[x][y];
        ne++;
    }
    cout << "\nTotal cost is: " << cost << endl;
}
int main()
{
    Prims MST;
    cout << "\nPrims Algorithm to connect several offices\n";
    MST.createGraph();
    MST.primsAlgo();
}
