#ifndef AMINO_H
#define AMINO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* This table associates a protein sequence (the first string)
 * with corresponding RNA sequences. Each row is a list of strings, NULL terminated. 
 * The table itself is also NULL terminated.
 */

char **amino_table[] = {
    (char *[]){"Ala", "GCU", "GCC", "GCA", "GCG", "GCN", NULL},
    (char *[]){"Leu", "UUA", "UUG", "CUU", "CUC", "CUA", "CUG", "YUR", "CUN", NULL},
    (char *[]){"Arg", "CGU", "CGC", "CGA", "CGG", "AGA", "AGG", "CGN", "MGR", NULL},
    (char *[]){"Lys", "AAA", "AAG", "AAR", NULL},
    (char *[]){"Asn", "AAU", "AAC", "AAY", NULL},
    (char *[]){"Met", "AUG", NULL},
    (char *[]){"Asp", "GAU", "GAC", "GAY", NULL},
    (char *[]){"Phe", "UUU", "UUC", "UUY", NULL},
    (char *[]){"Cys", "UGU", "UGC", "UGY", NULL},
    (char *[]){"Pro", "CCU", "CCC", "CCA", "CCG", "CCN", NULL},
    (char *[]){"Gln", "CAA", "CAG", "CAR", NULL},
    (char *[]){"Ser", "UCU", "UCC", "UCA", "UCG", "AGU", "AGC", "UCN", "AGY", NULL},
    (char *[]){"Glu", "GAA", "GAG", "GAR", NULL},
    (char *[]){"Thr", "ACU", "ACC", "ACA", "ACG"  "ACN", NULL},
    (char *[]){"Gly", "GGU", "GGC", "GGA", "GGG"  "GGN", NULL},
    (char *[]){"Trp", "UGG", NULL},
    (char *[]){"His", "CAU", "CAC", "CAY", NULL},
    (char *[]){"Tyr", "UAU", "UAC", "UAY", NULL},
    (char *[]){"Ile", "AUU", "AUC", "AUA", "AUH", NULL},
    (char *[]){"Val", "GUU", "GUC", "GUA", "GUG", "GUN", NULL},
    NULL
};

/* Lookup is performed by iterating through each row, and checking if a string
 * is in that row, if it's found, the first string in the row is returned.
 */
const char *amino_lookup(char *rna) {
    size_t x, y;
    char **row;
    char *word;
    char *first;
    y = 0;

    while (( row = amino_table[y++] )) {
        first = row[0];
        x = 1;
        while (( word = row[x++] ))
            if ( strcmp(word, rna ) == 0 )
                return first;
    }

    return NULL;
}

#endif /* AMINO_H */
