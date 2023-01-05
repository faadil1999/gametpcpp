#ifndef DEF_CARTEROYAUME
#define DEF_CARTEROYAUME
#include "Carte.h"

#include <string>
#include <vector>

class Joueur;

class CarteRoyaume :public Carte 
{
public:
	enum TypeRoyaume
	{
		ACTION_ACTION,
		ACTION_REACTION,
		ACTION_ATTACK,
		VICTOIRE
	};

	CarteRoyaume();
	CarteRoyaume(int cost ,std::string name_card, TypeRoyaume typecart , void(&func)(Joueur, std::vector<Joueur*>) );
	virtual void afficher()const;
	virtual void bref_description()const;
	virtual TypeCarte getCardType()const;
	virtual void effect_card();
	void attribute_fun(void(&function)(Joueur, std::vector<Joueur*>),Joueur j);
	void execute_action(Joueur &j , std::vector<Joueur*>list_j);
	std::string getName()const;
	~CarteRoyaume();
	//void testshowAdressEffect()const;
	
	//void effect_secondaire(Joueur& joueur, vector<Joueur>joueurs, void(*function)(Joueur, std::vector<Joueur>));
	

private:
	TypeRoyaume m_type_cart_royaume;
	std::string m_nom_carte;
	std::string m_description_carte;
	void (* effect)(Joueur joueur, std::vector<Joueur*>joueurs );
	
};

#endif

