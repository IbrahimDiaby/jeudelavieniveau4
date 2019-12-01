/** @file
 *	@brief Fonctions liées aux grilles
 */

#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * @struct grille :
 * nbl : nombre de lignes
 * nbc : nombre de colonnes
 * cellules : tableau de tableau de cellules
 * @brief Grille du jeu
 */
// structure grille : nombre de lignes, nombre de colonnes, tableau de tableau de cellules
typedef struct {int nbl; int nbc; int** cellules;} grille;

/**
 * @struct cellule :
 * cellules : tableau de tableau de cellules
 * @brief Grille du jeu
 */
// structure cellule : tableau de tableau de cellules correspondant à l'age de la cellule
typedef struct {int** cellules;} cellule;
 
/**
 * @param[in]  l Nombre de lignes de la grille à allouer
 * @param[in]  c Nombre de colonnes de la grille à allouer
 * @param[out] g Pointeur sur la grille à allouer
 * @brief Alloue une grille de taille l*c, et initialise toutes les cellules à mortes
 */
// alloue une grille de taille l*c, et initialise toutes les cellules à mortes
void alloue_grille (int l, int c, grille* g);

/**
 * @param[in]  l Nombre de lignes de la grille à allouer
 * @param[in]  c Nombre de colonnes de la grille à allouer
 * @param[out] C Pointeur sur la cellule à allouer
 * @brief Alloue une cellule de taille l*c, et initialise toutes les cellules à mortes
 */
// alloue une cellule à travers une grille de taille l*c
void alloue_grille_cellule (int l, int c, cellule *C);

/**
 * @brief Libère une grille
 * @param[in] g Pointeur sur la grille à libérer
 */
// libère une grille
void libere_grille (grille* g);

/**
 * @brief Libère un tableau de tableau de cellule
 * @param[in] g Pointeur sur la grille afin de recuperer le nombre de ligne et de colonn afin de liberer
 * @param[in] c Pointeur sur la cellule à libérer
 * @param[out] g Pointeur sur la grille 
 */
// libère une cellule
void libere_cellule (grille *g, cellule* c);

/**
 * @brief Alloue et initalise la grille g à partir d'un fichier
 * @param[in]  filename Nom du fichier à partir du quel la grille doit être initialisée
 * @param[out] g        Grille à initialiser
 * @return              0 si aucune erreur lors de la lecture du fichier, 1 sinon
 */
// alloue et initalise la grille g à partir d'un fichier
void init_grille_from_file (char * filename, grille* g);


/**
 * @brief Rend vivante la cellule (i,j) de la grille g
 * @param[in]  i Ligne de la cellule
 * @param[in]  j Colonne de la cellule
 * @param[out] g Grille
 */
// rend vivante la cellule (i,j) de la grille g
static inline void set_vivante(int i, int j, grille g){g.cellules[i][j] = 1;}

/**
 * @brief Rend vivante la cellule (i,j) du tableau cellule
 * @param[in]  i Ligne de la cellule
 * @param[in]  j Colonne de la cellule
 * @param[out] c cellule
 */
// rend vivante la cellule (i,j) de la cellule c
static inline void set_vivante_cellule(int i, int j, cellule c){c.cellules[i][j] = 1;}

/**
 * @brief Rend morte la cellule (i,j) de la grille g
 * @param[in]  i Ligne de la cellule
 * @param[in]  j Colonne de la cellule
 * @param[out] g Grille
 */
// rend morte la cellule (i,j) de la grille g
static inline void set_morte(int i, int j, grille g){g.cellules[i][j] = 0;}

/**
 * @brief Rend morte la cellule (i,j) de la cellule c
 * @param[in]  i Ligne de la cellule
 * @param[in]  j Colonne de la cellule
 * @param[out] c cellule
 */
// rend morte la cellule (i,j) de la cellule c
static inline void set_morte_cellule(int i, int j, cellule c){c.cellules[i][j] = 0;}

/**
 * @brief Teste si la cellule (i,j) de la grille g est vivante
 * @param[in] i Abscisse de la cellule dans la grille
 * @param[in] j Ordonnée de la cellule dans la grille
 * @param[in] g Grille
 * @return      Booléen (0 ou 1) indiquant si la cellule est vivante ou non
 */
// teste si la cellule (i,j) de la grille g est vivante
static inline int est_vivante(int i, int j, grille g){return g.cellules[i][j] == 1;}

/**
 * @brief Rend non-viable la cellule (i,j) de la grille g
 * @param[in]  i Ligne de la cellule
 * @param[in]  j Colonne de la cellule
 * @param[out] g Grille
 */
// rend non viable la cellule (i,j) de la grille g est non viable
static inline void set_nonViable(int i, int j, grille g){g.cellules[i][j] = -1;}

/**
 * @brief Teste si la cellule (i,j) de la grille g est non-viable
 * @param[in] i Abscisse de la cellule dans la grille
 * @param[in] j Ordonnée de la cellule dans la grille
 * @param[in] g Grille
 * @return      Booléen (0 ou 1) indiquant si la cellule est non-viable ou non
 */
// teste si la cellule (i,j) de la grille g est non viable
static inline int est_nonViable(int i, int j, grille g){return g.cellules[i][j] == -1;}

/**
 * @brief Recopie gs dans gd (sans allocation)
 * @param[in]  gs Grille à copier
 * @param[out] gd Destination de la grille à copier
 */
// recopie gs dans gd (sans allocation)
void copie_grille (grille gs, grille gd);

/**
 * @brief Recopie gs dans c (sans allocation)
 * @param[in]  gs Grille à copier
 * @param[out] c Destination de la grille à copier
 */
// recopie gs dans c (sans allocation)
void copie_grille_cellule (grille gs, cellule c);

/**
 * @brief veillir les cellules de la grille g et de la cellule c
 * @param[in] i Abscisse de la cellule dans la grille et dans le tableau de tableau de cellule
 * @param[in] j Ordonnée de la cellule dans la grille  et dans le tableau de tableau de cellule
 * @param[in]  g Grille à copier
 * @param[in] c Destination de la grille à copier
 * @param[out]  g Grille à copier
 * @param[out] c Destination de la grille à copier
 */
// veillir la cellule : la cellule meurt si elle atteint 8 pas
void vieillir(int i,int j,grille g,cellule c);

#endif
