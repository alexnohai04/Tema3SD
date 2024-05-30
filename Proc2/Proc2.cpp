#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream f("proc2.in");
ofstream g("proc2.out");

int main()
{
    int N, M;

    priority_queue<int, vector<int>, greater<>> p;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> t;

    f >> N >> M;
    for (int i = 1; i <= N; i++)
        p.push(i);

    for (int i = 1; i <= M; i++) {
        int S, D;
        f >> S >> D;

        while (!t.empty() && t.top().first <= S) {
            p.push(t.top().second);
            t.pop();
        }

        g << p.top() << '\n';
        t.push({ S + D, p.top() });
        p.pop();
    }

    return 0;
}
