/**
 * \file Vehicule.cpp
 * \brief fichier contenant la classe Vehicule
 * \author Ferraris Pascal
 * \version 1.0
 * \date 2019-10-06
 */

#include "Vehicule.h"
#include <sstream>
using namespace std;
namespace saaq {
/**
 * \brief constructeur de la classe Vehicule
 *   on enregistre en plus la date à laquelle le vehicule est creer
 * \param[in] p_niv une chaine de caractere ne contenant que le niv du vehicule
 * \param[in] p_immatriculation une chaine de caractere ne contenant que l'immatriculation du vehicule
 * \pre le niv et l'immatriculation sont valide
 */
Vehicule::Vehicule(const std::string& p_niv,
		const std::string& p_immatriculation) {
	PRECONDITION (util::validerImmatriculation(p_immatriculation));
	PRECONDITION (util::validerNiv(p_niv));
	m_immatriculation = p_immatriculation;
	m_niv = p_niv;
	util::Date date; //creation d'un date par defaut
	m_dateEnregistrement = date;//on considere que la date est deja validée

}
/**
 * \brief accesseur de m_dateEnregistrement
 * \return l'attribut m_dateEnregistrement de la classe de type date
 */
const util::Date Vehicule::reqDateEnregistrement() {
	return m_dateEnregistrement;
}

/**
 * \brief detruit le Vehiculeappelé, pour cela on detruit l'objet date qui lui est associé
 */
Vehicule::~Vehicule() {
	m_dateEnregistrement.~Date();
}

/**
 * \brief accesseur de m_immatriculation
 * \return l'attribut m_immatriculation de la classe de type string
 */

const std::string& Vehicule::reqImmatriculation() {
	ASSERTION(!m_immatriculation.empty())
	return m_immatriculation;
}
/**
 * \brief assignateur de m_immatriculation
 * \param[in] p_immatriculation une chaine de caracteres contenant la nouvelle immatriculation
 * \return un booleen indiquant si le changement à eu lieu
 */
int Vehicule::asgImmatriculation(const std::string& p_immatriculation) {
	if (util::validerImmatriculation(p_immatriculation)) { //verification de la validite de l'immatriculation
		m_immatriculation = p_immatriculation;
		return 0;
	}
	return 1;
}
/**
 * \brief accesseur de m_niv
 * \return l'attribut m_niv de la classe de type string
 */
const std::string& Vehicule::reqNiv() {
	ASSERTION(!m_niv.empty())
	return m_niv;
}
/**
 * \brief retourne un vehicule formate dans une chaîne de caracteres (string)
 * \return une chaine de caracteres contenant les informations du vehicule appele
 */
std::string Vehicule::reqVehiculeFormate() {
	ostringstream os;

	os << "Numero de serie : " << m_niv << endl;
	os << "Numero d’immatriculation : " << m_immatriculation << endl;
	os << "Date d’enregistrement : " << m_dateEnregistrement.reqDateFormatee()
			<< endl;

	return os.str();
}
/**
 * \brief operateur de comparaison entre deux vehicule
 * 		  on teste si tout les attributs sont egaux
 * \param[in] p_Vehicule le vehicule qu'on compare avec le vehicule sur lequel on appel la fonction
 * \return un booleen indiquant si les vehicules sont bien egaux
 */
const bool Vehicule::operator ==(const Vehicule& p_Vehicule) {
	return ((m_dateEnregistrement == p_Vehicule.m_dateEnregistrement)
			&& (m_immatriculation.compare(p_Vehicule.m_immatriculation) == 0)// si les deux chaines sont iddentique alors compare = 0
			&& (m_niv.compare(p_Vehicule.m_niv) == 0));
}

} /* namespace saaq */
