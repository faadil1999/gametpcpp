#ifndef DEF_PLATEFORMEGAME
#define DEF_PLATEFORMEGAME
#include <iostream>
#include "Joueur.h"
#include "CarteVictoire.h"
#include <vector>

class PlateformeGame
{
public:
	PlateformeGame();
	static void  increment_action();
	static void increment_achat();
	static void increment_piece();
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
	static void achatCarteTresor(Joueur& joueur);
	static void achatCarteRoyaume(Joueur& joueur);
	static void achatCarteVictoire(Joueur &joueur);
	void static putonHand(Joueur &joueur , Carte &carte);
	void static StartGame();
	void static PhaseAjustement(Joueur &joueur);
	void static PhaseAchat(Joueur & joueur);
	


private:

	static std::vector<Carte*> table_de_jeu;
	static std::vector<CarteTresor*> pille_cuivre;
	static std::vector<CarteTresor*> pille_argent;
	static std::vector<CarteTresor*> pille_or;
	static std::vector<CarteVictoire*> pille_cursed;
	static std::vector<CarteVictoire*> pille_domaine;
	static std::vector<CarteVictoire*> pille_duchet;
	static std::vector<CarteVictoire*> pille_province;
	static int nbr_achat;
	static int nbr_action;
	static int piece_posee;
};
#endif
