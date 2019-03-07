P4 : P4.o afficher_matrice.o hauteur_piece.o initialise.o tour_joueur.o gagne.o
	gcc P4.o afficher_matrice.o hauteur_piece.o initialise.o tour_joueur.o gagne.o -o P4

P4.o : SRC/P4.c
	gcc -c SRC/P4.c

afficher_matrice.o : SRC/afficher_matrice.c
	gcc -c SRC/afficher_matrice.c

hauteur_piece.o : SRC/hauteur_piece.c
	gcc -c SRC/hauteur_piece.c

initialise.o : SRC/initialise.c
	gcc -c SRC/initialise.c

tour_joueur.o : SRC/tour_joueur.c
	gcc -c SRC/tour_joueur.c

gagne.o : SRC/gagne.c
	gcc -c SRC/gagne.c

clean :
	rm  *.o
