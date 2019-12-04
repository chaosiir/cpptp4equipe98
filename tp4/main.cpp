/**
 * \file gestionImmatriculations.cpp
 * \brief fichier contenant le main pour tester notre classe Vehicule
 * \author Ferraris Pascal
 * \version 1.0
 * \date 2019-10-06
 */

#include <iostream>
#include <string>
#include "Vehicule.h"
#include "Proprietaire.h"
#include "VehiculePromenade.h"
#include "Camion.h"

using namespace std;
/**
 * \brief main pour tester la classe Vehicule
 */
int main()
{
	cout<<"*******************************************************"<<endl;
	cout<<"Bienvenue a l'outil d'ajout de gestion de vehicules"<<endl;
	cout<<"*******************************************************"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"Ajoutez un vehicule de promenade"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	saaq::Proprietaire user=saaq::Proprietaire("ferraris","pascal");
	string niv;//3VWFE21C04M000001
	do
	{
		cout << "entrez un niv" << endl;
		getline(cin, niv);
		if (!util::validerNiv(niv))
		{
			cout << "niv invalide" << endl;
		}
	} while (!util::validerNiv(niv)); //tant que le niv est faux on en demande un autre
	string immatriculation;//IFT 006
	do
	{
		cout << "entrez une immatriculation" << endl;
		getline(cin, immatriculation);
		if (!util::validationImmatriculationPromenade(immatriculation))
		{
			cout << "immatriculation invalide" << endl;
		}
	} while (!util::validationImmatriculationPromenade(immatriculation)); //tant que l'immatriculation est fausse on en demande une autre
	int nbplace;
	cout << "entrez le nombre de place" << endl;
	while(!(cin>>nbplace)){
		cin.clear();
		cin.ignore(10000,'\n');
		cout << "entrez un nombre valide" << endl;
	}
	saaq::VehiculePromenade VP = saaq::VehiculePromenade(niv, immatriculation,nbplace);
	user.ajouterVehicule(VP);
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"Ajoutez un Camion"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	string niv2;//1c43H561298
		do
		{
			cout << "entrez un niv" << endl;
			getline(cin, niv2);
			if (!util::validerNiv(niv2))
			{
				cout << "niv invalide" << endl;
			}
		} while (!util::validerNiv(niv2)); //tant que le niv est faux on en demande un autre
		string immatriculation2;//L032006
		do
		{
			cout << "entrez une immatriculation" << endl;
			getline(cin, immatriculation2);
			if (!util::validationImmatriculationCamion(immatriculation2))
			{
				cout << "immatriculation invalide" << endl;
			}
		} while (!util::validationImmatriculationCamion(immatriculation2)); //tant que l'immatriculation est fausse on en demande une autre
		int poids;
		cout << "entrez le poids" << endl;
		while(!(cin>>poids)){
			cin.clear();
			cin.ignore(10000,'\n');
			cout << "entrez un nombre valide" << endl;
		}
		int nbe;
		cout << "entrez le nombre d'essieux" << endl;
		while(!(cin>>nbe)){
			cin.clear();
			cin.ignore(10000,'\n');
			cout << "entrez un nombre valide" << endl;
		}
		saaq::Camion cam = saaq::Camion(niv, immatriculation2,poids,nbe);
		user.ajouterVehicule(cam);
		cout<<user.reqProprietaireFormate();
	return 0;
}

