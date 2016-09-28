#include "header.h"

t_mRNA *transcription(char *DNA)
{
  int i;
  t_mRNA *mRNA_head;
  t_mRNA *mRNA_body;

  // When you decouple error checking from the logic itself, instead of detecting errors along the way,
  // then you have to debug/implement a single idea in two places instead of one. Consider
  // including error checking in the logic of this single function and returning when an error
  // is detected.
  if (start_and_stop_codons_exist(DNA) == 0)
    return (0);

  i = 0;

  while (!IS_START_CODON(DNA[i], DNA[i + 1], DNA[i + 2]))
    i += 3;

  if (read_DNA(&mRNA_head, DNA[i], DNA[i + 1], DNA[i + 2]) == 0)
    return (0);

  mRNA_body = mRNA_head;
  i += 3;

  while (!IS_END_CODON(DNA[i], DNA[i + 1], DNA[i + 2]))
  {
    if (read_DNA(&mRNA_body->end_3, DNA[i], DNA[i + 1], DNA[i + 2]) == 0)
      return (0);

    mRNA_body = mRNA_body->end_3;
    i += 3;
  }

  return (mRNA_head);
}

int start_and_stop_codons_exist(char *DNA)
{
  int i;

  i = 0;

  while (DNA[i] != '\0' && DNA[i + 1] != '\0' && DNA[i + 2] != '\0' &&
         !IS_START_CODON(DNA[i], DNA[i + 1], DNA[i + 2]))
    i += 3;

  if (DNA[i] == '\0' || DNA[i + 1] == '\0' || DNA[i + 2] == '\0')
  {
    g_error = 1;
    return (0);
  }

  while (DNA[i + 2] != '\0')
  {
    if (IS_END_CODON(DNA[i], DNA[i + 1], DNA[i + 2]))
      return (1);
    i += 3;
  }

  g_error = 2;
  return (0);
}

// Readability is important, prefer flatness > nestedness.
// Also you don't need to couple logic and memory management in the same function,
// you can think of them as seperate tasks. All this function really needs to do
// is configure a struct the way you want, it doesn't need to know about memory allocations.
int read_dna(t_mRNA *rna, char d1, char d2, char d3) {

    rna->codon[0] = DNA_to_RNA(d1);
    rna->codon[1] = DNA_to_RNA(d2);
    rna->codon[2] = DNA_to_RNA(d3);
    rna->end_3 = NULL;

    if( (rna->codon[0] == 0)
     || (rna->codon[1] == 0)
     || (rna->codon[2] == 0) )
        return 0;

    return 1;
}

// Decoupling memory management lets you do nice things like this. (stack allocation)
int example() {
    t_mRNA rna;
    if ( !read_dna(&rna, 'A', 'C', 'T') ) 
        return 0;
    // etc
    return 1;
}

int read_DNA(t_mRNA **mRNA, char DNA1, char DNA2, char DNA3)
{
  if ((*mRNA = (t_mRNA*)malloc(sizeof(t_mRNA))) == 0)
  {
    g_error = -1;
    return (0);
  }
  if (((*mRNA)->codon[0] = DNA_to_RNA(DNA1)) == 0)
    g_error = 3;
  if (((*mRNA)->codon[1] = DNA_to_RNA(DNA2)) == 0)
    g_error = 3;
  if (((*mRNA)->codon[2] = DNA_to_RNA(DNA3)) == 0)
    g_error = 3;
  (*mRNA)->end_3 = 0;
  if (g_error)
    return (0);
  else
    return (1);
}

// Would be another great place for a switch-case.
char DNA_to_RNA(char DNA)
{
  if (DNA == 'A')
    return ('U');
  else if (DNA == 'T')
    return ('A');
  else if (DNA == 'G')
    return ('C');
  else if (DNA == 'C')
    return ('G');
  else
    return (0);
}
