#include <stdlib.h>
#include <stdio.h>

//La fontion permet de définir le nombre de joueurs qui vont faire la partie
int nb_joueurs(int n){
	printf("Saisir le nombre de joueurs (min = 2, max = 8: \n");
	scanf("%i",&n);
	return n;
}