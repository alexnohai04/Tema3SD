#include <iostream>
#include <fstream>
using namespace std;

const int N = 2500001;
const int NL = 20;

int str[NL][N];

int main()
{
    ifstream f("stramosi.in");
    ofstream g("stramosi.out");

    int n, m;
    f >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        f >> str[0][i];
    }

    for (int i = 1; i < NL; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int sp = str[i - 1][j];
            str[i][j] = str[i - 1][sp];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int q, p;
        f >> q >> p;

        while (p > 0)
        {
            int pw = 1;
            int ex = 0;

            while (pw * 2 <= p)
            {
                pw *= 2;
                ex++;
            }

            q = str[ex][q];
            p -= pw;
        }

        g << q << "\n";
    }

    f.close();
    g.close();

    return 0;
}
