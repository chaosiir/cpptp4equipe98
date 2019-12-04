/*
 * Proprietaire.cpp
 *
 *  Created on: 2019-11-27
 *      Author: etudiant
 */

#include "Proprietaire.h"
#include <sstream>
using namespace std;
namespace saaq {
/**
 * \brief constructeur de la classe Proprietaire
 *   on creer aussi un vecteur de pointeur de vehicule pour m_vVehicules
 * \param[in] p_nom un string étant le nom du proprietaire
 * \param[in] p_prenom un string étant le prenom du proprietaire
 * \pre p_nom et p_prenom ne sont pas vide
 */
Proprietaire::Proprietaire(const std::string& p_nom,
		const std::string& p_prenom) :
		m_nom(p_nom), m_prenom(p_prenom){
	 m_vVehicules={};
	 INVARIANTS();
	 POSTCONDITION(m_vVehicules.empty())
}

/**
 * \brief accesseur de m_nom
 * \return l'attribut m_nom de la classe de type string&
 */
const std::string& Proprietaire::reqnom() {
	INVARIANTS();
	return m_nom;
}
/**
 * \brief accesseur de m_prenom
 * \return l'attribut m_prenom de la classe de type string&
 */
const std::string& Proprietaire::reqprenom() {
	INVARIANTS();
	return m_prenom;
}

/**
 * \brief clone le proprietaire
 * \return un nouveau Vehicule de promenade iddentique à celui qui execute la fonction donné en type vehicule
 */
Proprietaire::Proprietaire(const Proprietaire& p_proprietaire) :
		m_prenom(p_proprietaire.m_prenom), m_nom(p_proprietaire.m_nom), m_vVehicules(
				p_proprietaire.m_vVehicules) {
	INVARIANTS();
}
/**
 * \brief assigne les valeurs de p_proprietaire à un objet Proprietaire et le renvois
 * \return le proprieraire modifié
 */
Proprietaire Proprietaire::operator = (const Proprietaire& p_proprietaire) {
	Proprietaire p=Proprietaire(p_proprietaire.m_prenom,p_proprietaire.m_prenom);
	INVARIANTS();
	p.m_vVehicules = p_proprietaire.m_vVehicules;
	return p;
}
/**
 * \brief retourne un Proprietaire formate dans une chaîne de caracteres (string)
 * \return une chaine de caracteres contenant les informations du Proprietaire appele
 */
std::string Proprietaire::reqProprietaireFormate() {
	ostringstream os;

	os << "Proprietaire " << endl;
	os << "------------------- " << endl;
	os << "Nom : " << m_nom << endl;
	os << "Prenom : " << m_prenom << endl;
	for (int i = 0; i < m_vVehicules.size(); ++i) {
		os << "------------------- " << endl;
		os << m_vVehicules[i]->reqVehiculeFormate() << endl;
	}
	return os.str();
}
/**
 * \brief ajoute un vehicule au proprietaire
 * \param[in] p_nouveauVehicule le vehicule à ajoueter à la liste de vehicule du proprietaire
 */
void Proprietaire::ajouterVehicule(const Vehicule& p_nouveauVehicule) {
	m_vVehicules.push_back(p_nouveauVehicule.clone());
	POSTCONDITION(!m_vVehicules.empty())
}

/**
 * \brief Destructeur de Proprietaire, on detruit tous les vehicules
 */
Proprietaire::~Proprietaire() {
	for (int i = 0; i < m_vVehicules.size(); ++i) {
		m_vVehicules[i]->~Vehicule();
	}
}

void Proprietaire::verifieInvariant() const
{
	INVARIANT(!m_nom.empty());
	INVARIANT(!m_prenom.empty());
}
} /* namespace saaq */

