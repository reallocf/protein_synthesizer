#include "header.h"

int main(int argc, char **argv)
{
  int i;
  t_mRNA *mRNA_strand;
  t_amino_acid *polypeptide_chain;

  if (argc == 1)
  {
    write(2, "No input\n", 9);
    return (0);
  }
  i = 1;
  while (i < argc)
  {
    g_error = 0;
    mRNA_strand = transcription(argv[i]);
    if (!g_error)
      polypeptide_chain = translation(mRNA_strand);
    if (!g_error)
      output(polypeptide_chain);
    else
      handle_error();
    i++;
  }
  return (0);
}

// The header #include <unistd.h>
// defines STDERR_FILENO, which would be a lot clearer to comprehend than `2`.
void handle_error(void)
{
  // Why hard code string length?
  // Let the compiler worry about that stuff and your code will be more readable and less error prone.
  // see: fprintf or dprintf
  if (g_error == -1)
    write(2, "System error\n", 13);
  else if (g_error == 1)
    write(2, "No start codon\n", 15);
  else if (g_error == 2)
    write(2, "No end codon\n", 13);
  else if (g_error == 3)
    write(2, "Unrecognized nucleotide(s)\n", 27);
}

void output(t_amino_acid *polypeptide_chain)
{
  while (polypeptide_chain)
  {
    write(1, polypeptide_chain->name, 3);
    polypeptide_chain = polypeptide_chain->amino_group;
    if (polypeptide_chain)
      write(1, "-", 1);
  }
  free_polypeptide_chain(polypeptide_chain);
  write(1, "\n", 1);
}

void free_polypeptide_chain(t_amino_acid *polypeptide_chain)
{
  t_amino_acid *temp_amino_acid;

  while (polypeptide_chain)
  {
    temp_amino_acid = polypeptide_chain->amino_group;
    free(polypeptide_chain);
    polypeptide_chain = temp_amino_acid;
  }
}
