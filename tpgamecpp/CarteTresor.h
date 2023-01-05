#ifndef DEF_CARTETRESOR
#define DEF_CARTETRESOR
#include "Carte.h"

class CarteTresor : public Carte
{
public:
	enum TypeTresor
	{
		CUIVRE,
		ARGENT,
		OR
	};

	CarteTresor();
	CarteTresor(TypeTresor tresor);
	int getCarteValue()const;
	virtual void afficher()const;
	virtual void bref_description()const;
	virtual TypeCarte getCardType()const;
	virtual void effect_card();
	~CarteTresor();
	

private:
	TypeTresor m_typetresor;
	int m_valeur;
	
};
#endif

