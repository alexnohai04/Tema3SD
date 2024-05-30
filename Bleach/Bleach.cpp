#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream f("bleach.in");
ofstream g("bleach.out");
int n, k;
long long sum, rez;

int main() {
    
    f >> n >> k;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n + k; i++) {
        if (i <= n) {
            int el;
            f >> el;
            pq.push(el);
        }
        if (i > k) {
            int el = pq.top();
            pq.pop();
            if (el - sum > rez)
                rez = el - sum;
            sum += el;
        }
    }

    g << rez;

    f.close();
    g.close();
    return 0;
}
