#ifndef DEF_CARTEROYAUME
#define DEF_CARTEROYAUME
#include <string>
#include "Carte.h"

class CarteRoyaume :public Carte 
{
public:
	CarteRoyaume();
	virtual void afficher()const;
	virtual void bref_description()const;
	virtual TypeCarte getCardType()const;
	virtual void effect_card();
};

#endif

