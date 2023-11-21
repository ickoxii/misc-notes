// permutation
// counting
#include <iostream>
using namespace std;

int factorial(int);
int nPr(int, int);
int nCr(int, int);
void printMenu();

int main() {
    int c = 'f';
    int n, r;

    while (c != 'q') {
        printMenu();
        cin >> c;
        switch(c) {
            case 'f':
                cout << "Enter number to take factorial of: ";
                cin >> n;
                cout << factorial(n) << endl << endl;
                break;
            case 'p':
                cout << "Enter n and r values for nPr: ";
                cin >> n >> r;
                cout << nPr(n, r) << endl << endl;
                break;
            case 'c':
                cout << "Enter n and r value for nCr: ";
                cin >> n >> r;
                cout << nCr(n, r) << endl << endl;
                break;
            case 'q':
                break;
            default:
                cout << "Invalid Menu Selection" << endl << endl;
        }
    }

    return 0;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

/*
n! / (n - r)!
*/
int nPr(int n, int r) {
    return factorial(n) / factorial(n-r);
}

/*
n! / (r! * (n - r)!)
*/
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void printMenu() {
    cout << "Menu for various combinatorics:\n";
    cout << "\tEnter f for factorial\n";
    cout << "\tEnter p for nPr\n";
    cout << "\tEnter c for nCr\n";
    cout << "\tEnter q to quit" << endl;
}
