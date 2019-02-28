P4 : P4.o afficher_matrice.o hauteur_piece.o initialiser_matrice.o tour_joueur.o gagne.o
	gcc P4.o afficher_matrice.o hauteur_piece.o initialiser_matrice.o tour_joueur.o gagne.o -o P4

P4.o : P4.c
	gcc -c P4.c

afficher_matrice.o : afficher_matrice.c
	gcc -c afficher_matrice.c

hauteur_piece.o : hauteur_piece.c
	gcc -c hauteur_piece.c

initialiser_matrice.o : initialiser_matrice.c
	gcc -c initialiser_matrice.c

tour_joueur.o : tour_joueur.c
	gcc -c tour_joueur.c

gagne.o : gagne.c
	gcc -c gagne.c

clean :
	rm  *.o
