/*
 * VehiculePromenade.h
 *
 *  Created on: 2019-11-27
 *      Author: etudiant
 */

#ifndef VEHICULEPROMENADE_H_
#define VEHICULEPROMENADE_H_

#include <string>
#include <iostream>
#include "Date.h"
#include "Vehicule.h"
#include "validationFormat.h"
namespace saaq
{
/**
 * \class VehiculePromenade
 * \brief Classe implantant le concept de Vehicule de Promedate heritant de la classe Vehicule
 * 		Attributs: m_niv : un objet string étant le numéro de série du Véhicule (ou NIV).
 *				   m_immatriculation : un objet stringetant le numéro de plaque d’immatriculation du Véhicule.
 *		   	   	   m_dateEnregistrement : la date d’enregistrement de l’immatriculation (construction de l'objet).
 *		   	   	   m_nbPlaces: un entier positif indiquant le nombre de place dans le vehicule
 */
class VehiculePromenade : public Vehicule
{
public:
	VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation,int p_nbPlaces);
	std::string reqVehiculeFormate();
	~VehiculePromenade();
	const int reqnbPLaces();
	virtual Vehicule* clone() const;
	virtual double tarificationAnnuelle();
	void verifieInvariant() const;

protected:
	int asgImmatriculation(const std::string& p_immatriculation);
private:
	int m_nbPlaces;
};

} /* namespace saaq */



#endif /* VEHICULEPROMENADE_H_ */
