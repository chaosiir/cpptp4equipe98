/*
 * Camion.h
 *
 *  Created on: 2019-11-27
 *      Author: etudiant
 */

#ifndef CAMION_H_
#define CAMION_H_

#include <string>
#include <iostream>
#include "Date.h"
#include "Vehicule.h"
#include "validationFormat.h"
namespace saaq
{
/**
 * \class Vehicule
 * \brief Classe implantant le concept de Vehicule
 * 		Attributs: m_niv : un objet string étant le numéro de série du Véhicule (ou NIV).
 *				   m_immatriculation : un objet stringetant le numéro de plaque d’immatriculation du Véhicule.
 *		   	   	   m_dateEnregistrement : la date d’enregistrement de l’immatriculation (construction de l'objet).
 */
class Camion:public Vehicule
{
public:
	Camion(const std::string& p_niv, const std::string& p_immatriculation,int p_poids,int p_nbEssieux);
	const int reqpoids();
	const int reqnbEssieux();
	std::string reqVehiculeFormate();
	~Camion();
	void verifieInvariant() const;
	virtual Vehicule* clone() const;
	virtual double tarificationAnnuelle();

protected:
	int asgImmatriculation(const std::string& p_immatriculation);
private:
	int m_poids;
	int m_nbEssieux;
};

} /* namespace saaq */




#endif /* CAMION_H_ */
