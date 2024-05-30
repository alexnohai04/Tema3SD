#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream f("pikachu.in");
ofstream g("pikachu.out");

long long n, k, dr = 0, st = 999999999999;
long long p[200002], v[200002];

long long sum(int d) {
    long long dif = 0;
    for (int i = 1; i <= k; i++) {
        dif += abs(v[i] - d);
    }
    long long valmin = dif;
    for (int i = k + 1; i <= n; i++) {
        dif = dif + abs(v[i] - d) - abs(v[i - k] - d);
        valmin = min(dif, valmin);
    }
    return valmin;
}

int main() {
    f >> n >> k;
    for (int i = 1; i <= n; i++) {
        f >> v[i];
        dr = max(dr, v[i]);
        st = min(st, v[i]);
    }

    while (st <= dr) {
        long long mid = (st + dr) / 2;
        long long v_left = sum(mid - 1);
        long long v_right = sum(mid + 1);

        if (v_right < v_left)
            st = mid + 1;
        else
            dr = mid - 1;
    }

    int sol = st;
    g << sum(sol) << '\n';

    return 0;
}
