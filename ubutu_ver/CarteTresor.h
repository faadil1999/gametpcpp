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
	std::string getCardTresorType();
	int getCarteValue()const;
	virtual void afficher()const;
	virtual void bref_description()const;
	virtual TypeCarte getCardType()const;
	virtual void effect_card();
	virtual std::string getSubTypeCard()const;
	~CarteTresor();
	

private:
	TypeTresor m_typetresor;
	int m_valeur;
	
};
#endif

