#ifndef DEF_CARTEVICTOIRE
#define DEF_CARTEVICTOIRE
#include "Carte.h"
#include "Joueur.h"
#include <string>

class CarteVictoire:public Carte
{
public:
	enum TypeVictoire
	{
		DOMAINE,DUCHET,PROVINCE,MALEDICTION
	};
	CarteVictoire();
	CarteVictoire(TypeVictoire typevictoire);
	~CarteVictoire();
	int getValueVictoire()const;
	std::string getTypeVictoire()const;
	virtual void afficher()const;
	virtual void bref_description()const;
	virtual  TypeCarte getCardType() const;
	virtual void effect_card(Joueur &joueur);
	void beenTrashed(Joueur &joueur )const;
	

private:
	TypeVictoire m_typevictoire;
	int m_valeur_victoire;
};
#endif
