#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sequence {
public:
    Sequence() : header(""), sequence("") {}

    // wczytania pliku fasta
    void readFasta(const string& filepath) {
        ifstream file(filepath);

        string line;
        bool isHeader = true;

        while (getline(file, line)) {
            if (line.empty()) continue; // Pomijamy puste linie

            if (line[0] == '>') { // Nagłówek
                header = line.substr(1); // Usuwamy znak '>'
                isHeader = false;
            }
            else if (!isHeader) { // Sekwencja
                sequence += line;
            }
        }

        file.close();

        // output wczytanych plikow
        cout << "Naglowek: " << header << endl;
        cout << "Sekwencja: " << sequence << endl;
    }

private:
    string header;   // Nagłówek FASTA
    string sequence; // Sekwencja
};

int main() {
    Sequence seq;

    seq.readFasta("ex1/DNA.FASTA");

    return 0;
}