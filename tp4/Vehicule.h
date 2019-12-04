/**
 * \file Vehicule.h
 * \brief fichier contenant l'interface de la classe Vehicule
 * \author Ferraris Pascal
 * \version 1.0
 * \date 2019-10-06
 */

#ifndef VEHICULE_H_
#define VEHICULE_H_
#include <string>
#include <iostream>
#include "Date.h"
#include "validationFormat.h"
#include "ContratException.h"
namespace saaq
{
/**
 * \class Vehicule
 * \brief Classe implantant le concept de Vehicule
 * 		Attributs: m_niv : un objet string étant le numéro de série du Véhicule (ou NIV).
 *				   m_immatriculation : un objet stringetant le numéro de plaque d’immatriculation du Véhicule.
 *		   	   	   m_dateEnregistrement : la date d’enregistrement de l’immatriculation (construction de l'objet).
 */
class Vehicule
{
public:
	Vehicule(const std::string& p_niv, const std::string& p_immatriculation);
	const util::Date reqDateEnregistrement();
	const std::string& reqImmatriculation();
	const std::string& reqNiv();
	std::string reqVehiculeFormate();
	const bool operator==(const Vehicule& p_Vehicule);
	virtual ~Vehicule();
	virtual  Vehicule*  clone() const=0;
	virtual double tarificationAnnuelle()=0;


protected:
	int asgImmatriculation(const std::string& p_immatriculation);
	std::string m_niv;
	std::string m_immatriculation;
	util::Date m_dateEnregistrement;

};

} /* namespace saaq */

#endif /* VEHICULE_H_ */
