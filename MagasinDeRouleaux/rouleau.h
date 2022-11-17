/**
  @file rouleau.h
  @brief Déclaration de la classe Rouleau
  @version 1.1
  @author Philippe CRUCHET
  @date 13/10/2022
  */

#ifndef ROULEAU_H
#define ROULEAU_H
#include "libs.h"

using namespace std;

class Rouleau
{
private:
    /// Référence du rouleaux
    string reference ;
    /// Diamètre du rouleau
    int diametre ;
    /// Rangée de l'alvéole où se trouve le rouleau
    int rangee;
    /// Colonne de l'avéole où se trouve le rouleau
    int colonne ;
public:
    Rouleau(string _reference,const int _diametre) ;
    void AffecterAlveole(const int _rangee, const int _colonne) ;
    void ObtenirLocalisation(int &_rangee, int &_colonne);
    bool operator < (const Rouleau & _aComparer) const ;
    int operator -(const Rouleau & _aSoustraire) const;
    void Visualiser() const;
};

#endif // ROULEAU_H

