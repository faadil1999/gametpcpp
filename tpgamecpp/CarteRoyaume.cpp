#include <iostream>
#include "CarteRoyaume.h"
using namespace std;

CarteRoyaume::CarteRoyaume() {
	m_type_carte = Carte::ROYAUME;
	m_carte_cost = 2;
}

void CarteRoyaume::afficher()const{

	cout << "Il sagit dune carte royaume" << endl;
}

void CarteRoyaume::bref_description()const {
	cout << "bientot" << endl;
};

Carte::TypeCarte CarteRoyaume::getCardType()const 
{
	return m_type_carte;
}

void CarteRoyaume::effect_card()
{
	cout << "Une action sera activee " << endl;
}

