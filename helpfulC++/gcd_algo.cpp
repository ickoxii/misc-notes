#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int x, int y) {
    int r;
    if (y < x) {
        swap(x, y);
    }
    r = y % x;
    while (r != 0) {
        y = x;
        x = r;
        r = y % x;
    }
    return x;
}

int main() {
    int x, y;

    cout << "enter 2 numbers to find gcd of: ";
    cin >> x >> y;

    cout << gcd(x, y) << endl;

    return 0;
}
