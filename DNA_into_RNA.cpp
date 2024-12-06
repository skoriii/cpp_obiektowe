#include "DNA_into_RNA.h"
#include <iostream>
using namespace std;

DNA_into_RNA::DNA_into_RNA(const string& sequence) : dna_sequence(sequence) {}

void DNA_into_RNA::transcribe() {
    for (char nucleotide: dna_sequence) {
        if (nucleotide == 'A') cout << 'U';
        else if (nucleotide == 'T') cout << 'A';
        else if (nucleotide == 'G') cout << 'C';
        else if (nucleotide == 'C') cout << 'G';
    }

}