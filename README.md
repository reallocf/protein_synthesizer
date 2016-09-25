# protein_synthesizer

Takes in DNA sequences and outputs proteins using transcription and translation.
Effort was made to sythesize similarly to how biology functions as opposed to following the shortest route.

DNA sequences are exptected to be inputted from the stdin in the form of non-delimited, capitalized nucleotides (A, C, T, or G). They are read following the executable with each additional argument corresponding to another sequence.
Proteins are outputted to the stdout in the form of dash-delimited amino acids.

Appropriate errors are thrown if:
* There is no input.
* A strand does not have a start or stop codon.
* There are any input characters other than 'A', 'T', 'C', or 'G'.
If multiple sequences are given, the other sequences will still give outputs.

Transcription:
Each DNA strand will be scanned until a sequence generating an mRNA start codon (AUG) is found.
At this point, an mRNA strand (built as a linked list) is formed.
New elements are added until an mRNA stop codon (UAG, UAA, or UGA) is formed.

Translation:
Each codon in the mRNA strand is then paired with the corresponding anticodon of a tRNA molecule.
This tRNA molecule then places its corresponding amino acid in the growing polypeptide chain, which is linked together as each consecutive tRNA molecule adds to it.
This process stops when the mRNA strand ends.

---

To run:

1. Clone/Download this repository.

2. Open the cloned file with your terminal.

3. Type the command "make" and hit enter. I used a makefile for this project to aid in compilation and cleanup.

4. Type "./protein_synthesizer " and the DNA strand you want analyzed. You may also type "sh testing.sh" to run a number of simple tests.
