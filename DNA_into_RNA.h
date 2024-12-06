#ifndef DNA_INTO_RNA_H
#define DNA_INTO_RNA_H

#include <string>
using namespace std;

class DNA_into_RNA {
    string dna_sequence;

public:
    DNA_into_RNA(const string& sequence);
    void transcribe();
};

#endif // DNA_INTO_RNA_H
