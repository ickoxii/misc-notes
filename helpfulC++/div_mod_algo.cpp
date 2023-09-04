#include <iostream>

using namespace std;

class BAD{};

void divModAlgo(int n, int d, int *q, int *r) {
    *q = 0;
    *r = n;
    if (n >= 0) {
        while (*r >= d) {
            (*q)++;
            *r -= d;
        }
    }
    else {
        while (*r < 0) {
            (*q)--;
            *r += d;
        }
    }
}

int main() {
    int n, d, q, r;

    while (int x = 1) {
        cout << "Enter n divided by d: ";
        try {
            if (!(cin >> n >> d)) {
                throw BAD();
            }
        } catch(BAD) {
            return -1;
        }


        divModAlgo(n, d, &q, &r);

        cout << "q: " << q << endl;
        cout << "r: " << r << endl;
    }

}
