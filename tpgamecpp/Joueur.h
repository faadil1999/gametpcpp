#ifndef DEF_JOUEUR
#define DEF_JOUEUR
#include <iostream>
#include "CarteRoyaume.h"
#include "CarteTresor.h"
#include <vector>
#include <string>

class Joueur
{
public:
	Joueur(std::string pseudo);
	void presenter()const;
	void useCarteAction(CarteRoyaume carte_royaume);
	void useCartePiece(CarteTresor carte_tresor);

	void setVictoryVal(int value);
	void carteMain()const;
	void showDeck()const;
	void showDiscard()const;
	void addCardOnHand(Carte& carte);
	void addOntable(int position_cart);
	void setDiscard(std::vector <Carte*> cartes);
	void showcart_type_tresor() const;/*we can make a func with cart_type as parameter but jai la flemme de refaire tout le code*/
	void showcart_type_royaume()const;
	void showcart_type_carte(Carte::TypeCarte type_cart)const;
	bool hasTresor()const;/*we can make a func with cart_type as parameter but jai la flemme de refaire tout le code*/
	bool hasRoyaume()const;
	bool hasTypeCarte(Carte::TypeCarte type_cart)const;
	bool isTresor(int position)const;
	bool isRoyaume(int position)const;

	bool isTypeRequested(int position , Carte::TypeCarte type_req)const;

	void pickFromDeckToHand(int nbr_carte);

	bool isGoodIndice(int position , std::vector<Carte*>cartes )const;
	std::vector<Carte*> getHandCartes()const;
	std::string getPseudo()const;
	int getVictory_value()const;
	~Joueur();


private:
	std::vector <Carte*> m_deck;
	std::vector <Carte*> m_trash;
	std::vector <Carte*> m_discard;
	std::vector <Carte*> m_hand;
	std::string m_pseudo;
	int m_victory_value;
};
#endif

