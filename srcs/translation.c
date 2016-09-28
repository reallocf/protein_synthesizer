#include "header.h"

t_amino_acid *translation(t_mRNA *mRNA_strand)
{
  t_mRNA *mRNA_current;
  t_tRNA *tRNA;
  t_amino_acid *polypeptide_head;
  t_amino_acid *polypeptide_body;
  
  // Dynamically allocating polypeptide_head so you can return it later - that's perfectly fine.
  // But why dynamically allocate tRNA just to free it at the end of the function?
  // Declaring it as:
  // t_tRNA tRNA[1] = {0};
  // Gives you identical identical syntax minus the messy heap memory management.
  if ((polypeptide_head = (t_amino_acid*)malloc(sizeof(t_amino_acid))) == 0 ||
      (tRNA = (t_tRNA*)malloc(sizeof(t_tRNA))) == 0)
    g_error = -1;

  // You could have included this in the above if statement, and saved yourself a redundant block of code.
  if (g_error)
    return (0);

  read_mRNA(&tRNA, mRNA_strand);
  find_attached_amino_acid(tRNA, polypeptide_head);

  mRNA_current = mRNA_strand->end_3;

  polypeptide_body = polypeptide_head;

  while (mRNA_current)
  {

    if ((polypeptide_body->amino_group =
         (t_amino_acid*)malloc(sizeof(t_amino_acid))) == 0)
      g_error = -1; // Why not return here? We ran out of memory.

    read_mRNA(&tRNA, mRNA_current);

    // Redundant check, see above comment.
    if (g_error)
      return (0);

    find_attached_amino_acid(tRNA, polypeptide_body->amino_group);
    polypeptide_body = polypeptide_body->amino_group;
    mRNA_current = mRNA_current->end_3;
  }

  polypeptide_body->amino_group = 0;
  
  // Freeing at the end of the function... probably a great place to use stack memory instead.
  free_mRNA(mRNA_strand);
  free(tRNA);
  return (polypeptide_head);
}

// Why use double-pointers here? Single pointers would suffice - since you're not mutating the pointer itself.
void read_mRNA(t_tRNA **tRNA, t_mRNA *mRNA)
{
  (*tRNA)->anticodon[0] = RNA_to_RNA(mRNA->codon[0]);
  (*tRNA)->anticodon[1] = RNA_to_RNA(mRNA->codon[1]);
  (*tRNA)->anticodon[2] = RNA_to_RNA(mRNA->codon[2]);
}

char RNA_to_RNA(char RNA)
{
  // Try using a switch-case.
  // Shows a clearer 1:1 mapping, less verbose.
  switch(RNA){
  case 'A': return 'U';
  case 'U': return 'A';
  case 'G': return 'C';
  case 'C': return 'G';
  }
  return 0;
/*
  if (RNA == 'A')
    return ('U');
  else if (RNA == 'U')
    return ('A');
  else if (RNA == 'G')
    return ('C');
  else if (RNA == 'C')
    return ('G');
  else
    return (0);
*/
}

void free_mRNA(t_mRNA *mRNA_strand)
{
  t_mRNA *temp_mRNA;

  while (mRNA_strand)
  {
    temp_mRNA = mRNA_strand->end_3;
    free(mRNA_strand);
    mRNA_strand = temp_mRNA;
  }
}
