#include "header.h"

void find_attached_amino_acid(t_tRNA *tRNA, t_amino_acid *amino_acid)
{
  if (tRNA->anticodon[0] == 'A')
  {
    if (tRNA->anticodon[1] == 'A')
    {
      if (tRNA->anticodon[2] == 'A' || tRNA->anticodon[2] == 'G')
        name_amino_acid(amino_acid, "Phe");
      else
        name_amino_acid(amino_acid, "Leu");
    }
    else if (tRNA->anticodon[1] == 'U')
      name_amino_acid(amino_acid, "Tyr");
    else if (tRNA->anticodon[1] == 'G')
      name_amino_acid(amino_acid, "Ser");
    else
    {
      if (tRNA->anticodon[2] == 'A' || tRNA->anticodon[2] == 'G')
        name_amino_acid(amino_acid, "Cys");
      else
        name_amino_acid(amino_acid, "Trp");
    }
  }
  else
    find_attached_amino_acid_G(tRNA, amino_acid);
}

void find_attached_amino_acid_G(t_tRNA *tRNA, t_amino_acid *amino_acid)
{
  if (tRNA->anticodon[0] == 'G')
  {
    if (tRNA->anticodon[1] == 'A')
      name_amino_acid(amino_acid, "Leu");
    else if (tRNA->anticodon[1] == 'U')
    {
      if (tRNA->anticodon[2] == 'A' || tRNA->anticodon[2] == 'G')
        name_amino_acid(amino_acid, "His");
      else
        name_amino_acid(amino_acid, "Gln");
    }
    else if (tRNA->anticodon[1] == 'G')
      name_amino_acid(amino_acid, "Pro");
    else
      name_amino_acid(amino_acid, "Arg");
  }
  else
    find_attached_amino_acid_C(tRNA, amino_acid);
}

void find_attached_amino_acid_C(t_tRNA *tRNA, t_amino_acid *amino_acid)
{
  if (tRNA->anticodon[0] == 'C')
  {
    if (tRNA->anticodon[1] == 'A')
      name_amino_acid(amino_acid, "Val");
    else if (tRNA->anticodon[1] == 'U')
    {
      if (tRNA->anticodon[2] == 'A' || tRNA->anticodon[2] == 'G')
        name_amino_acid(amino_acid, "Asp");
      else
        name_amino_acid(amino_acid, "Glu");
    }
    else if (tRNA->anticodon[1] == 'G')
      name_amino_acid(amino_acid, "Ala");
    else
      name_amino_acid(amino_acid, "Gly");
  }
  else
    find_attached_amino_acid_U(tRNA, amino_acid);
}

void find_attached_amino_acid_U(t_tRNA *tRNA, t_amino_acid *amino_acid)
{
  if (tRNA->anticodon[1] == 'A')
  {
    if (tRNA->anticodon[2] == 'C')
      name_amino_acid(amino_acid, "Met");
    else
      name_amino_acid(amino_acid, "Ile");
  }
  else if (tRNA->anticodon[1] == 'U')
  {
    if (tRNA->anticodon[2] == 'A' || tRNA->anticodon[2] == 'G')
      name_amino_acid(amino_acid, "Asn");
    else
      name_amino_acid(amino_acid, "Lys");
  }
  else if (tRNA->anticodon[1] == 'G')
    name_amino_acid(amino_acid, "Thr");
  else
  {
    if (tRNA->anticodon[2] == 'A' || tRNA->anticodon[2] == 'G')
      name_amino_acid(amino_acid, "Ser");
    else
      name_amino_acid(amino_acid, "Arg");
  }
}

void name_amino_acid(t_amino_acid *amino_acid, char *name)
{
  amino_acid->name[0] = name[0];
  amino_acid->name[1] = name[1];
  amino_acid->name[2] = name[2];
}
