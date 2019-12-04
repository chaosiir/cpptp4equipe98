/*
 * Camion.cpp
 *
 *  Created on: 2019-11-27
 *      Author: etudiant
 */

#include "Camion.h"
#include <sstream>
using namespace std;
namespace saaq {
/**
 * \brief constructeur de la classe Camion
 *   on enregistre en plus la date à laquelle le vehicule est creer
 * \param[in] p_niv une chaine de caractere ne contenant que le niv du vehicule
 * \param[in] p_immatriculation une chaine de caractere ne contenant que l'immatriculation du vehicule
 * \param[in] p_poids un entier superieur à 3000 indiquant le poids du vehicule
 * \param[in] p_nbEssieux un entier superieur à 1 indiquant le nombre d'essieux du vehicule
 * \pre le niv ,le nbPlaces et l'immatriculation sont valide
 */
Camion::Camion(const std::string& p_niv, const std::string& p_immatriculation,
		int p_poids, int p_nbEssieux) :
		Vehicule::Vehicule(p_immatriculation,p_niv), m_poids(p_poids), m_nbEssieux(p_nbEssieux) {
	INVARIANTS();

}

/**
 * \brief assignateur de m_immatriculation
 * \param[in] p_immatriculation une chaine de caracteres contenant la nouvelle immatriculation
 * \return un booleen indiquant si le changement à eu lieu
 */
int Camion::asgImmatriculation(const std::string& p_immatriculation) {
	if (util::validerImmatriculation(p_immatriculation)) { //verification de la validite de l'immatriculation
		m_immatriculation = p_immatriculation;
		return 0;
	}
	return 1;
}
/**
 * \brief accesseur de m_poids
 * \return l'attribut m_poids de la classe de type int
 */
const int Camion::reqpoids() {
	INVARIANTS();
	return m_poids;
}

/**
 * \brief accesseur de m_nbEssieux
 * \return l'attribut m_nbEssieux de la classe de type int
 */
const int Camion::reqnbEssieux() {
	INVARIANTS();
	return m_nbEssieux;
}

/**
 * \brief donne le tarif annuel pour posseder un Camion
 * \return le tarif sous la forme de double, pour les Camions celui-ci depend du poids et du nombre d'essieux
 */
double Camion::tarificationAnnuelle() {
	double tarif = 0;
	INVARIANTS();
	switch (m_nbEssieux) {
	case 2:
		tarif = (m_poids > 4000) ? 905.28 : 570.28;
		break;
	case 3:
		tarif = 1566.19;
		break;
	case 4:
		tarif = 2206.19;
		break;
	case 5:
		tarif = 2821.76;
		break;
	default:
		tarif = 3729.76;
	}
	return tarif;
}
/**
 * \brief clone le vehicule courant
 * \return un nouveau Camion iddentique à celui qui execute la fonction donné en type vehicule
 */
Vehicule* Camion::clone() const {
	return new Camion(*this);
}
/**
 * \brief detruit le camion appelé, pour cela on detruit l'objet date qui lui est associé dans ~Vehicule()
 */
Camion::~Camion() {
	this->Vehicule::~Vehicule();
}
/**
 * \brief retourne un vehicule formate dans une chaîne de caracteres (string)
 * \return une chaine de caracteres contenant les informations du Camion appele
 */
std::string Camion::reqVehiculeFormate() {
	ostringstream os;

	os << "Numero de serie : " << m_niv << endl;
	os << "Numero d’immatriculation : " << m_immatriculation << endl;
	os << "Date d’enregistrement : " << m_dateEnregistrement.reqDateFormatee()
			<< endl;
	os << "nombre d'essieux : " << m_nbEssieux << endl;
	os << "poids : " << m_poids << endl;
	os << "tarif : " << tarificationAnnuelle() << endl;
	return os.str();
}

/**
 * \brief fonction qui va servir à verifier les invariants: pour Camion il s'agit de verifier que le nombre d'essieux est au moins 2
 *  et le poids est superieur à 3000
 */
void Camion::verifieInvariant() const
{
	INVARIANT(m_poids>3000);
	INVARIANT(m_nbEssieux>1);
}
} /* namespace saaq */

