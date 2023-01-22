#ifndef DEF_PLATEFORMEGAME
#define DEF_PLATEFORMEGAME
#include <iostream>
#include "Joueur.h"
#include "CarteVictoire.h"
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/writer.h>
#include <fstream>

#include <vector>




class PlateformeGame
{
public:
	PlateformeGame();
	static void  increment_action();
	static void increment_achat();

	static void decrement_action();
	static void decrement_achat();
	static void initialisationStatus();

	static void utiliserPiece(int piece);
	static int getAction();
	static int getAchat();
	static int getPiece();
	static void setAction(int nbr_ac);
	static void ajouterPiece(int value_coin);
	static void setTableJeu(Carte &carte);
	//function getActuelJoueur and getListJoueur is for execution of the royaume card
	static Joueur &getActuelJoueur();
	static std::vector<Joueur*> getListJoueur();

	static void achatCarteTresor();
	static void achatCarteRoyaume();
	static void achatCarteVictoire();
	
	static void putonHand(Carte &carte);
	static void  StartGame();
	static void  PhaseAjustement();
	static void PhaseAchat();
	static void PhaseAction();

	static void saveGame();
	static void loadGame();

	static void  showCurrentStatus() ;
	static std::string messageMenuForCardIfEmptyOrNot( int size_pile , Carte &carte  ,std::string messageMenu);
	bool static gameIsEnd();
	void static incrementEndGame();
	void static presentationEndGame();

	void static show_from_piece_value(int val_piece);
	
	bool static verif_card_and_piece(int piece , int val_carte );

	void static deffausser_carte(Joueur &joueur , int position);

	void static deffausser_top_carte_action(Joueur &joueur);


	void static add_to_player_discard(Carte &carte);

	void static add_to_trash(Carte& carte);

	~PlateformeGame();
	


private:

	static std::vector<Carte*> table_de_jeu;
	static std::vector<Carte*> m_trash;
	static std::vector<CarteTresor*> pille_cuivre;
	static std::vector<CarteTresor*> pille_argent;
	static std::vector<CarteTresor*> pille_or;
	static std::vector<CarteVictoire*> pille_cursed;
	static std::vector<CarteVictoire*> pille_domaine;
	static std::vector<CarteVictoire*> pille_duchet;
	static std::vector<CarteVictoire*> pille_province;
	
	static std::vector<Joueur*>m_list_joueur;
	static std::vector<CarteRoyaume*>  carte_royaume_1;
	static std::vector<CarteRoyaume*>  carte_royaume_2;
	static std::vector<CarteRoyaume*>  carte_royaume_3;
	static std::vector<CarteRoyaume*>  carte_royaume_4;
	static std::vector<CarteRoyaume*>  carte_royaume_5;
	static std::vector<CarteRoyaume*>  carte_royaume_6;
/*	static std::vector<CarteRoyaume*>  carte_royaume_7;
	static std::vector<CarteRoyaume*>  carte_royaume_8;
	static std::vector<CarteRoyaume*>  carte_royaume_9;
	static std::vector<CarteRoyaume*>  carte_royaume_10;
	*/
	static Joueur* joueur_actuel;
	static int nbr_achat;
	static int nbr_action;
	static int piece_posee;
	static unsigned short end_game;
	
};
#endif
