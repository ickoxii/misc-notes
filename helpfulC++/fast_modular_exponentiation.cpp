#include <iostream>
#include <cmath>
using namespace std;

int func(int x, int y, int n) {
    int p = 1; // stores partial result
    int s = x; // holds current x^2^j
    int r = y; // used to compute binary expansion of y

    while (r > 0) {
        if (r mod 2 == 1) {
            p = (p*s)%n;
        }
        s = (s*s)%n;
        r = r/2;
    }
    return p;
}

int main() {
    int x, y, n;

    cout << "enter x, y, n: ";
    cin >> x >> y >> n;

    cout << func(x, y, n) << endl;

    return 0;
}
