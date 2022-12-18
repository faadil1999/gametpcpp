#include <iostream>
#include "PlateformeGame.h"
#include "CarteTresor.h"
#include <vector>

using namespace std;
int PlateformeGame::nbr_achat = 1;
int PlateformeGame::nbr_action = 1;
int PlateformeGame::piece_posee = 0;
vector<Carte*> PlateformeGame::table_de_jeu = vector<Carte*>();
vector<CarteTresor*> PlateformeGame::pille_cuivre = vector<CarteTresor*>(46, new CarteTresor(CarteTresor::CUIVRE));
vector<CarteTresor*> PlateformeGame::pille_argent = vector<CarteTresor*>(40 , new CarteTresor(CarteTresor::ARGENT));
vector<CarteTresor*> PlateformeGame::pille_or = vector<CarteTresor*>(30, new CarteTresor(CarteTresor::OR));
vector<CarteVictoire*> PlateformeGame::pille_domaine = vector<CarteVictoire*>(8,new CarteVictoire(CarteVictoire::DOMAINE));
vector<CarteVictoire*> PlateformeGame::pille_duchet = vector<CarteVictoire*>(8,new CarteVictoire(CarteVictoire::DUCHET));
vector<CarteVictoire*> PlateformeGame::pille_province = vector<CarteVictoire*>(8,new CarteVictoire(CarteVictoire::PROVINCE));
vector<CarteVictoire*> PlateformeGame::pille_cursed = vector<CarteVictoire*>(8,new CarteVictoire(CarteVictoire::MALEDICTION));

PlateformeGame::PlateformeGame() {

	for (int i = 0; i < 30; i++) {
		pille_or.push_back(new CarteTresor(CarteTresor::OR));
	}

	for (int i = 0; i < 40; i++) {
		pille_or.push_back(new CarteTresor(CarteTresor::ARGENT));
	}

	for (int i = 0; i < 46; i++) {
		pille_or.push_back(new CarteTresor(CarteTresor::CUIVRE));
	}

	for (int i = 0; i < 8; i++) {
		pille_domaine.push_back(new CarteVictoire(CarteVictoire::DOMAINE));
		pille_duchet.push_back(new CarteVictoire(CarteVictoire::DUCHET));
		pille_province.push_back(new CarteVictoire(CarteVictoire::PROVINCE));
		pille_cursed.push_back(new CarteVictoire(CarteVictoire::MALEDICTION));
	}
}

void PlateformeGame::ajouterPiece(int value_coin) {

	piece_posee += value_coin;
}

void PlateformeGame::initialisationStatus() {
	nbr_achat = 1;
	nbr_action = 1;
	piece_posee = 0;
}

void PlateformeGame::increment_action() {
	nbr_action++;

}

void PlateformeGame::increment_achat() {
	nbr_achat++;

}

int PlateformeGame::getAction() {

	return nbr_action;
}

int PlateformeGame::getAchat() {
	return nbr_achat;
}
int PlateformeGame::getPiece() {
	return piece_posee;
}
void PlateformeGame::setAction(int nbr_ac) {
	nbr_action = nbr_ac;
}

void PlateformeGame::utiliserPiece(int piece) {

	piece_posee -= piece;
}


void PlateformeGame::decrement_action() {
	if (nbr_action == 0) {
		cerr << "Error";

	}
	else {
		nbr_action--;
	}


}

void PlateformeGame::decrement_achat() {
	if (nbr_achat == 0) {

		cerr << "Error" << endl;
	}
	else {

		nbr_achat--;
	}

}
void PlateformeGame::PhaseAchat(Joueur &joueur)
{

	int choix = 1;
	cout << "Phase Achat" << endl;
	
	do {
		cout << "Faites le choix de la carte que vous voulez poser sur la table \n";
		
		joueur.showcart_type_tresor();
		if(joueur.hasTresor() ) {
			cout << "Entrez 90 pour passer cette etape \n";
			cin >> choix;
			if(choix <90 ) {
				if (joueur.isTresor(choix)) 
				{

					joueur.addOntable(choix);
				}
				else {
					cout << "Cette carte nest pas une carte tresor \n";
				}
			}
			else if (choix >90) {
				cout << "Hors sujet mais on passera a letape suivante \n";
				break;
			}
			else{
				cout << "On passe a letape suivante \n";
			}
		}
	
	
	} while (joueur.hasTresor());
	choix = 0;
	
	cout << "Quel type de carte voulez vous acheter\n";
	cout << "1-) Pour les cartes de type tresor \n";
	cout << "2-) Pour les cartes de type royaume \n";
	cout << "3-) Pour les cartes de type victoire \n";
	cin >> choix;
	switch (choix)
	{
	case 1:
		PlateformeGame::achatCarteTresor(joueur);
		break;
	case 2:
		PlateformeGame::achatCarteRoyaume(joueur);
		break;
	case 3:
		PlateformeGame::achatCarteVictoire(joueur);
		break;
	case 0:
		cout << "Vous avez passer cette etape \n";
		break;
	default:
		cout << "Mauvais numero de choix \n";
		break;
	}


}

void PlateformeGame::putonHand(Joueur &joueur , Carte &carte)
{
	joueur.addCardOnHand(carte);
}

void PlateformeGame::setTableJeu(Carte &carte)
{
	carte.effect_card();
	table_de_jeu.push_back(&carte);
	
}

void PlateformeGame:: achatCarteTresor(Joueur& joueur)
{
	int choix = 0;

	if (PlateformeGame::nbr_achat >= pille_or.back()->getCarteCost())
	{
		cout << "1-) Pour acheter un cuivre " << endl;
		cout << "2-) Pour acheter un argent " << endl;
		cout << "3-) Pour acheter un or " << endl;
		
	}
	else if (PlateformeGame::nbr_achat >= pille_argent.back()->getCarteCost() && PlateformeGame::nbr_achat < pille_or.back()->getCarteCost())
	{
		cout << "1-) Pour acheter une malediction " << endl;
		cout << "2-) Pour acheter un domaine " << endl;
		cout << "3-) Pour acheter un duchet " << endl;
	}
	else
	{
		cout << "1-) Pour acheter un cuivre" << endl;

	}
	cout << "90-) Pour passer cette etape \n";
	cout << "0-) Retour\n";
	cout << "Faites votre choix " << endl;
	cin >> choix;

	switch (choix)
	{
	case 1:
		putonHand(joueur, *pille_cuivre.back());

		pille_cuivre.pop_back();
		cout << "Vous avez acheter une carte cuivre" << endl;
		break;

	case 2:
		if (PlateformeGame::nbr_achat >= pille_argent.back()->getCarteCost()) {

			putonHand(joueur, *pille_argent.back());
			pille_argent.pop_back();
			cout << "Vous avez acheter une carte domaine" << endl;

		}
		else {
			cout << "Error" << endl;
			cout << "Faite choix moins couteux " << endl;
		}
		break;
	case 3:
		if (PlateformeGame::nbr_achat >= pille_or.back()->getCarteCost()) {

			putonHand(joueur, *pille_or.back());
			pille_or.pop_back();
			cout << "Vous avez acheter une carte duchet" << endl;
		}
		else {
			cout << "Error" << endl;
			cout << " Faites un achat moins couteux " << endl;
		}
		break;
	case 90:
		cout << "Vous avez passez cette etape" << endl;
		break;
	case 0:
		PlateformeGame::PhaseAchat(joueur);
		break;
	default:
		break;
	}

	
}

void PlateformeGame::achatCarteRoyaume(Joueur& joueur)
{



}

void PlateformeGame::achatCarteVictoire(Joueur &joueur)
{
	int choix = 0;

	if (PlateformeGame::nbr_achat >= pille_province.back()->getCarteCost())
	{
		cout << "1-) Pour acheter une malediction " << endl;
		cout << "2-) Pour acheter un domaine " << endl;
		cout << "3-) Pour acheter un duchet " << endl;
		cout << "4-) pour acheter une province " << endl;
	}
	else if (PlateformeGame::nbr_achat >= pille_duchet.back()->getCarteCost() && PlateformeGame::nbr_achat < pille_province.back()->getCarteCost())
	{
		cout << "1-) Pour acheter une malediction " << endl;
		cout << "2-) Pour acheter un domaine " << endl;
		cout << "3-) Pour acheter un duchet " << endl;
	}
	else if (PlateformeGame::nbr_achat >= pille_domaine.back()->getCarteCost() && PlateformeGame::nbr_achat < pille_duchet.back()->getCarteCost()) {

		cout << "2-) Pour acheter un domaine " << endl;
		cout << "3-) Pour acheter un duchet " << endl;
	}
	else
	{
		cout << "1-) Pour acheter une malediction " << endl;

	}

	cout << "Faites votre choix " << endl;
	cin >> choix;

	switch (choix)
	{
	case 1:
		putonHand(joueur, *pille_cursed.back());

		pille_cursed.pop_back();
		cout << "Vous avez acheter une carte malediction" << endl;
		break;

	case 2:
		if (PlateformeGame::nbr_achat >= pille_domaine.back()->getCarteCost()) {

			putonHand(joueur, *pille_domaine.back());
			pille_domaine.pop_back();
			cout << "Vous avez acheter une carte domaine" << endl;

		}
		else {
			cout << "Error" << endl;
			cout << "Faite choix moins couteux " << endl;
		}
		break;
	case 3:
		if (PlateformeGame::nbr_achat >= pille_duchet.back()->getCarteCost()) {

			putonHand(joueur, *pille_duchet.back());
			pille_duchet.pop_back();
			cout << "Vous avez acheter une carte duchet" << endl;
		}
		else {
			cout << "Error" << endl;
			cout << " Faites un achat moins couteux " << endl;
		}
		break;
	case 4:
		if (PlateformeGame::nbr_achat >= pille_province.back()->getCarteCost())
		{
			putonHand(joueur, *pille_province.back());
			pille_province.pop_back();
			cout << "Vous avez acheter une carte province" << endl;
		}
		else {
			cout << "Error";
			cout << " Faites un achat moins couteux " << endl;
		}

		break;
	case 0:
		PlateformeGame::PhaseAchat(joueur);
		break;
	default:
		break;
	}
}

void PlateformeGame::StartGame()
{
	for (int i = 0; i < 30; i++) {
		pille_or.push_back(new CarteTresor(CarteTresor::OR));
	}

	for (int i = 0; i < 40; i++) {
		pille_or.push_back(new CarteTresor(CarteTresor::ARGENT));
	}

	for (int i = 0; i < 46; i++) {
		pille_or.push_back(new CarteTresor(CarteTresor::CUIVRE));
	}

	for (int i = 0; i < 8; i++) {
		pille_domaine.push_back(new CarteVictoire(CarteVictoire::DOMAINE));
		pille_duchet.push_back(new CarteVictoire(CarteVictoire::DUCHET));
		pille_province.push_back(new CarteVictoire(CarteVictoire::PROVINCE));
		pille_cursed.push_back(new CarteVictoire(CarteVictoire::MALEDICTION));
	}

}



void PlateformeGame::PhaseAjustement(Joueur &joueur)
{
	
	joueur.setDiscard(table_de_jeu);
	initialisationStatus();

}
