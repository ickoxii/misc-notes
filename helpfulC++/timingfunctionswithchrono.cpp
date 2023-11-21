#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    // get starting time
    auto start = high_resolution_clock::now();

    // process here

    // get end time
    auto end = high_resolution_clock::now();

    // get duration
    auto duration = duration_cast<milliseconds>(end - start);
    if (duration.count() > 1000) {
        cout << "took too long" << endl;
        return -1;
    }

    return 0;
}
