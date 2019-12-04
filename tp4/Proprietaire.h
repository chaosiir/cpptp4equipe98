/*
 * Proprietaire.h
 *
 *  Created on: 2019-11-27
 *      Author: etudiant
 */

#ifndef PROPRIETAIRE_H_
#define PROPRIETAIRE_H_
#include <string>
#include <iostream>
#include <vector>
#include "Vehicule.h"

namespace saaq
{
/**
 * \class Proprietaire
 * \brief Classe implantant le concept de Proprietaire
 * 		Attributs: m_nom : un objet string étant le nom du proprietaire
 *				   m_prenom : un objet string etant le prenom du proprietaire.
 *				   m_vVehicules: la liste des vehicule possédée par le proprietaire
 *
 */
class Proprietaire
{
public:
	Proprietaire(const std::string& p_nom, const std::string& p_prenom);
	const std::string& reqnom();
	const std::string& reqprenom();
	std::string reqProprietaireFormate();
	void ajouterVehicule (const Vehicule& p_nouveauVehicule);
	~Proprietaire();
	Proprietaire (const Proprietaire& p_proprietaire);
	Proprietaire operator = (const Proprietaire& p_proprietaire);
	void verifieInvariant() const;

private:
	std::string m_nom;
	std::string m_prenom;
	std::vector<Vehicule*> m_vVehicules;
};

} /* namespace saaq */




#endif /* PROPRIETAIRE_H_ */
