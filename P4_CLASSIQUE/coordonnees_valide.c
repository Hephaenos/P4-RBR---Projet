#include <stdio.h>
#include <stdlib.h>

int coordonnees_valides(int coord, int mat[L][C]){
	int x=5;											// x est la taille de notre matrice

	return ((coord<1 || coord>C) && colonne_pleine(coord,mat));	// on teste si le joueur met sa piece dans la matrice et si la colonne n'est pas pleine
}