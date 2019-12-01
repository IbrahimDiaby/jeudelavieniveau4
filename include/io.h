/** @file
 *	@brief Fonctions liées aux entrées et sorties 
*/
 #ifndef __IO_H
#define __IO_H

#include <stdio.h>
#include "grille.h"
#include "jeu.h"

/**
 * @brief affiche les traits 
 * @param[in]  c nombre de cellules du trait
 */
// affichage d'un trait horizontal
void affiche_trait (int c);

/**
 * @brief affiche les lignes
 * @param[in]  c nombre de cellules de la ligne
 * @param[in]  ligne pointeur de ligne
 * @param[in]  vieillissement : activé (1) / desactivé (0)
 */
// affichage d'une ligne de la grille
void affiche_ligne (int c, int* ligne, int veillissement);

/**
 * @brief affiche la grille ou l'age des cellules si le vieillissement est actif ou non
 * @param[in]  g grille
 * @param[in]  C cellule
 * @param[in]  compteur indiquant le nombre de pas
 * @param[in]  cyclique : activé (1) / desactivé (0)
 * @param[in]  vieillissement : activé (1) / desactivé (0) 
 */
// affichage d'une grille
void affiche_grille (grille g, cellule C, int compteur, int cyclique, int vieillissement);

/**
 * @brief efface la grille
 * @param[in]  g grille
 */
// effacement d'une grille
void efface_grille (grille g);

/**
 * @brief debut le jeu
 * @param[in]  g pointeur de grille
 * @param[in]  g pointeur de grille
 * @param[in]  C pointeur de cellule
 */
// debute le jeu
void debut_jeu(grille *g, grille *gc, cellule *C);

#endif
