#ifndef DNA_DATA_H
#define DNA_DATA_H

#include <string>
#include <iostream>

class DNA_data {
public:
    std::string genome_seq;
    std::string motif;
    int edit_dist;
    int motif_len;
    int genome_len;

    DNA_data();

    void set_data();
    int calculate_distance(const std::string &fragm_a, const std::string &fragm_b);
    void find_motifs();
};

#endif
