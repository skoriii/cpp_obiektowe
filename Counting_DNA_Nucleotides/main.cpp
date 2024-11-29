#include <iostream>
#include <string>
#include "n_counter.h"

using namespace std;

int main() {
    string seq;
    cout << "Wprowadź sekwencje: " << endl;
    cin >> seq;

    n_counter analyzer(seq);
    analyzer.count_nucleotides();

    return 0;
}
