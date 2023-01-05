#include <iostream>
#include "PlateformeGame.h"
#include "CarteTresor.h"
#include <vector>


using namespace std;

void func_village(Joueur j, vector<Joueur*>list_joueur)
{

	PlateformeGame::setAction(2);

}

int PlateformeGame::nbr_achat = 1;
int PlateformeGame::nbr_action = 1;
int PlateformeGame::piece_posee = 0;
vector<Joueur*> PlateformeGame::m_list_joueur = vector<Joueur*>();
Joueur* PlateformeGame::joueur_actuel = new Joueur("premier");
 unsigned short PlateformeGame::end_game = 0;
vector<Carte*> PlateformeGame::table_de_jeu = vector<Carte*>();
vector<CarteTresor*> PlateformeGame::pille_cuivre = vector<CarteTresor*>(47, new CarteTresor(CarteTresor::CUIVRE));
vector<CarteTresor*> PlateformeGame::pille_argent = vector<CarteTresor*>(41 , new CarteTresor(CarteTresor::ARGENT));
vector<CarteTresor*> PlateformeGame::pille_or = vector<CarteTresor*>(31, new CarteTresor(CarteTresor::OR));
vector<CarteVictoire*> PlateformeGame::pille_domaine = vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::DOMAINE));
vector<CarteVictoire*> PlateformeGame::pille_duchet = vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::DUCHET));
vector<CarteVictoire*> PlateformeGame::pille_province = vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::PROVINCE));
vector<CarteVictoire*> PlateformeGame::pille_cursed = vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::MALEDICTION));
vector<CarteRoyaume*> PlateformeGame::carte_royaume_1 = 
vector<CarteRoyaume*>(5,new CarteRoyaume( 10,"Village" , CarteRoyaume::TypeRoyaume::ACTION_ACTION , func_village));
vector<CarteRoyaume*> PlateformeGame::carte_royaume_2 =
vector<CarteRoyaume*>(5, new CarteRoyaume(10, "Marchee", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));
vector<CarteRoyaume*> PlateformeGame::carte_royaume_3 =
vector<CarteRoyaume*>(5, new CarteRoyaume(10, "Bucheron", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));


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
void PlateformeGame::incrementEndGame() {
	end_game++;
}

Joueur & PlateformeGame::getActuelJoueur()
{
	return *joueur_actuel;
}
vector<Joueur*> PlateformeGame::getListJoueur()
{

	return m_list_joueur;
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
	cout << "Joueur :" <<joueur.getPseudo() << endl;
	cout << "Phase Achat" << endl;
	showCurrentStatus();
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
					showCurrentStatus();
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
	if (carte.getCardType() == Carte::VICTOIRE) {
		
		CarteVictoire& carte_v = dynamic_cast<CarteVictoire&>(carte);
		
		carte_v.effect_card(joueur);
	
	}
	else {
		joueur.addCardOnHand(carte);
	}
	
}

void PlateformeGame::setTableJeu(Carte &carte)
{
	carte.effect_card();
	table_de_jeu.push_back(&carte);
	if(carte.getCardType() == Carte::TypeCarte::ROYAUME)
	{//if the type of the card is Royaume we will cast it so that we will use the function execute_action
		CarteRoyaume& carte_r = dynamic_cast<CarteRoyaume&>(carte);
		carte_r.execute_action(PlateformeGame::getActuelJoueur()  , PlateformeGame::getListJoueur());
	}

}

void PlateformeGame:: achatCarteTresor(Joueur& joueur)
{
	int choix = 0;
	
	if (PlateformeGame::piece_posee >= pille_or.back()->getCarteCost())
	{
		cout << "1-) Pour acheter un cuivre " << endl;
		cout << "2-) Pour acheter un argent " << endl;
		cout << "3-) Pour acheter un or " << endl;
		
	}
	else if (PlateformeGame::piece_posee >= pille_argent.back()->getCarteCost() && PlateformeGame::piece_posee < pille_or.back()->getCarteCost())
	{
		cout << "1-) Pour acheter un cuivre " << endl;
		cout << "2-) Pour acheter un argent " << endl;
		
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
		if (PlateformeGame::piece_posee >= pille_argent.back()->getCarteCost()) {

			if (pille_argent.size() == 1) {
				cout << "Petit malin !! cette pille de carte est vide" << endl;
			}
			else {
				putonHand(joueur, *pille_argent.back());
				pille_argent.pop_back();
				cout << "Vous avez acheter une carte argent" << endl;
			}
		
		}
		else {
			cout << "Error" << endl;
			cout << "Faite choix moins couteux " << endl;
		}
		break;
	case 3:
		if (PlateformeGame::piece_posee >= pille_or.back()->getCarteCost()) {
			if (pille_or.size() == 1) {
				cout << "Petit malin !! cette pille de carte est vide" << endl;
			}
			else {
				putonHand(joueur, *pille_or.back());
				pille_or.pop_back();
				cout << "Vous avez acheter une carte or" << endl;
			}
			
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

void PlateformeGame:: achatCarteRoyaume(Joueur &joueur)
{
	int choix = 0;
	cout << "Faites un choix" << endl;
	cout << "Pour retourner en arriere" << endl;
	cout << carte_royaume_1.back()->getCarteCost() << endl;
	cout << piece_posee << endl;
	
	if (3 > 0 )
	{
		cout << messageMenuForCardIfEmptyOrNot(carte_royaume_1.size(), *carte_royaume_1.back(), "1-) Pour acheter la carte " + carte_royaume_1.back()->getName())<<endl;
	}


	cin >> choix;
	
	messageMenuForCardIfEmptyOrNot(carte_royaume_2.size(), *carte_royaume_2.back(), "2-) Pour acheter la carte " + carte_royaume_2.back()->getName() );
	messageMenuForCardIfEmptyOrNot(carte_royaume_3.size(), *carte_royaume_3.back(), "3-) Pour acheter la carte " + carte_royaume_3.back()->getName());
	switch (choix)
	{
	case 1:
		putonHand(joueur, *carte_royaume_1.back());
			carte_royaume_1.pop_back();
			cout << "carte " + carte_royaume_1.back()->getName() + " achetee" << endl;
		break;
	case 0:
		PlateformeGame::PhaseAchat(joueur);
		break;
	default:
		break;
	}


}

void PlateformeGame::showCurrentStatus()
{
	cout << "Action: " << nbr_action << endl;
	cout << "Piece: " << piece_posee << endl;

}



void PlateformeGame::achatCarteVictoire(Joueur &joueur)
{
	int choix = 0;

	if (PlateformeGame::piece_posee >= pille_province.back()->getCarteCost())
	{
		cout << messageMenuForCardIfEmptyOrNot(pille_cursed.size(),*pille_cursed.back(), "1-) Pour acheter une malediction ") << endl;
		cout << messageMenuForCardIfEmptyOrNot(pille_domaine.size(), *pille_domaine.back(), "2-) Pour acheter un domaine ") << endl;
		cout << messageMenuForCardIfEmptyOrNot(pille_duchet.size(), *pille_duchet.back(), "3-) Pour acheter un duchet ") << endl;
		cout << messageMenuForCardIfEmptyOrNot(pille_province.size(), *pille_province.back(), "4-) pour acheter une province ") << endl;
	}
	else if (PlateformeGame::piece_posee >= pille_duchet.back()->getCarteCost() && PlateformeGame::piece_posee < pille_province.back()->getCarteCost())
	{

		cout << messageMenuForCardIfEmptyOrNot(pille_cursed.size(), *pille_cursed.back(), "1-) Pour acheter une malediction ") << endl;
		cout << messageMenuForCardIfEmptyOrNot(pille_domaine.size(), *pille_domaine.back(), "2-) Pour acheter un domaine ") << endl;
		cout << messageMenuForCardIfEmptyOrNot(pille_duchet.size(), *pille_duchet.back(), "3-) Pour acheter un duchet ") << endl;
	}
	else if (PlateformeGame::piece_posee >= pille_domaine.back()->getCarteCost() && PlateformeGame::piece_posee < pille_duchet.back()->getCarteCost()) {

		cout << messageMenuForCardIfEmptyOrNot(pille_cursed.size(), *pille_cursed.back(), "1-) Pour acheter une malediction ") << endl;
		cout << messageMenuForCardIfEmptyOrNot(pille_domaine.size(), *pille_domaine.back(), "2-) Pour acheter un domaine ") << endl;
	}
	else
	{
		cout << messageMenuForCardIfEmptyOrNot(pille_cursed.size(), *pille_cursed.back(), "1-) Pour acheter une malediction ") << endl;

	}
	cout << "0-)Retour \n";
	cout << "Faites votre choix " << endl;
	cin >> choix;

	switch (choix)
	{
	case 1:

		if (pille_domaine.size() == 1) {
			cout << "Petit malin !! cette pille de carte est vide" << endl;
		}
		else {
			putonHand(joueur, *pille_cursed.back());

			pille_cursed.pop_back();
			cout << "Vous avez acheter une carte malediction" << endl;
		}
		
		break;

	case 2:
		if (PlateformeGame::piece_posee >= pille_domaine.back()->getCarteCost()) {

			if (pille_domaine.size() == 1) {
				cout << "Petit malin !! cette pille de carte est vide" << endl;
			}
			else {
				putonHand(joueur, *pille_domaine.back());
				pille_domaine.pop_back();
				cout << "Vous avez acheter une carte domaine" << endl;
			}

		}
		else {
			cout << "Error" << endl;
			cout << "Faite choix moins couteux " << endl;
		}
		break;
	case 3:
		if (PlateformeGame::piece_posee >= pille_duchet.back()->getCarteCost()) {

			if (pille_duchet.size() == 1) {
				cout << "Petit malin !! cette pille de carte est vide" << endl;
			}
			else{
				putonHand(joueur, *pille_duchet.back());
				pille_duchet.pop_back();
				cout << "Vous avez acheter une carte duchet" << endl;
			}
		}
		else {
			cout << "Error" << endl;
			cout << " Faites un achat moins couteux " << endl;
		}
		break;
	case 4:
		if (PlateformeGame::piece_posee >= pille_province.back()->getCarteCost())
		{
			if(pille_province.size()==1){
				cout << "Partie terminee" << endl;
			}
			else {


				putonHand(joueur, *pille_province.back());
				pille_province.pop_back();
				cout << "Vous avez acheter une carte province" << endl;
			}
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


void func_vi(Joueur j, vector<Joueur*>list_joueur)
{
	j.pickFromDeckToHand(1);
	PlateformeGame::setAction(2);

}

void func_buch(Joueur j , vector<Joueur*>list_joueur)
{
	PlateformeGame::increment_achat();
	PlateformeGame::ajouterPiece(2);
}

void func_marche(Joueur j , vector<Joueur*>list_joueur)
{
	
	PlateformeGame::increment_action();
	PlateformeGame::increment_achat();
	PlateformeGame::ajouterPiece(1);
}


void PlateformeGame::StartGame()
{
	int nbr_joueur = 0;
	string name = "";
	
	
	do {
		cout << "combien de joueur" << endl;
		cin >> nbr_joueur;
		for (int i = 0; i < nbr_joueur; i++) {
			cout << "Ecrivez pseudonyme joueur" << endl;
			cin >> name;
			m_list_joueur.push_back(new Joueur(name));
			cout << "joueur " << name <<" ajoutee" << endl;
		}
	
	} while (nbr_joueur > 5);
	
	cout << "Debut de jeu" << endl;
	
	joueur_actuel = m_list_joueur[0];


	
	 for (int i = 0; i < 10; i++)
	{
	
		carte_royaume_1[i]->attribute_fun(func_vi , *joueur_actuel);
		carte_royaume_2[i]->attribute_fun(func_marche , *joueur_actuel);
		carte_royaume_3[i]->attribute_fun(func_buch , *joueur_actuel);

	}
	 do {
		 for(Joueur *joueur : m_list_joueur)
		 {
			 joueur_actuel = joueur;
			 PhaseAction(*joueur_actuel);
			 PhaseAchat(*joueur_actuel);
			 PhaseAjustement(*joueur_actuel);
		 }
	 } while (gameIsEnd() == false);

	
	
}

std::string PlateformeGame::messageMenuForCardIfEmptyOrNot(int size_pile, Carte& carte, string messageMenu)
{
	if(size_pile>1)
	{
		
		return messageMenu;
	}
	else {
	
		carte.bref_description();
		return "La pille de cette carte est vide \n";
	}

}

bool PlateformeGame::gameIsEnd()
{
	if (pille_province.size() == 1) {
		return true;
	}
	if(joueur_actuel->getVictory_value() == 30)
	{
		return true;
	}
	if(end_game == 3)
	{
		return true;
	}

	return false;
}


void PlateformeGame::PhaseAjustement(Joueur &joueur)
{
	joueur.presenter();

	joueur.setDiscard(table_de_jeu);
	

	initialisationStatus();

}

void PlateformeGame::PhaseAction(Joueur& joueur)
{
	int choix = 1;
	cout << "Joueur :" << joueur.getPseudo() << endl;
	cout << "Phase Action" << endl;
	showCurrentStatus();
	

	do {
		cout << "Faites le choix de la carte que vous voulez actionner et poser sur la table \n";

		joueur.showcart_type_royaume();
		if (joueur.hasRoyaume()) {
			cout << "Entrez 90 pour passer cette etape \n";
			cin >> choix;
			if (choix < 90) {
				if (joueur.isRoyaume(choix))
				{

					joueur.addOntable(choix);
					showCurrentStatus();
				}
				else {
					cout << "Cette carte nest pas une carte Royaume \n";
				}
			}
			else if (choix > 90) {
				cout << "Hors sujet mais on passera a letape suivante \n";
				break;
			}
			else {
				cout << "On passe a letape suivante \n";
			}
		}else{
			cout << "Vous n'avez pas de carte Royaume on passe alors a l'etape suivante" << endl;
		}


	} while (joueur.hasRoyaume() && nbr_action !=0);

}

PlateformeGame::~PlateformeGame()
{
	delete joueur_actuel;

	for (int i = 0; i < table_de_jeu.size(); i++) {
		delete table_de_jeu[i];
	}

	for(int i = 0; i < pille_cuivre.size() ; i++)
	{
		delete pille_cuivre[i];
	}

	for(int i = 0 ; i < pille_argent.size() ; i++)
	{
		delete pille_argent[i];
	}
	for(int i = 0 ; i < pille_or.size() ; i++)
	{
		delete pille_or[i];
	}
	for(int i = 0 ; i < pille_cursed.size() ; i++)
	{
		delete pille_cursed[i];
	}
	for(int i = 0 ; i < pille_domaine.size(); i++)
	{
		delete pille_domaine[i];
	}
	for(int i = 0 ; i < pille_duchet.size() ; i++)
	{
		delete pille_duchet[i];
	}
	for(int i = 0 ; i < pille_province.size() ; i++)
	{
		delete pille_province[i];
	}

	for(int i = 0 ; i < m_list_joueur.size() ; i++)
	{
		delete m_list_joueur[i];
	}

	

}


