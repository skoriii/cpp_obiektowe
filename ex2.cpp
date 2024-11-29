#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sequence {
public:
    Sequence(string seq) : sequence(seq) {}

    int editDistance(string s, string t) const {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = (s[i - 1] == t[j - 1]) ? dp[i - 1][j - 1] : 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });

        return dp[m][n];
    }

    string getSequence() const { return sequence; }

private:
    string sequence;
};

class MotifFinder {
public:
    MotifFinder(Sequence& motif, Sequence genome, int maxDist)
        : motif(motif), genome(genome), maxDist(maxDist) {}

    void findMotifs() const {
        for (int start = 0; start < genome.getSequence().size(); ++start) {
            for (int len = 1; len <= motif.getSequence().size() + maxDist && start + len <= genome.getSequence().size(); ++len) {
                string subGenome = genome.getSequence().substr(start, len);
                if (motif.editDistance(motif.getSequence(), subGenome) <= maxDist)
                    cout << start + 1 << " " << len << endl;
            }
        }
    }

private:
    Sequence motif, genome;
    int maxDist;
};

int main() {
    Sequence motif("ACGTAG"), genome("ACGGATCGGCATCGT");
    MotifFinder finder(motif, genome, 2);
    finder.findMotifs();
    return 0;
}