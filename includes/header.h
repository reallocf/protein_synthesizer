#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

// Preprocessor directives are cool because you can write compile-time logic.
// But for run-time logic I try to avoid them, they're hard to debug, hard to read,
// and more error-prone.

# define IS_START_CODON(DNA1, DNA2, DNA3) (DNA1 == 'T' && \
                                           DNA2 == 'A' && DNA3 == 'C')

# define IS_END_CODON(DNA1, DNA2, DNA3) ((DNA1 == 'A' && \
                                          DNA2 == 'T' && DNA3 == 'T') || \
                                         (DNA1 == 'A' && DNA2 == 'T' && \
                                          DNA3 == 'C') || \
                                         (DNA1 == 'A' && DNA2 == 'C' && \
                                          DNA3 == 'T'))

  typedef struct s_mRNA
  {
    struct s_mRNA *end_3;
    char codon[3];
  } t_mRNA;

  typedef struct s_tRNA
  {
    char anticodon[3];
  } t_tRNA;

  typedef struct s_amino_acid
  {
    struct s_amino_acid *amino_group;
    char name[3];
  } t_amino_acid;

  t_mRNA *transcription(char *DNA_strand);
  int start_and_stop_codons_exist(char *DNA);
  int read_DNA(t_mRNA **mRNA, char DNA1, char DNA2, char DNA3);
  char DNA_to_RNA(char DNA);
  t_amino_acid *translation(t_mRNA *mRNA_strand);
  void read_mRNA(t_tRNA **tRNA, t_mRNA *mRNA);
  char RNA_to_RNA(char RNA);
  void find_attached_amino_acid(t_tRNA *tRNA, t_amino_acid *amino_acid);
  void find_attached_amino_acid_G(t_tRNA *tRNA, t_amino_acid *amino_acid);
  void find_attached_amino_acid_C(t_tRNA *tRNA, t_amino_acid *amino_acid);
  void find_attached_amino_acid_U(t_tRNA *tRNA, t_amino_acid *amino_acid);
  void name_amino_acid(t_amino_acid *amino_acid, char *name);
  void free_mRNA(t_mRNA *mRNA_strand);
  void output(t_amino_acid *polypeptide_chain);
  void handle_error(void);
  void free_polypeptide_chain(t_amino_acid *polypeptide_chain);

  int g_error;

#endif
