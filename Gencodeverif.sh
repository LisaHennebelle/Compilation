#!/usr/bin/env bash
# Tests de syntaxe
#
#cat minictest.c | while read line; do
    #echo $line
#done

cd Tests/Syntaxe/OK
touch minictestVerif.c
#if [[ -e "$PWD/Tests/Gencode/KO/minicctest_gencodeko.mc" ]]; then
#  echo "file exists"
#fi

echo "void main() {" > minictestVerif.c
echo "int a = 0 ;" >> minictestVerif.c
echo "}" >> minictestVerif.c
more minictestVerif.c

# acceder à la deuxieme ligne du fichier et l'afficher
#sed -n 2p minictestVerif.c > minictest.c
#more minictest.c
echo "minic test "
#sed -i 's/main/fefefe/g' minictestVerif.c
more minictestVerif.c
echo "minic test verif "
# int  i

# int  i = 0; void main () {} # K= 0; void main () {} # KO => "void" <= "voi"
cd ../KO

# Tests de verification
cd ../../Verif/OK



cd ../KO

# Test de Gencode
cd ../../Gencode/KO





cd ../OK
cd ../../..
./minicc Tests/Syntaxe/OK/minictestVerif.c
