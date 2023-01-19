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
vector<Carte*> PlateformeGame::m_trash = vector<Carte*>();
vector<CarteTresor*> PlateformeGame::pille_cuivre = vector<CarteTresor*>(47, new CarteTresor(CarteTresor::CUIVRE));
vector<CarteTresor*> PlateformeGame::pille_argent = vector<CarteTresor*>(41 , new CarteTresor(CarteTresor::ARGENT));
vector<CarteTresor*> PlateformeGame::pille_or = vector<CarteTresor*>(31, new CarteTresor(CarteTresor::OR));
vector<CarteVictoire*> PlateformeGame::pille_domaine = vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::DOMAINE));
vector<CarteVictoire*> PlateformeGame::pille_duchet = vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::DUCHET));
vector<CarteVictoire*> PlateformeGame::pille_province = vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::PROVINCE));
vector<CarteVictoire*> PlateformeGame::pille_cursed = vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::MALEDICTION));
vector<CarteRoyaume*> PlateformeGame::carte_royaume_1 = 
vector<CarteRoyaume*>(11,new CarteRoyaume( 3,"Village" , CarteRoyaume::TypeRoyaume::ACTION_ACTION , func_village));
vector<CarteRoyaume*> PlateformeGame::carte_royaume_2 =
vector<CarteRoyaume*>(11, new CarteRoyaume(5, "Marchee", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));
vector<CarteRoyaume*> PlateformeGame::carte_royaume_3 =
vector<CarteRoyaume*>(11, new CarteRoyaume(3, "Bucheron", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));
vector<CarteRoyaume*> PlateformeGame::carte_royaume_4 =
vector<CarteRoyaume*>(11, new CarteRoyaume(3, "Atelier", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));
vector<CarteRoyaume*> PlateformeGame::carte_royaume_5 =
vector<CarteRoyaume*>(11, new CarteRoyaume(4, "Forgeron", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));
vector<CarteRoyaume*> PlateformeGame::carte_royaume_6 =
vector<CarteRoyaume*>(11, new CarteRoyaume(5, "Festival", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));



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
void PlateformeGame::PhaseAchat()
{
	int choix = 1;
do{
	
	cout << "Joueur :" << joueur_actuel->getPseudo() << endl;
	cout << "Phase Achat" << endl;
	showCurrentStatus();
	do {
		cout << "Faites le choix de la carte que vous voulez poser sur la table \n";

		joueur_actuel->showcart_type_tresor();
		if (joueur_actuel->hasTresor()) {
			cout << "Entrez 91 pour passer cette etape \n";
			cin >> choix;
			if (choix < 90) {
				if (joueur_actuel->isTresor(choix))
				{

					joueur_actuel->addOntable(choix);
					showCurrentStatus();
				}
				else {
					cout << "Cette carte nest pas une carte tresor \n";
				}
			}
			else if (choix > 90) {
				cout << "On passera a letape suivante \n";
				break;
			}
			else {
				cout << "Choisissez bien !! \n";
			}
		}


	} while (joueur_actuel->hasTresor() );
	choix = 0;

	cout << "Quel type de carte voulez vous acheter\n";
	cout << "1-) Pour les cartes de type tresor \n";
	cout << "2-) Pour les cartes de type royaume \n";
	cout << "3-) Pour les cartes de type victoire \n";
	cin >> choix;
	switch (choix)
	{
	case 1:

		PlateformeGame::achatCarteTresor();
		break;

	case 2:
		PlateformeGame::achatCarteRoyaume();
		break;

	case 3:
		PlateformeGame::achatCarteVictoire();
		break;

	case 0:
		cout << "Vous avez passer cette etape \n";
		break;

	default:
		cout << "Mauvais numero de choix \n";
		break;
	}
	decrement_achat();

} while ( nbr_achat!=0 && (choix != 90 && choix < 90));
	



}

void PlateformeGame::putonHand( Carte &carte)
{
	if (carte.getCardType() == Carte::VICTOIRE) {
		
		CarteVictoire& carte_v = dynamic_cast<CarteVictoire&>(carte);
		
		carte_v.effect_card(*joueur_actuel);
	
	}
	else {
		joueur_actuel->addCardOnHand(carte);
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

void PlateformeGame:: achatCarteTresor()
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
		putonHand( *pille_cuivre.back() );

		pille_cuivre.pop_back();
		if (pille_cuivre.size() == 1) {
			incrementEndGame();
		}
		cout << "Vous avez acheter une carte cuivre" << endl;
		break;

	case 2:
		if (PlateformeGame::piece_posee >= pille_argent.back()->getCarteCost()) {

			if (pille_argent.size() == 1) {
				cout << "Petit malin !! cette pille de carte est vide" << endl;
			}
			else {
				putonHand(*pille_argent.back());
				pille_argent.pop_back();
				if (pille_argent.size() == 1) {
					incrementEndGame();
				}
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
				putonHand(*pille_or.back());
				pille_or.pop_back();

				if (pille_or.size() == 1) {
					incrementEndGame();
				}
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
		PlateformeGame::PhaseAchat();
		break;
	default:
		break;
	}

	
}

void PlateformeGame:: achatCarteRoyaume()
{
	int choix = 0;
	cout << "Faites un choix" << endl;
	

	
	if (piece_posee >= carte_royaume_1.back()->getCarteCost() )
	{
		cout << messageMenuForCardIfEmptyOrNot(carte_royaume_1.size(), *carte_royaume_1.back(), "1-) Pour acheter la carte " + carte_royaume_1.back()->getName())<<endl;
	}

	if (piece_posee >= carte_royaume_2.back()->getCarteCost())
	{
		cout << messageMenuForCardIfEmptyOrNot(carte_royaume_2.size(), *carte_royaume_2.back(), "2-) Pour acheter la carte " + carte_royaume_2.back()->getName()) << endl;
	}

	if (piece_posee >= carte_royaume_3.back()->getCarteCost())
	{
		cout << messageMenuForCardIfEmptyOrNot(carte_royaume_3.size(), *carte_royaume_3.back(), "3-) Pour acheter la carte " + carte_royaume_3.back()->getName()) << endl;
	}
	cout << "0-)Retour" << endl;

	cin >> choix;
	
	switch (choix)
	{
	case 1:
		putonHand( *carte_royaume_1.back());
			carte_royaume_1.pop_back();
			cout << "carte " + carte_royaume_1.back()->getName() + " achetee" << endl;
		break;
	case 2:
		putonHand(*carte_royaume_2.back());
		carte_royaume_2.pop_back();
		cout << "carte " + carte_royaume_2.back()->getName() + " achetee" << endl;
		break;
	case 3:
		putonHand(*carte_royaume_3.back());
		carte_royaume_3.pop_back();
		cout << "carte " + carte_royaume_3.back()->getName() + " achetee" << endl;
		break;
	case 0:
		PlateformeGame::PhaseAchat();
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



void PlateformeGame::achatCarteVictoire()
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
			putonHand( *pille_cursed.back());

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
				putonHand(*pille_domaine.back());
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
				putonHand( *pille_duchet.back() );
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


				putonHand(*pille_province.back());
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
		PlateformeGame::PhaseAchat();
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

void func_festival(Joueur j , vector<Joueur*>list_joueur)
{

	PlateformeGame::setAction(2);
	PlateformeGame::increment_achat();
	PlateformeGame::ajouterPiece(2);

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
void func_attelier(Joueur j , vector<Joueur*>list_joueur)
{
	
	PlateformeGame::show_from_piece_value(4);

}

void func_vassal(Joueur j , vector<Joueur*>list_joueur)
{
	j.from_top_deck_to_discard();
	PlateformeGame::ajouterPiece(2);

}

void func_forge(Joueur j , vector<Joueur*>list_joueur)
{

	j.pickFromDeckToHand(3);
	cout << "3 cartes ajoutees dans la main" << endl;

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


	
	 for (int i = 0; i < 11; i++)
	{
	
		carte_royaume_1[i]->attribute_fun(func_vi , *joueur_actuel);
		carte_royaume_2[i]->attribute_fun(func_marche , *joueur_actuel);
		carte_royaume_3[i]->attribute_fun(func_buch , *joueur_actuel);
		carte_royaume_4[i]->attribute_fun(func_attelier, *joueur_actuel);
		carte_royaume_5[i]->attribute_fun(func_forge, *joueur_actuel);
		carte_royaume_6[i]->attribute_fun(func_festival, *joueur_actuel);

	}
	 do {
		 for(Joueur *joueur : m_list_joueur)
		 {
			 joueur_actuel = joueur;
			 PhaseAction();
			 PhaseAchat();
			 PhaseAjustement();
		 }
	 } while (gameIsEnd() == false);

	
	
}


void PlateformeGame::deffausser_carte(Joueur& joueur, int position)
{
	joueur.from_deck_to_place(position);

};

void PlateformeGame::deffausser_top_carte_action(Joueur& joueur)
{
	joueur.from_top_deck_to_trash();
}

void PlateformeGame::add_to_player_discard(Carte& carte)
{
	if (carte.getCardType() == Carte::ROYAUME)
	{
		cout << "Il s'agit dune carte royaume" << endl;
		cout << "On execute donc la carte " << endl;
		CarteRoyaume& carte_r = dynamic_cast<CarteRoyaume&>(carte);
		carte_r.execute_action(*joueur_actuel, m_list_joueur);
	}
	else
	{
		cout << "Carte envoyee dans le discard du joueur actuel" << endl;
	}
}

void PlateformeGame::add_to_trash(Carte& carte)
{
	if (carte.getCardType() == Carte::ROYAUME)
	{
		cout << "Il s'agit dune carte royaume" << endl;
		cout << "On execute donc la carte " << endl;
		CarteRoyaume& carte_r = dynamic_cast<CarteRoyaume&>(carte);
		carte_r.execute_action(*joueur_actuel, m_list_joueur);
	}
	m_trash.push_back(&carte);
	cout << "carte deffausser" << endl;
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


void PlateformeGame::PhaseAjustement()
{
	joueur_actuel->presenter();

	joueur_actuel->setDiscard(table_de_jeu);
	

	initialisationStatus();

}

void PlateformeGame::PhaseAction()
{
	int choix = 1;
	cout << "Joueur :" << joueur_actuel->getPseudo() << endl;
	cout << "Phase Action" << endl;
	showCurrentStatus();
	

	do {
		cout << "Faites le choix de la carte que vous voulez actionner et poser sur la table \n";

		joueur_actuel->showcart_type_royaume();
		if (joueur_actuel->hasRoyaume()) {
			cout << "Entrez 90 pour passer cette etape \n";
			cin >> choix;
			if (choix < 90) {
				if (joueur_actuel->isRoyaume(choix))
				{

					joueur_actuel->addOntable(choix);
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


	} while (joueur_actuel->hasRoyaume() && nbr_action !=0);

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

void PlateformeGame::show_from_piece_value(int piece_val)
{
	vector<Carte*>list_cartd = vector<Carte*>();
	list_cartd.push_back(pille_cuivre.back());
	list_cartd.push_back(pille_argent.back());
	list_cartd.push_back(pille_or.back());
	list_cartd.push_back(pille_cursed.back());
	list_cartd.push_back(pille_domaine.back());
	list_cartd.push_back(pille_duchet.back());
	list_cartd.push_back(pille_province.back());
	list_cartd.push_back(carte_royaume_1.back());
	list_cartd.push_back(carte_royaume_2.back());
	list_cartd.push_back(carte_royaume_3.back());

	for(int i = 0 ; i < list_cartd.size() ; i++)
	{
		if(	list_cartd[i]->getCarteCost() <= piece_val )
		{
			cout << i << " ) ";
			list_cartd[i]->bref_description();
		}
	}
	
	cout << "Choisissez une carte " << endl;
	int choix = 0;
	switch (choix)
	{
		
	case 0:
		if (verif_card_and_piece(piece_val, pille_cuivre.back()->getCarteCost() )) 
		{

			joueur_actuel->addCardOnHand(*pille_cuivre.back());
			pille_cuivre.pop_back();
		}
	
		break;
	case 1:
		if (verif_card_and_piece(piece_val, pille_argent.back()->getCarteCost()))
		{

			joueur_actuel->addCardOnHand(*pille_argent.back());
			pille_argent.pop_back();
		}
		break;
	case 2:
		if (verif_card_and_piece(piece_val, pille_or.back()->getCarteCost()))
		{

			joueur_actuel->addCardOnHand(*pille_or.back());
			pille_or.pop_back();
		}
		break;
	case 3:
		if (verif_card_and_piece(piece_val, pille_cursed.back()->getCarteCost()))
		{

			joueur_actuel->addCardOnHand(*pille_cursed.back());
			pille_cursed.pop_back();
		}
		break;
	case 4:
		if (verif_card_and_piece(piece_val, pille_domaine.back()->getCarteCost()))
		{

			joueur_actuel->addCardOnHand(*pille_domaine.back());
			pille_domaine.pop_back();
		}
		else {
			cout << "Petit malin" << endl;
		}

		break;
	case 5:
		if (verif_card_and_piece(piece_val, pille_duchet.back()->getCarteCost()))
		{

			joueur_actuel->addCardOnHand(*pille_duchet.back());
			pille_duchet.pop_back();
		}
		else {
			cout << "Petit malin" << endl;
		}
		break;
	case 6:
		if (verif_card_and_piece(piece_val, pille_province.back()->getCarteCost()))
		{

			joueur_actuel->addCardOnHand(*pille_province.back());
			pille_province.pop_back();
		}
		else {
			cout << "Petit malin" << endl;
		}
		break;
	case 7:
		if (verif_card_and_piece(piece_val, carte_royaume_1.back()->getCarteCost()))
		{

			joueur_actuel->addCardOnHand(*carte_royaume_1.back());
			carte_royaume_1.pop_back();
		}
		else {
			cout << "Petit malin" << endl;
		}
		break;
	case 8:
		if (verif_card_and_piece(piece_val, carte_royaume_2.back()->getCarteCost()))
		{

			joueur_actuel->addCardOnHand(*carte_royaume_2.back());
			carte_royaume_2.pop_back();
		}
		else {
			cout << "Petit malin" << endl;
		}
		break;
	case 9:
		if (verif_card_and_piece(piece_val, carte_royaume_3.back()->getCarteCost()))
		{

			joueur_actuel->addCardOnHand(*carte_royaume_3.back());
			carte_royaume_3.pop_back();
		}
		break;
	case 10:
		cout << "bientot" << endl;
		break;
	case 11:
		cout << "bientot" << endl;
		break;
	case 12:
		cout << "Bientot" << endl;
		break;

	default:
		cout << "Bientot" << endl;
		break;
	}

}


void PlateformeGame::presentationEndGame()
{
	for(Joueur* joueur : m_list_joueur)
	{
		cout << joueur->getPseudo() << " a pour victoire " << joueur->getVictory_value() << endl;
	
	}

}

bool PlateformeGame::verif_card_and_piece(int piece , int carte_val)
{
	return piece >=  carte_val;
}


