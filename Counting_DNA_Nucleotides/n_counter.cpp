#include "n_counter.h"
#include <iostream>
using namespace std;

n_counter::n_counter(const string& sequence) : dna_sequence(sequence) {}

void n_counter::count_nucleotides() {
    int A = 0, C = 0, G = 0, T = 0;

    for (char nucleotide : dna_sequence) {
        if (nucleotide == 'A') A++;
        else if (nucleotide == 'C') C++;
        else if (nucleotide == 'G') G++;
        else if (nucleotide == 'T') T++;
    }

    cout << "A: " << A << " C: " << C << " G: " << G << " T: " << T << endl;
}
