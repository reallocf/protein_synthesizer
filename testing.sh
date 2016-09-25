echo "Working Tests:"
echo "Input: TACAAACCCTTTGGGATC"
echo "Output:"
./protein_synthesizer TACAAACCCTTTGGGATC
echo "Input: TACGATCGATAGCTAGCTAGCACT"
echo "Output:"
./protein_synthesizer TACGATCGATAGCTAGCTAGCACT
echo "Input: TACACGTATCTTGGCTAGCTAATT"
echo "Output:"
./protein_synthesizer TACACGTATCTTGGCTAGCTAATT
echo "Input: TACTCGGGGCGCATCCAAGAGATT (trailing DNA)"
echo "Output:"
./protein_synthesizer TACTCGGGGCGCATCCAAGAGATT
echo "Input: CAAGAGATTTACTCGGGGCGCATC (leading DNA)"
echo "Output:"
./protein_synthesizer CAAGAGATTTACTCGGGGCGCATC
echo "Input: CAAGAGATTTACTCGGGGCGCATCCAAGAGATT (trailing and leading DNA)"
echo "Output:"
./protein_synthesizer CAAGAGATTTACTCGGGGCGCATCCAAGAGATT
echo "Input: TACTTTATT TACAAAATT TACCCCATT TACGGGATC (multiple DNA strands)"
echo "Output:"
./protein_synthesizer TACTTTATT TACAAAATT TACCCCATT TACGGGATC
echo
echo
echo "Broken Tests:"
echo "Input: (no input)"
echo "Output:"
./protein_synthesizer
echo "Input: AUGTTTATT (no starting codon)"
echo "Output:"
./protein_synthesizer AUGTTTATT
echo "Input: TACTTTAAA (no ending codon)"
echo "Output:"
./protein_synthesizer TACTTTAAA
echo "Input: TACTTYATT (improper nucleotide)"
echo "Output:"
./protein_synthesizer TACTTYATT
echo "Input: TACTTTATT TACAAAATC TATCCCATT TACGGGATC (working and broken DNA strands)"
echo "Output:"
./protein_synthesizer TACTTTATT TACAAAATG TATCCCATT TACGGGATC
