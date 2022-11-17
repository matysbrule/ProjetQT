#ifndef STOCK_H
#define STOCK_H
#include "libs.h"
#include "rouleau.h"
#include "alveoleslibres.h"

class Stock : public multiset <Rouleau>
{
public:
    typedef Stock::iterator POSITION_STOCK;
    void AjouterRouleau(const Rouleau _nouveau);
    int RechercherSerie(POSITION_STOCK _positionDebut);
    void SortirRouleau(const POSITION_STOCK _positionRouleau);
    void Visualiser() const;
private :
};

#endif // STOCK_H
