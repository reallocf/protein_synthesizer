#include <stdio.h>
#include <stdlib.h>

#include "amino.h"

void test_lookup(char *rna) {
    printf("%s = %s\n", rna, amino_lookup(rna));
}

int main(int argc, char *argv[]){
    
    test_lookup("GUU");
    test_lookup("AGA");
    test_lookup("CUN");
    test_lookup("AUG");
    test_lookup("GUN");

    return 0;
}
