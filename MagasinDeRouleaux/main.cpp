#include "menu.h"
#include "stock.h"
#include "rouleau.h"
enum CHOIX_MENU
{
    Ajouter_un_Rouleau =1,
    Rechercher_une_serie_de_rouleau = 2,
    Sortir_un_rouleau = 3,
    Visualiser = 4,
    Quitter = 5,
};
Rouleau *lesRouleaux;
Stock leStock;
int main()
{ try {
        int choix;
        float diametre;
        string reference;
        string nouveau;
        int nbrouleau;
        Stock::POSITION_STOCK positionDebut;
        Menu leMenu("../testalveoleslibres/rouleau.txt");
        do {
            choix = leMenu.Afficher();
            switch (choix){
            case Ajouter_un_Rouleau:
                system("clear");
                cout << "Vous avez choisi d'ajouter un rouleau" << endl;
                cout << "veuillez saisir le diamètre du rouleau : " << endl;
                cin >> diametre;
                system("clear");
                cout << "veuillez saisir la reference : "<< endl;
                cin >>nouveau;
                cout << "le rouleau a bien été ajouter au stock." << endl;
                lesRouleaux = new Rouleau(reference, diametre);
                leStock.AjouterRouleau(*lesRouleaux);
                system("clear");
                Menu::AttendreAppuiTouche();
                choix = leMenu.Afficher();
                break;
            case Rechercher_une_serie_de_rouleau:
                system("clear");
                cout << "entrer la reference du rouleau que vous souhaitez : "<< endl;
                cin >> reference;
                system("clear");
                lesRouleaux->Visualiser();
                Menu::AttendreAppuiTouche();
                choix = leMenu.Afficher();
                break;
            case Sortir_un_rouleau :
                system("clear");
                nbrouleau = leStock.RechercherSerie(positionDebut);
                for (int i = 0; i < nbrouleau ; nbrouleau++)
                {
                    positionDebut->Visualiser();
                    leStock.SortirRouleau(positionDebut++);
                }
                system("clear");
                Menu::AttendreAppuiTouche();
                choix = leMenu.Afficher();
                break;
            case Visualiser :
                cout << "vous avez choisi de visualiser les rouleaux."<< endl;
                leStock.Visualiser();
                Menu::AttendreAppuiTouche();
                leStock.Visualiser();
                //choix = leMenu.Afficher();
                break;
            case Quitter :
                system("clear");
                cout << "vous allez quitter le menu."<< endl;
                system("clear");
                return 0;
                break;
            }}while(1);} catch (runtime_error &e){}return 0;}
