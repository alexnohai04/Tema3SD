#include <fstream>

using namespace std;

ifstream f("plantatie.in");
ofstream g("plantatie.out");

const int NMAX = 507;

int r[NMAX][NMAX][10];
int e[NMAX];

int main()
{
    int n, m;
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f >> r[i][j][0];


    for (int p = 1, lat = 2; lat <= n; p++, lat *= 2)
        for (int i = 1; i <= n - lat + 1; i++)
            for (int j = 1; j <= n - lat + 1; j++)
            {
                int i2 = i + (lat >> 1);
                int j2 = j + (lat >> 1);
                r[i][j][p] = max(r[i][j][p - 1], max(r[i2][j][p - 1], max(r[i][j2][p - 1], r[i2][j2][p - 1])));
            }


    for (int i = 2; i <= n; i++)
        e[i] = 1 + e[i / 2];

    while (m--)
    {
        int i, j, l;
        f >> i >> j >> l;

        int k = e[l];
        int lung = (1 << k);
        int i2 = i + l - lung;
        int j2 = j + l - lung;
        g << max(r[i][j][k], max(r[i2][j][k], max(r[i][j2][k], r[i2][j2][k]))) << '\n';
    }
    return 0;
}