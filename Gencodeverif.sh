#!/usr/bin/env bash
# -------------------------Creation des divers fichiers de test--------------------------------- #

declare -a tableau_indi=()
for i in {0..20}; do
	tableau_indi+=("minictest$i.c")
done
echo $tableau_indi
cd Tests/Syntaxe/OK
#declaration et ecriture d'un fichier de reference
declare -a fichierref=("minictestOriginal.c")
echo "void main() {" 							>  ${fichierref[0]}
echo "	int var1 = 15, i, nb = 0;" 				>> ${fichierref[0]}
echo "	int bin1 = 230, bin2 = 12, bin3;" 		>> ${fichierref[0]}
echo "	bool var2 = (true && false), booleen;" 	>> ${fichierref[0]}
echo "	if (var2 == true) {" 					>> ${fichierref[0]}
echo "		var1 = 1;" 							>> ${fichierref[0]}
echo "	}" 										>> ${fichierref[0]}
echo "	else {" 								>> ${fichierref[0]}
echo "		var1 = 2;" 							>> ${fichierref[0]}
echo "	}" 										>> ${fichierref[0]}
echo "	while(nb<=5){nb=nb+1;}" 				>> ${fichierref[0]}
echo "	bin1 = bin1 >> 2;" 						>> ${fichierref[0]}
echo "	bin3 = bin1 | bin2;" 					>> ${fichierref[0]}
echo "	bin2 = bin1 ^ bin3;" 					>> ${fichierref[0]}
echo "	booleen = !var2;" 						>> ${fichierref[0]}
echo "	for (i = 1; i < 5; i = i + 1)" 			>> ${fichierref[0]}
echo "	{var1 = var1+1;}" 						>> ${fichierref[0]}
echo "	print(var1);"							>> ${fichierref[0]}
echo "}" 										>> ${fichierref[0]}
#visualisation du fichier
more ${fichierref[0]}

function bouclewhile {
	declare -i i=0
	#sed -i '1 i\int i;' ${fichierref[0]} #ajouter texte au dessus de ligne 1
	#more ${fichierref[0]}
	while [ $i -lt $1 ]
	do
		# step 0
		cp --copy-contents ${fichierref[0]} ${tableau_indi[$i]}

		#step 1
	    sed -i ${tab_carac[$i]} ${tableau_indi[$i]} #sed -i "s/var1/tata/g" nom_fichiher

		i=$[$i+1]
	done
}


	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification syntaxes OK /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
	#declaration des fichiers de tests et des changements de caractères associes
	declare -a tab_carac=(	"s/==/!=/g"
	                        "s/var1/carotte/g"
	                        "s/==/||/g"
	                        "s/var1+1/var1%1/g"
	                        "s/var1+1/var1-1/g"
	                        "s/15/-15/g"
	                        "s/2/5/g"
	                        "s/i;/i=0;/g"
	                        "s/+1;/*45;/g"
	                        "s/>>/<</g"
	                        "s/>>/>>>/g"
	                        "s/while(nb<=5){nb=nb+1;}/do{nb=nb+1;}while(nb<=5);/g"
	                        "s/|/&/g"
	                        "s/nb<=5){nb=nb+1;}/nb>=5){nb=nb-1;}/g"
	                        )
	declare -i nbboucleSO=${#tab_carac[@]}

	#lancer la fonction pour chaque element de tab_carac:
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

	declare -a tab_carac=(	"s/==/eq/g"
	 						"s/var1/35/g"
							"s/if/&&/g"
							"s/2;/2/g"
							"s/5;/5/g"
							"s/15,/15/g"
							"s/;}/}/g"
							"s/+1;/}/g"
							"s/>>/></g"
							"s/else/els/g"
							"s/</<</g"
							"s/print/printf/g"
							"s/{nb=nb+1;}/do{nb=nb+1;}/g")

	declare -a fichierref=("minictestOriginal.c")
	declare -a fichiersrc=("../OK/minictestOriginal.c")
	cp --copy-contents ${fichiersrc[0]}  ${fichierref[0]} #copie du fichier de reference de Syntaxe ok à syntaxe ko
	declare -i nbboucleSK=${#tab_carac[@]}
	bouclewhile $nbboucleSK

	# Tests de verification
cd ../../Verif/OK
	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification verif OK /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
	sudo cp -r ../../Syntaxe/OK/* .
	declare -i nbboucleVO=$nbboucleSO

cd ../KO
	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* Verification verif KO /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*"
	declare -a fichierref=("minictestOriginal.c")
	declare -a fichiersrc=("../OK/minictestOriginal.c")
	declare -a tab_carac=(	"s/true/tru/g"
	 						"s/15/bin3/g"
							"s/true/1/g" )
	declare -i nbboucleVK=${#tab_carac[@]}

	cp --copy-contents ${fichiersrc[0]}  ${fichierref[0]} #copie du fichier de reference de Syntaxe ok à syntaxe ko
	#remplacage de caractères
	bouclewhile $nbboucleVK

	#modification du fichier de reference pour le rendre incorrect
	declare -i i=$nbboucleVK

	cp --copy-contents ${fichierref[0]}  ${tableau_indi[$nbboucleVK]}
	#creation de fichiers par ajout de lignes
	sed -i '7i\		if ((var1%2)== 0){ bin4 = false; }' ${tableau_indi[$nbboucleVK]} #redeclaration de var2
	#more ${tableau_indi[0]}
	nbboucleVK=$[$nbboucleVK+1]

	cp --copy-contents ${fichierref[0]}  ${tableau_indi[$nbboucleVK]}
	sed -i '7i\if ((var1%2)== 0){ var2 = 1; }' ${tableau_indi[$nbboucleVK]}
	#more ${tableau_indi[1]}
	nbboucleVK=$[$nbboucleVK+1]

	cp --copy-contents ${fichierref[0]}  ${tableau_indi[$nbboucleVK]}
	sed -i '7i\if ((var1%2)== 0){ bool var3 = var2 + 1; }' ${tableau_indi[$nbboucleVK]}
	#more ${tableau_indi[2]}
	nbboucleVK=$[$nbboucleVK+1]


# Test de Gencode
cd ../../Gencode/OK
	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/ Verification Gencode OK /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"
	sudo cp -r ../../Syntaxe/OK/* .
	declare -i nbboucleGO=$nbboucleSO

cd ../KO
	echo "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/ Verification Gencode KO /*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"

	declare -a fichierref=("minictestOriginal.c")
	declare -a fichiersrc=("../OK/minictestOriginal.c")
	declare -a tab_carac=(	"s/15/4294967295/g" #depassement de la memoire car manipulé par la suite
							"s/+1/+4294967295/g"
							"s/+1/*4294967295/g"
							"s/13;/0;/g" #division par 0
							"s/10;/0;/g") #modulo 0
	declare -i nbboucleGK=${#tab_carac[@]}

	cp --copy-contents ${fichiersrc[0]}  ${fichierref[0]} #copie du fichier de reference de Syntaxe ok à gencode ko
	#modification du fichier de reference pour le rendre incorrect
	cp --copy-contents ${fichierref[0]}  ${tableau_indi[$nbboucleGK]}
	sed -i '6 i\		int var4 =  var1 % 10; var1 = var1 / 13;' ${fichierref[0]}

	#lancer la fonction sur 5 boucles
	bouclewhile $nbboucleGK


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
	while [ $i -lt $nbboucleSK ]
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
	while [ $i -lt $nbboucleVO ]
	do
	        echo "**********************************************************"
			echo ${tableau_indi[$i]}
			echo "verif ok"
	        ./minicc -v Tests/Verif/OK/${tableau_indi[$i]} #appel avec l'option -v
			echo "**********************************************************"
			i=$[$i+1]
	done

#compilation des fichiers de Verif/KO
	declare -i i=0
	echo "Compilation des fichiers de verif KO"
	while [ $i -lt $nbboucleVK ]
	do
	        echo "**********************************************************"
			echo ${tableau_indi[$i]}
			echo "verif ko"
			more Tests/Verif/KO/${tableau_indi[$i]}
	        ./minicc -v Tests/Verif/KO/${tableau_indi[$i]} #appel avec l'option -v
			echo "**********************************************************"
			i=$[$i+1]
	done

#compilation des fichiers de Gencode/OK
	declare -i i=0
	echo "Compilation des fichiers de Gencode OK"
	while [ $i -lt $nbboucleGO ]
	do
	        echo "**********************************************************"
			echo ${tableau_indi[$i]}
			echo "gencode ok"
	        ./minicc Tests/Gencode/OK/${tableau_indi[$i]}
			echo "**********************************************************"
			i=$[$i+1]
	done
#compilation des fichiers de Gencode/KO
	declare -i i=0
	echo "Compilation des fichiers de Gencode KO"
	while [ $i -lt $nbboucleGK ]
	do
	        echo "**********************************************************"
			echo ${tableau_indi[$i]}
			echo "gencode ko"
			more Tests/Gencode/KO/${tableau_indi[$i]}
	        ./minicc Tests/Gencode/KO/${tableau_indi[$i]}
			echo "**********************************************************"
			i=$[$i+1]
	done
