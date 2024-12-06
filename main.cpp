#include <iostream>
#include <string>
#include "DNA_into_RNA.h"

using namespace std;

int main() {
    string seq;
    cout << "Wprowadź sekwencje: " <<endl;
    cin >> seq;

    DNA_into_RNA transcriber(seq);
    transcriber.transcribe();
    return 0;
}
