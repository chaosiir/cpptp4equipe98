/*
 * VehiculePromenade.cpp
 *
 *  Created on: 2019-11-27
 *      Author: etudiant
 */

#include "VehiculePromenade.h"
#include <sstream>
using namespace std;
namespace saaq {
/**
 * \brief constructeur de la classe VehiculePromenade
 *   on enregistre en plus la date à laquelle le vehicule est creer
 * \param[in] p_niv une chaine de caractere ne contenant que le niv du vehicule
 * \param[in] p_immatriculation une chaine de caractere ne contenant que l'immatriculation du vehicule
 * \param[in] p_nbPlacess un entier positif indiquant le nombre de place dans le vehicule
 * \pre le niv ,le nbPlaces et l'immatriculation sont valide
 */
VehiculePromenade::VehiculePromenade(const std::string& p_niv,
		const std::string& p_immatriculation, int p_nbPlaces) :
		Vehicule::Vehicule(p_immatriculation, p_niv), m_nbPlaces(p_nbPlaces) {
	INVARIANTS();

}
/**
 * \brief detruit le Vehicule de Promenade appelé, pour cela on detruit l'objet date qui lui est associé dans ~Vehicule()
 */
VehiculePromenade::~VehiculePromenade() {
	this->Vehicule::~Vehicule();
}
/**
 * \brief assignateur de m_immatriculation
 * \param[in] p_immatriculation une chaine de caracteres contenant la nouvelle immatriculation
 * \return un booleen indiquant si le changement à eu lieu
 */
int VehiculePromenade::asgImmatriculation(
		const std::string& p_immatriculation) {
	if (util::validerImmatriculation(p_immatriculation)) { //verification de la validite de l'immatriculation
		m_immatriculation = p_immatriculation;
		return 0;
	}
	return 1;
}
/**
 * \brief accesseur de m_nbPlaces
 * \return l'attribut m_nbPlaces de la classe de type int
 */
const int VehiculePromenade::reqnbPLaces() {
	INVARIANTS();
	return m_nbPlaces;
}

/**
 * \brief donne le tarif annuel pour posseder un vehicule de promenade
 * \return le tarif sous la forme de double, pour les vehicule de promenade celui-ci est toujours de 224.04$
 */
double VehiculePromenade::tarificationAnnuelle() {
	return 224.04;
}
/**
 * \brief clone le vehicule courant
 * \return un nouveau Vehicule de promenade iddentique à celui qui execute la fonction donné en type vehicule
 */
Vehicule* VehiculePromenade::clone() const {
	return new VehiculePromenade(*this);
}
/**
 * \brief retourne un vehicule formate dans une chaîne de caracteres (string)
 * \return une chaine de caracteres contenant les informations du Vehicule de Promenade appele
 */
std::string VehiculePromenade::reqVehiculeFormate() {
	ostringstream os;

	os << "Numero de serie : " << m_niv << endl;
	os << "Numero d’immatriculation : " << m_immatriculation << endl;
	os << "Date d’enregistrement : " << m_dateEnregistrement.reqDateFormatee()
			<< endl;
	os << "nombre de places : " << m_nbPlaces << endl;
	os << "tarif : 224.04$" << endl;
	return os.str();
}
/**
 * \brief fonction qui va servir à verifier les invariants: pour VehiculePromenade il s'agit de verifier que le nombre de place est positif
 */
void VehiculePromenade::verifieInvariant() const
{
	INVARIANT(m_nbPlaces>0);
}
} /* namespace saaq */

