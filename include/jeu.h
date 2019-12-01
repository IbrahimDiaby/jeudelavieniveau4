/** @file
 *	@brief Fonctions liées aux fonctionnements de jeu
 */
 #ifndef __JEU_H
#define __JEU_H

#include "grille.h"

/**
 * @brief modulo permettant de gérer les bordures des grilles
 * @param[in]  i abscisse/ordonnée variable
 * @param[in]  m maximum
 */
// modulo modifié pour traiter correctement les bords i=0 et j=0
// dans le calcul des voisins avec bords cycliques
static inline int modulo(int i, int m) {return (i+m)%m;}

/**
 * @brief calcul le nombre de voisins vivants cyclique
 * @param[in]  i abscisse
 * @param[in]  j ordonnée
 * @param[in] g grille
 * @param[out] nombre de voisins cycliques
 */
// compte le nombre de voisins vivants de la cellule (i,j)
// les bords sont cycliques.
int compte_voisins_vivants_cyclique(int i, int j, grille g);

/**
 * @brief calcul le nombre de voisins vivants non cyclique
 * @param[in]  i abscisse
 * @param[in]  j ordonnée
 * @param[in] g grille
 * @param[out] nombre de voisins cycliques
 */
int compte_voisins_vivants_non_cyclique (int i, int j, grille g);

/**
 * @brief evolution de grille et de cellule simultanemment
 * @param[in] g pointeur de grille
 * @param[in] gc pointeur de grille
 * @param[in] C pointeur de cellule
 * @param[in] (*compte_voisins_vivants)(int, int, grille) pointeur sur la fonction cyclique ou non cyclique
 * @param[in]  vieillissement : activé (1) / desactivé (0) 
 */
// fait évoluer la grille g d'un pas de temps
void evolue (grille *g, grille *gc, cellule *C,int (*compte_voisins_vivants) (int, int, grille), int vieillissement);

/**
 * @brief (*compte_voisins_vivants) (int, int, grille) pointeur sur la fonction cyclique ou non cyclique
 * @param[in] int abscisse
 * @param[in] int ordonnée
 * @param[in] grille grille
 * 
 */
// pointeur sur la fonction cyclique ou non cyclique
int (*compte_voisins_vivants) (int, int, grille);

#endif
