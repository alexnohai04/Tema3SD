#include <fstream>
using namespace std;
ifstream f("kami.in");
ofstream g("kami.out");

const int MaxNiveluri = 100005;
const int valMax = 1000000000;

int cantitateZapada[MaxNiveluri];

int main() {
    

    int nrNiv, nrOp, poz, val, suma, op;

    f >> nrNiv;

    for (int i = 1; i <= nrNiv; i++) {
        f >> cantitateZapada[i];
    }

    f >> nrOp;

    while (nrOp--) {
        f >> op;

        if (op == 0) {
            f >> poz >> val;
            cantitateZapada[poz] = val;
        }
        else {
            f >> poz;

            suma = cantitateZapada[poz];
            poz--;
            while (poz >= 1 && suma > cantitateZapada[poz]) {
                suma += cantitateZapada[poz];
                poz--;

                if (suma > valMax) {
                    poz = 0;
                }
            }

            g << poz << '\n';
        }
    }

    f,g.close();
    return 0;
}
