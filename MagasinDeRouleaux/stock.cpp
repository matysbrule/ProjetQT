#include "stock.h"
#include "rouleau.h"
void Stock::AjouterRouleau(const Rouleau _nouveau)
{
    insert (_nouveau);
}
int Stock::RechercherSerie(POSITION_STOCK _positionDebut)
{
    POSITION_STOCK debutrouleau;
    POSITION_STOCK endrouleau = begin();
    _positionDebut = debutrouleau;
    int retour = size();
    if (retour >= 6){
    for (int i = 0; i < 6 ; i++)
    {
        endrouleau++;
    }
    retour = 6;
    int difference = *endrouleau - *debutrouleau;
    do {
        debutrouleau++;
        endrouleau++;
        int difference2 = *endrouleau - *debutrouleau;
        if (difference2 > difference)
        {
            _positionDebut = debutrouleau;
            difference2 = difference;
        }
    }
    while(endrouleau != end());
    }

    return retour;
}
void Stock::SortirRouleau(const POSITION_STOCK _positionRouleau)
{
    erase(_positionRouleau);
}
void Stock::Visualiser() const
{
    POSITION_STOCK it;
    for (it=begin();it != end(); it++)
    {
        it->Visualiser();
    }
}
