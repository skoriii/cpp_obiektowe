#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

class Sequence {
public:
    Sequence() : sequence("") {}

    //wczytanie pliku z sekwencja DNA (to nie fasta - cala linia to sekwencja)
    void readSequence(const string& filepath) {
        ifstream file(filepath);
        if (file.is_open()) {
            getline(file, sequence);  
            file.close();
        }
        else {
            cerr << "Nie można otworzyć pliku." << endl;
        }
    }


    string getSequence() const {
        return sequence;
    }

private:
    string sequence; 
};

class DNACounter {
public:

    DNACounter(const Sequence& seqObj) : sequence(seqObj.getSequence()) {}

    // liczenie wystąpień nukleotydów
    unordered_map<char, int> countNucleotides() {
        unordered_map<char, int> counts = { {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0} };

        for (char nucleotide : sequence) {
            if (counts.find(nucleotide) != counts.end()) {
                counts[nucleotide]++;
            }
        }
        return counts;
    }

    // output zliczeń
    void displayCounts() {
        unordered_map<char, int> counts = countNucleotides();
        cout << counts['A'] << " " << counts['C'] << " " << counts['G'] << " " << counts['T'] << endl;
    }

private:
    string sequence; 
};

int main() {
    Sequence seq;
    seq.readSequence("rosalind_dna.txt");

    DNACounter dnaCounter(seq);
    dnaCounter.displayCounts();

    return 0;
}