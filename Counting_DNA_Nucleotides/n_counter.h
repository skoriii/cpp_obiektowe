#ifndef N_COUNTER_H
#define N_COUNTER_H

#include <string>
using namespace std;

class n_counter {
    string dna_sequence;

public:
    n_counter(const string& sequence);
    void count_nucleotides();
};

#endif // N_COUNTER_H
