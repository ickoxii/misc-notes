#include <iostream>
using namespace std;

void encrypt(int m, int k, int N, int *c) {
    *c = (m + k) % N;
}
void decrypt(int *m, int k, int N, int c) {
    *m = (c - k) % N;
}

int main() {
    int m, k = 67, N = 79, c;
    int a = 0;

    do {
        cout << "enter 1 to encrypt, 2 to decrypt" << endl;
        cin >> a;
        if (a == 1) {
            cout << "enter m to encrypt: ";
            cin >> m;
            encrypt(m, k, N, &c);
            cout << "encryption: " << c << endl;
        }
        else if (a == 2) {
            cout << "enter c to decrypt: ";
            cin >> c;
            decrypt(&m, k, N, c);
            cout << "decryption: " << m << endl;
        }
    } while (a != -1);

    return 0;
}
