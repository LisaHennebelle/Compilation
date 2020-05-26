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
	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification syntaxes OK /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
	#declaration des fichiers de tests et des changements de caractères associes
	declare -a tableau_indi=("minictest0.c" "minictest1.c" "minictest2.c" "minictest3.c" "minictest4.c" "minictest5.c" "minictest6.c" "minictest7.c" "minictest8.c" "minictest9.c" "minictest10.c" "minictest11.c" "minictest12.c" "minictest13.c" "minictest14.c""minictest15.c" "minictest16.c" "minictest17.c" "minictest18.c" "minictest19.c" "minictest20.c" "minictest21.c" "minictest22.c" "minictest23.c" "minictest24.c")
	declare -a tab_carac=("s/==/!=/g" "s/var1/carotte/g" "s/==/||/g" "s/var1+1/var1%1/g" "s/var1+1/var1-1/g" "s/15/-15/g" "s/2/5/g" "s/i;/i=0;/g"  )
	#declaration et ecriture d'un fichier de reference
	declare -a fichierref=("minictestSyntaxe.c")
	echo "void main() {" > ${fichierref[0]}
	echo "	int var1 = 15, i;" >> ${fichierref[0]}
	echo "	bool var2 = true;" >> ${fichierref[0]}
	echo "	if (var2 == true) {" >> ${fichierref[0]}
	echo "	  var1 = 1;" >> ${fichierref[0]}
	echo "	}" >> ${fichierref[0]}
	echo "	else {" >> ${fichierref[0]}
	echo "	  var1 = 2;" >> ${fichierref[0]}
	echo "	}" >> ${fichierref[0]}
	echo "	for (i = 1; i < 5; i = i + 1)" >> ${fichierref[0]}
	echo "	{var1 = var1+1;}" >> ${fichierref[0]}
	echo "	print(var1);">> ${fichierref[0]}
	echo "}" >> ${fichierref[0]}
	#visualisation du fichier
	more ${fichierref[0]}


	function bouclewhile {
		declare -i i=0
		#sed -i '1 i\int i;' ${fichierref[0]} #ajouter texte au dessus de ligne 1
		#more ${fichierref[0]}
		while [ $i -lt $1 ]
		do
	    	# step 0
			echo "cp --copy-contents ${fichierref[0]} ${tableau_indi[$i]}"
			cp --copy-contents ${fichierref[0]} ${tableau_indi[$i]}

			#step 1
	        echo "minic test 0"
	        echo ${tableau_indi[$i]}
			echo "sed -i ${tab_carac[$i]} ${tableau_indi[$i]}"
	        sed -i ${tab_carac[$i]} ${tableau_indi[$i]} #sed -i "s/var1/tata/g" nom_fichiher

			i=$[$i+1]
			ls
		done
	}

	#lancer la fonction sur 7 boucles :
	declare -i nbboucleSO=8
	bouclewhile $nbboucleSO

	#ajout de lignes

	cp --copy-contents ${fichierref[0]} ${tableau_indi[$nbboucleSO]}
	sed -i '7i\		if ((var1%2)== 0){ var2 = false; }' ${tableau_indi[$nbboucleSO]}
	nbboucleSO=$[$nbboucleSO+1]
	cp --copy-contents ${fichierref[0]} ${tableau_indi[$nbboucleSO]}
	sed -i '1i\int var3 = 15;' ${tableau_indi[$nbboucleSO]} #  declaration globale avant le main
	nbboucleSO=$[$nbboucleSO+1]

cd ../KO
	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification syntaxes KO /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
	#declare -a tableau_indi=("minictest0.c" "minictest1.c" "minictest2.c" "minictest3.c" "minictest4.c")
	declare -a tab_carac=("s/==/eq/g" "s/var1/35/g" "s/if/&&/g" "s/2;/2/g" "s/5;/5/g" "s/15/false/g" "s/;}/}/g")
	declare -a fichierref=("minictestSyntaxe.c")
	declare -a fichiersrc=("../OK/minictestSyntaxe.c")
	#modification du fichier de reference pour rendre sa syntaxe incorrecte
	cp --copy-contents ${fichiersrc[0]}  ${fichierref[0]} #copie du fichier de reference de Syntaxe ok à syntaxe ko
	#sed -i "s/=/%/g" ${fichierref[0]} ${fichierref[0]}
	#lancer la fonction sur 5 boucles
	bouclewhile 7
	# Tests de verification
cd ../../Verif/OK
	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification verif OK /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
	sudo cp -r ../../Syntaxe/OK/* .
	echo "../../Syntaxe/OK/* "
	ls ../../Syntaxe/OK/*
	pwd
	ls
cd ../KO
	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification verif KO /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
	declare -a fichierref=("minictestVerif.c")
	declare -a fichiersrc=("../OK/minictestSyntaxe.c")
	#modification du fichier de reference pour le rendre incorrect
	declare -i i=0

	cp --copy-contents ${fichiersrc[0]}  ${fichierref[0]} #copie du fichier de reference de Syntaxe ok à syntaxe ko
	cp --copy-contents ${fichierref[0]}  ${tableau_indi[$i]}
	sed -i '7i\if ((var1%2)== 0){ bool var2 = false; }' ${tableau_indi[$i]} #redeclaration de var2
	more ${fichierref[0]}
	i=$[$i+1]
	cp --copy-contents ${fichierref[0]}  ${tableau_indi[$i]}#copie du fichier de reference de Syntaxe ok à syntaxe ko
	sed -i '7i\if ((var1%2)== 0){ var2 = 1; }' ${tableau_indi[$i]} #redeclaration de var2
	i=$[$i+1]
	cp --copy-contents ${fichierref[0]}  ${tableau_indi[$i]} #copie du fichier de reference de Syntaxe ok à syntaxe ko
	sed -i '7i\if ((var1%2)== 0){ bool var3 = var2 + 1; }' ${tableau_indi[$i]} #redeclaration de var2
	i =$[$i+1]
	cp --copy-contents ${fichierref[0]}  ${tableau_indi[$i]}
	sed -i "s/true/tru/g" ${tableau_indi[$i]} #remplacement de true par un string


# Test de Gencode
cd ../../Gencode/OK
	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification Gencode OK /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
	sudo cp -r ../../Syntaxe/OK/* .
	pwd
	ls

cd ../KO
	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification Gencode KO /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
	declare -a tab_carac=("s/15/4294967295/g" "s/var1/carotte/g" "s/if/while/g" "s/3/0/g" "s/10/0/g")
	declare -a fichierref=("minictestVerif.c")
	declare -a fichiersrc=("../OK/minictestSyntaxe.c")
	#modification du fichier de reference pour le rendre incorrect
	cp --copy-contents ${fichiersrc[0]}  ${fichierref[0]} #copie du fichier de reference de Syntaxe ok à syntaxe ko
	sed -i '7i\if ((var1%2)== 0){ var 1 = 3 % 10; }' ${fichierref[0]}
	more ${fichierref[0]}
	#lancer la fonction sur 5 boucles
	bouclewhile 5
	sed -i '7i\	var 1 = 3 / 0' ${tableau_indi[4]}

cd ../../.. # retour au dossier source de Tests
# --------------------------------------------------COMPILATION ----------------------------------------#
make realclean
make # mettre à jour le compilateur minicc
#test des différentes options sans compilation
./minicc -b
./minicc -h
#compilation des fichiers dans syntaxe/ok
	declare -i i=0
	echo "Compilation des fichiers de syntaxe OK"
	while [ $i -lt $nbboucleSO ]
	do
	        echo "**********************************************************"
			echo ${tableau_indi[$i]}
			echo "syntaxe ok"
			more Tests/Syntaxe/OK/${tableau_indi[$i]}
	        ./minicc -s Tests/Syntaxe/OK/${tableau_indi[$i]}
			echo "**********************************************************"
			i=$[$i+1]
	done

#compilation des fichiers de syntaxe/ko
	declare -i i=0
	echo "Compilation des fichiers de syntaxe KO"
	while [ $i -lt 5 ]
	do
	        echo "**********************************************************"
			echo ${tableau_indi[$i]}
			echo "syntaxe ko"
			more Tests/Syntaxe/KO/${tableau_indi[$i]}
			./minicc  -s  Tests/Syntaxe/KO/${tableau_indi[$i]} #appel avec l'option -s
			echo "**********************************************************"
			i=$[$i+1]
	done

#compilation des fichiers de Verif/OK
	declare -i i=0
	echo "Compilation des fichiers de verif OK"
	while [ $i -lt 5 ]
	do
	        echo "**********************************************************"
			echo ${tableau_indi[$i]}
			echo "syntaxe ok"
	        ./minicc -v Tests/Verif/OK/${tableau_indi[$i]} #appel avec l'option -v
			echo "**********************************************************"
			i=$[$i+1]
	done

#compilation des fichiers de Verif/KO
	declare -i i=0
	echo "Compilation des fichiers de verif KO"
	while [ $i -lt 5 ]
	do
	        echo "**********************************************************"
			echo ${tableau_indi[$i]}
			echo "syntaxe ok"
	        ./minicc -v Tests/Verif/KO/${tableau_indi[$i]} #appel avec l'option -v
			echo "**********************************************************"
			i=$[$i+1]
	done

#compilation des fichiers de Gencode/OK
	declare -i i=0
	echo "Compilation des fichiers de GEncode OK"
	while [ $i -lt 5 ]
	do
	        echo "**********************************************************"
			echo ${tableau_indi[$i]}
			echo "syntaxe ok"
	        ./minicc Tests/Gencode/OK/${tableau_indi[$i]}
			echo "**********************************************************"
			i=$[$i+1]
	done
#compilation des fichiers de Gencode/KO
	declare -i i=0
	echo "Compilation des fichiers de Gencode KO"
	while [ $i -lt 5 ]
	do
	        echo "**********************************************************"
			echo ${tableau_indi[$i]}
			echo "syntaxe ok"
	        ./minicc Tests/Gencode/KO/${tableau_indi[$i]}
			echo "**********************************************************"
			i=$[$i+1]
	done
