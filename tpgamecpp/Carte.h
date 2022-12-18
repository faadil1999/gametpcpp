#ifndef DEF_CARTE
#define DEF_CARTE
#include <string>
class Carte
{
public:
	enum TypeCarte
	{
		VICTOIRE,TRESOR,ROYAUME
	};

	virtual void afficher() const = 0;
	virtual void bref_description() const = 0;
	virtual TypeCarte getCardType() const = 0;
	virtual void effect_card() ;
	int getCarteCost() const;
	
protected:
	TypeCarte m_type_carte;
	int m_carte_cost;
};

#endif
