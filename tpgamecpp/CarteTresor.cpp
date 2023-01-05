#include <iostream>
#include <string>
#include "CarteTresor.h"
#include "PlateformeGame.h"

using namespace std;

string enum_to_string(CarteTresor::TypeTresor tresor) {
	switch (tresor)
	{
	case CarteTresor::CUIVRE:
		return "Cruivre";
		break;
	case CarteTresor::ARGENT:
		return "Argent";
		break;
	case CarteTresor::OR:
		return "Or";
		break;
	default:
		cout << "ERROORR" << endl;
		return "Cuivre";
		break;
	}
}

CarteTresor::CarteTresor() {
	m_type_carte = Carte::TRESOR;
	m_typetresor = CarteTresor::CUIVRE;
	m_valeur = 1;
	m_carte_cost = 0;
}

CarteTresor::CarteTresor(TypeTresor typetresor):m_typetresor(typetresor)
{
	m_type_carte = Carte::TRESOR;

	switch (typetresor)
	{
	case CarteTresor::CUIVRE:
		m_valeur = 1;
		m_carte_cost = 0;
		break;
	case CarteTresor::ARGENT:
		m_valeur = 2;
		m_carte_cost = 3;
		break;
	case CarteTresor::OR:
		m_valeur = 3;
		m_carte_cost = 6;
		break;
	default:
		cout << "ERROORR" << endl;
		m_valeur = 1;
		break;
	}
}
int CarteTresor::getCarteValue()const {
	return m_valeur;
}

void CarteTresor::afficher()const {
	cout << "Il sagit dune carte Tresor" << endl;
	cout << "je suis de type " << enum_to_string(m_typetresor) << " Je vaut " << m_valeur << endl ;
}

void CarteTresor::bref_description()const {
	cout << "Type Tresor " << enum_to_string(m_typetresor) << " Valeur: " << m_valeur << endl;
}

void CarteTresor::effect_card()
{
	
	PlateformeGame::ajouterPiece(m_valeur);
};

Carte::TypeCarte CarteTresor::getCardType()const
{
	return  m_type_carte;
}


CarteTresor::~CarteTresor()
{
}
