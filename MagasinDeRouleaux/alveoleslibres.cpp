#include "alveoleslibres.h"

Alveoleslibres::Alveoleslibres(const int _nbRangees, const int _nbColonnes):
    nbRangees(_nbRangees),
    nbColonnes(_nbColonnes)
{
    for (int i = 1; i <= nbRangees*nbColonnes; i++ )
    {
        push_back(i);
    }
}
bool Alveoleslibres::Reserver(int _rangee, int _colonne)
{
    bool retour = true;
    if (empty())
    {
        retour = false;
    }
    else
    {
        int numAlve = back();
        _rangee = ((numAlve-1)/nbColonnes)+1;
        _colonne = ((numAlve-1)%nbColonnes)+1;
        pop_back();
    }
    return retour;
}
bool Alveoleslibres::Liberer(const int _rangee, const int _colonne)
{
    bool retour = true;
    if (_rangee * _colonne == nbRangees * nbColonnes)
    {
        retour = false;
    }else{
        push_back((_rangee -1) *nbColonnes +_colonne);
    }
    return retour;
}
void Alveoleslibres::Visualiser()
{
    vector<int>::iterator it;
    for (it=begin();it != end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
