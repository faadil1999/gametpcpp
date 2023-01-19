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
#include <map>


using namespace std;
int ip = 0;
int randomfunc(int j)
{
    return rand() % j;
}

void (*func)(int);

void funct(int op) {
    cout << "Faadil test " <<op<< endl;
}

void attribution(void(*functi)(int) , void(&funct2)(int) ,int op) {

    functi = &funct2;
    functi(op);
    
}
void func_vll(Joueur j, vector<Joueur*>list_joueur)
{

    PlateformeGame::setAction(2);

}

void modif (int *p ,int n_val)
{
    *p = n_val;
}

int main()
{
    int n = 25;
    int ip = 152;
    cout << ip << " " << ::ip << endl;
    int &re = n;
    int* p = &n;
    *p = 42;
    int poo = *p;
    re = 45;
    n = 88;
    modif(&n, 15000);
    cout << *p << endl;
    cout << re << endl;
    cout << poo << endl;
    int tab[] = {2 , 5 , 6 , 8 , 9};

    

    attribution(func, *funct,6);
    func = &funct;
   // func(6);
    cout << "nbr action avant execution " << PlateformeGame::getAction() << endl;
    vector<int>lis = vector<int>();
    for (int i = 0; i < 5; i++) {

        lis.push_back(i);
    }
   



    for(int i = 0 ;i <lis.size() ; i ++)
    {
        cout << lis[i] << endl;
    }
    cout << "effacement" << endl;
    lis.erase(lis.begin() + (2) ,lis.end() - (2));

    for (int i = 0; i < lis.size(); i++)
    {
        cout << lis[i] << endl;
    }

    Joueur *j3 = new Joueur("Fpo");
    Joueur *j4 = new Joueur("sadBoy");
    vector<Joueur*>listJ = vector<Joueur*>();
    listJ.push_back(j3);
    CarteRoyaume* cartv = new CarteRoyaume();
   
    cartv->attribute_fun(*func_vll , *j3);
  //  cartv->execute_action(*j3, listJ);
    cout << "nbr action apres execution " << PlateformeGame::getAction() << endl;
    system("pause");
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


    PlateformeGame::StartGame();

  
    cout << "new deck" << endl;
    j1.showDeck();
    cout << "end new deck" << endl;
    cout << "Show discard" << endl;
    j1.showDiscard();
    cout << "main" << endl;
    j1.showcart_type_tresor();
   
 



    cout << "Hello World!\n";
}

