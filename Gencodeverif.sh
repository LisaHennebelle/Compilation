#!/usr/bin/env bash
# --------------------------Tests de syntaxe--------------------------------- #

#syntaxes de fonction avec arguments  :  #!/bin/bash
#                function e {
#                    echo $1
#                }
#                e Hello
#                e World
#                echo foo

cd Tests/Syntaxe/OK
#declaration des fichiers de tests et des hangements de caractères associes
declare -a tableau_indi=("minictest0.c" "minictest1.c" "minictest2.c" "minictest3.c" "minictest4.c")
declare -a tab_carac=("s/==/!=/g" "s/var1/carotte/g" "s/if/while/g" "s/true/false/g" "'1 i\if ((var1%2)== 0){ var2 = false; }'")
declare -a fichierref=("minictestSyntaxe.c")
echo "void main() {" > $fichierref[0]
echo "	int var1 = 0 ;" >> $fichierref[0]
echo "	bool var2 = true;" >> $fichierref[0]
echo "	if (var2 == true) {" >> $fichierref[0]
echo "	  var1 = 1;" >> $fichierref[0]
echo "	}" >> $fichierref[0]
echo "	print(var1);">> $fichierref[0]
echo "}" >> $fichierref[0]
more $fichierref[0]
#preciser le nombre de boucles à faire à l'appel de la fonction
echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification syntaxes OK /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
function bouclewhile {
	declare -i i=0
	#sed -i '1 i\int i;' $fichierref[0] #ajouter texte au dessus de ligne 1
	#more $fichierref[0]
	while [ $i -lt $1 ]
	do
    	# step 0
		cp --copy-contents $fichierref[0] ${tableau_indi[$i]}

		#step 1
        echo "minic test 0"
        echo ${tableau_indi[$i]}
		echo "sed -i ${tab_carac[$i]} ${tableau_indi[$i]}"
        sed -i ${tab_carac[$i]} ${tableau_indi[$i]}
        more ${tableau_indi[$i]}

		i=$[$i+1]
	done
}

#lancer la fonction sur 5 boucles :
bouclewhile 5

cd ../KO
echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification syntaxes KO /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
declare -a tableau_indi=("minictest0.c" "minictest1.c" "minictest2.c" "minictest3.c" "minictest4.c")
declare -a tab_carac=("s/==/!=/g" "s/var1/carotte/g" "s/if/while/g" "s/true/false/g" "1 i\if ((var1%2)== 0){ var2 = false; }")
declare -a fichierref=("../OK/minictestSyntaxe.c")

#modification du fichier de reference pour rendre sa syntaxe incorrecte
sed -i "s/=/%/g" $fichierref[0] $fichierref[0]


#preciser le nombre de boucles à faire à l'appel de la fonction
bouclewhile 5
# Tests de verification
cd ../../Verif/OK



cd ../KO

# Test de Gencode
cd ../../Gencode/KO

cd ../OK
cd ../../..
declare -i i=0
echo "Compilation des fichiers de verification OK"
while [ $i -lt 5 ]
do
        echo "**********************************************************"
		echo ${tableau_indi[$i]}
		echo "syntaxe ok"
        ./minicc -s Tests/Syntaxe/OK/${tableau_indi[$i]}
		echo "syntaxe ko"
		./minicc -s Tests/Syntaxe/KO/${tableau_indi[$i]}
		echo "**********************************************************"
		i=$[$i+1]
done
