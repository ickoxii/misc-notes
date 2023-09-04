#include <iostream>
#include <math>
using namespace std;

int mod(int n, int d) {
    int q = 0;
    int r = n;
    if (n >= 0) {
        while (r >= d) {
            q++;
            r -= d;
        }
    }
    else {
        while (r < 0) {
            q--;
            r += d;
        }
    }
    return r;
}

void encrypt(int *c, int m, int e, int N) {
    *c = mod(pow(m, e), N);
}

void decrypt(int c, int *m, int d, int N) {
    *m = mod(pow(c, d), N);
}

int main() {


    return 0;
}
