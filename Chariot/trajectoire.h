#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H
#include <iostream>
#include "element.h"

using namespace std;

class Trajectoire
{
private:
    Element **parcours; // crétion d'un tableau de pointeurs d'élements
    int nbEtapesMax; // nombre maxi etapes pour (tableau)
    int prochaineEtape; // prochaine case libre du tableau

public:
    Trajectoire(const int _nbEtapesMax);
    ~Trajectoire();
    bool Ajouter(Element *pElement); //bug lorsque (element *_pElement)
    void Afficher();
};

#endif // TRAJECTOIRE_H
