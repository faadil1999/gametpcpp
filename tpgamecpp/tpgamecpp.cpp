// tpgamecpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CarteRoyaume.h"
#include "Carte.h"
#include "CarteTresor.h"
#include "CarteVictoire.h"
#include <vector>
#include <algorithm>
#include "PlateformeGame.h"

using namespace std;

int main()
{
    vector <Carte*>discard;
    vector <Carte*>trash;
    vector <Carte*>own_card;

  

    own_card.push_back(new CarteRoyaume());
    own_card.push_back(new CarteTresor(CarteTresor::OR));
    own_card.push_back(new CarteVictoire());
    own_card.push_back(new CarteRoyaume());
    own_card.push_back(new CarteVictoire());
    own_card.push_back(new CarteTresor(CarteTresor::ARGENT));
    own_card[5]->afficher();
    own_card.pop_back();
    
    own_card.back()->afficher();
    Joueur j1("SacreFaad");
    Joueur j2("Momohil");
/*    
    j1.carteMain();
    cout << "montrez tresor" << endl;
    j1.showcart_type_tresor();
    j1.addOntable(2);
    cout << "ajout sur table" << endl;
    j1.showcart_type_tresor();
    j1.addOntable(3);
    cout << "ajout sur table" << endl;
    cout << "dec" << endl;
    j1.showDeck();
    cout << "end deck" << endl;*/

    PlateformeGame::PhaseAchat(j1);
    PlateformeGame::PhaseAjustement(j1);
    PlateformeGame::PhaseAchat(j2);
    PlateformeGame::PhaseAjustement(j2);
    cout << "new deck" << endl;
    j1.showDeck();
    cout << "end new deck" << endl;
    cout << "Show discard" << endl;
    j1.showDiscard();
    cout << "main" << endl;
    j1.showcart_type_tresor();
   
    
    for (int i = 0; i < 9; i++) {
        if(i == 5)
        {
            
        }
    }



    cout << "Hello World!\n";
}

