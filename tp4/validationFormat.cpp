/**
 * \file validationFormat.cpp
 * \brief fichier contenant l'implementation des fonction de validation du niv et de l'immatriculation
 * \author Ferraris Pascal
 * \version 1.0
 * \date 2019-09-24
 */

#include "validationFormat.h"
using namespace std;
namespace util {
/**
 * \brief retourne si la chaine de caractere est une plaque d'immatriculation valide :
 * avec A une lettre majuscule quelconque sauf 'O', 0 un chiffre quelconque , les espace et lettre autres que A sont importantes
 * L000000  (1)
 * 000A000  (2)
 * 000 AAA  (3)
 * A00 AAA  (4)
 * AAA 000  (5)
 * AAAA     (6)
 * \param[in] p_immatriculation une chaine de caractere ne contenant que la plaque d'imatriculation
 * \return valide un booleen indiquant si la plaque est valide
 */
bool validerImmatriculation(const std::string& p_immatriculation) {
	if (p_immatriculation.length() == 7) //comme on donne la chaine par reference on peut s'en servir comme un objet
			{ // on regarde si la plaque fait 7 caracteres
		char ch[7];
		p_immatriculation.copy(ch, 7, 0); //on copy la chaine dans un tableau de char pour faire des test plus facilement

		if (isdigit(ch[3])) //test du (1), seul a avoir un chiffre en 4ieme position
				{
			if (ch[0] == 'L') // valide si on a un L et que des chiffres
					{
				for (int i = 1; i < 7; i++) {
					if (!isdigit(ch[i])) //si on a pas un chiffre dans la suite la plaque n'est pas valide
							{
						return false;
					}
				}
				return true; //si toutes les characteres ont ete verifies alors la plaque est validee
			}
			return false; // pas besoin de else car on a des return dans le if
		}

		else if (isupper(ch[3]) && ch[3] != 'O') // test de (2) , seul a avoir une lettre en position 4
				{
			for (int i = 0; i < 3; i++) {
				if (!isdigit(ch[i]) || !isdigit(ch[4 + i])) //si on a pas un chiffre dans la suite la plaque n'est pas valide
						{ //on ne test pas la position 4 car comme dit plut haut c'est une lettre
					return false;
				}
			}
			return true; //si toutes les characteres ont ete verifies alors la plaque est validee
		} else if (ch[3] == ' ') //(3) (4) et (5) ont un espace
				{
			if (isdigit(ch[0]) || (isupper(ch[0]) && ch[0] != 'O')) // on regarde si le premier caractere est un chiffre ou
					{ //une lettre valide
				if (isdigit(ch[1]) && isdigit(ch[2])) //test de (3) et (4) puis si il y a deux chiffres
						{
					for (int i = 4; i < 7; i++) //on a deja teste l'espace donc il ne reste que 3 lettres
							{
						if (!isupper(ch[i]) || ch[i] == 'O') {
							return false;
						}
					}
					return true;
				} else if (isupper(ch[1]) && ch[1] != 'O' && isupper(ch[1])
						&& ch[1] != 'O') //test de (5) on regarde si on a deux autres lettres
								{
					for (int i = 4; i < 7; i++) //on a deja teste l'espace donc il ne reste que 3 chiffres
							{
						if (!isdigit(ch[i])) {
							return false;
						}
					}
					return true;
				} else {
					return false;
				}

			}
		} //sinon la plaque est fausse
		return false;

	}

	else if (p_immatriculation.length() == 4) //test de (6)
			{
		char ch[4];
		p_immatriculation.copy(ch, 4, 0); //on copy la chaine dans un tableau de char pour faire des test plus facilement
		for (int i = 0; i < 4; i++) {
			if (!isupper(ch[i]) || ch[i] == 'O') //si le caractere n'est pas une majuscule ou est 'O'
					{
				return false; //la plaque est fausse
			}
		}
		return true; //si toutes les lettres ont ete verifiees alors la plaque est validee
	} else {
		return false;
	}

}

/**
 * \brief retourne si la chaine de caractere est une plaque d'immatriculation valide pour un Vehicule de promenade :
 * avec A une lettre majuscule quelconque sauf 'O', 0 un chiffre quelconque , les espace et lettre autres que A sont importantes
 * 000A000  (1)
 * 000 AAA  (2)
 * A00 AAA  (3)
 * AAA 000  (4)
 * AAAA     (5)
 * \param[in] p_immatriculation une chaine de caractere ne contenant que la plaque d'imatriculation
 * \return  un booleen indiquant si la plaque est valide
 */
bool validationImmatriculationPromenade(const std::string& p_immatriculation) {
	if (p_immatriculation.length() == 7) //comme on donne la chaine par reference on peut s'en servir comme un objet
			{ // on regarde si la plaque fait 7 caracteres
		char ch[7];
		p_immatriculation.copy(ch, 7, 0); //on copy la chaine dans un tableau de char pour faire des test plus facilement

		if (isupper(ch[3]) && ch[3] != 'O') // test de (1) , seul a avoir une lettre en position 4
				{
			for (int i = 0; i < 3; i++) {
				if (!isdigit(ch[i]) || !isdigit(ch[4 + i])) //si on a pas un chiffre dans la suite la plaque n'est pas valide
						{ //on ne test pas la position 4 car comme dit plut haut c'est une lettre
					return false;
				}
			}
			return true; //si toutes les characteres ont ete verifies alors la plaque est validee
		} else if (ch[3] == ' ') //(2) (3) et (4) ont un espace
				{
			if (isdigit(ch[0]) || (isupper(ch[0]) && ch[0] != 'O')) // on regarde si le premier caractere est un chiffre ou
					{ //une lettre valide
				if (isdigit(ch[1]) && isdigit(ch[2])) //test de (2) et (3) puis si il y a deux chiffres
						{
					for (int i = 4; i < 7; i++) //on a deja teste l'espace donc il ne reste que 3 lettres
							{
						if (!isupper(ch[i]) || ch[i] == 'O') {
							return false;
						}
					}
					return true;
				} else if (isupper(ch[1]) && ch[1] != 'O' && isupper(ch[1])
						&& ch[1] != 'O') //test de (4) on regarde si on a deux autres lettres
								{
					for (int i = 4; i < 7; i++) //on a deja teste l'espace donc il ne reste que 3 chiffres
							{
						if (!isdigit(ch[i])) {
							return false;
						}
					}
					return true;
				} else {
					return false;
				}

			}
		} //sinon la plaque est fausse
		return false;

	}

	else if (p_immatriculation.length() == 4) //test de (5)
			{
		char ch[4];
		p_immatriculation.copy(ch, 4, 0); //on copy la chaine dans un tableau de char pour faire des test plus facilement
		for (int i = 0; i < 4; i++) {
			if (!isupper(ch[i]) || ch[i] == 'O') //si le caractere n'est pas une majuscule ou est 'O'
					{
				return false; //la plaque est fausse
			}
		}
		return true; //si toutes les lettres ont ete verifiees alors la plaque est validee
	} else {
		return false;
	}
}
/**
 * \brief retourne si la chaine de caractere est une plaque d'immatriculation valide pour un Camion soit un L suivit de 6 chiffres
 * \param[in] p_immatriculation une chaine de caractere ne contenant que la plaque d'imatriculation
 * \return  un booleen indiquant si la plaque est valide
 */
bool validationImmatriculationCamion(const std::string& p_immatriculation) {
	if (p_immatriculation.length() == 7) //comme on donne la chaine par reference on peut s'en servir comme un objet
			{ // on regarde si la plaque fait 7 caracteres
		char ch[7];
		p_immatriculation.copy(ch, 7, 0); //on copy la chaine dans un tableau de char pour faire des test plus facilement
		if (ch[0] == 'L') // valide si on a un L et que des chiffres
				{
			for (int i = 1; i < 7; i++) {
				if (!isdigit(ch[i])) //si on a pas un chiffre dans la suite la plaque n'est pas valide
						{
					return false;
				}
			}
			return true; //si toutes les characteres ont ete verifies alors la plaque est validee
		}
	}
	return false; // pas besoin de else car on a des return dans le if
}

/**
 * \brief retourne si la chaine de caractere est un NIV valide :
 *   on suit l'algorithm suivant : https://en.wikibooks.org/wiki/Vehicle_Identification_Numbers_(VIN_codes)/Check_digit
 * \param[in] p_niv une chaine de caractere ne contenant que le niv
 * \return valide un booleen indiquant si le numero est valide
 */
bool validerNiv(const std::string& p_niv) {
	if (p_niv.length() == 17) //comme on donne la chaine par reference on peut s'en servir comme un objet
			{
		char ch[17];
		p_niv.copy(ch, 17, 0); //on copy la chaine dans un tableau de char pour faire des operation plus facilement plus facilement
		int transliterating[17]; //tableau d'entier qui va contenir la convertion des caracteres.
		for (int i = 0; i < 17; i++) {
			switch (ch[i])
			// d'abord on convertie les caracteres.
			{
			case '0':
				transliterating[i] = 0;
				break;
			case 'A': //dans ces 3 cas on a le meme effet donc on peut ne mettre qu'une fois l'instruction car dans un switch on continue
			case 'J': //les instruction jusqu'a un break ou à la fin du default une fois rentrer dans un case
			case '1':
				transliterating[i] = 1;
				break;
			case 'B':
			case 'K':
			case 'S':
			case '2':
				transliterating[i] = 2;
				break;
			case 'C':
			case 'L':
			case 'T':
			case '3':
				transliterating[i] = 3;
				break;
			case 'D':
			case 'M':
			case 'U':
			case '4':
				transliterating[i] = 4;
				break;
			case 'E':
			case 'N':
			case 'V':
			case '5':
				transliterating[i] = 5;
				break;
			case 'F':
			case 'W':
			case '6':
				transliterating[i] = 6;
				break;
			case 'G':
			case 'P':
			case 'X':
			case '7':
				transliterating[i] = 7;
				break;
			case 'H':
			case 'Y':
			case '8':
				transliterating[i] = 8;
				break;
			case 'R':
			case 'Z':
			case '9':
				transliterating[i] = 9;
				break;
			default: // si le symbole ne fait pas partie des caracteres precedents la plaque est fausse
				return false;
			}
		}

		for (int i = 0; i < 17; i++) // puis on rajoute les poids
				{
			transliterating[i] *= poid[i]; //poid est une constante declaree dans le .h pour retenir les poids
		}

		int somme = 0; // puis on fait la somme du tableau
		for (int i = 0; i < 17; i++) {
			somme += transliterating[i];
		}

		somme = somme % 11; //puis on fait le modulo par 11
		if (somme < 10) { // conversion de char en int par Foo Bah
						  //https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
			return (somme == ((int) ch[8] - (int) '0'));// on renvoit si le modulo est egale au caractere 9 dans la chaine de depart converti en entier
		} else //le modulo est egale à 10 donc on regarde si on a bien un x dans la chaine de depart
		{
			return (ch[8] == 'X'); // et on renvoit sa veracite
		}
	}
	//si le niv ne fait pas 17 caracteres il n'est pas valide
	return false;
}
} // namespace util
