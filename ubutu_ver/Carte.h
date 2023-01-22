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
	virtual std::string getSubTypeCard()const = 0;
	int getCarteCost() const;

	virtual ~Carte();
	
protected:
	TypeCarte m_type_carte;
	int m_carte_cost;
};

#endif
