/**
 * \file validationFormat.h
 * \brief fichier contenant l'interface des fonction de validation du niv et de l'immatriculation
 * \author Ferraris Pascal
 * \version 1.0
 * \date 2019-09-24
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
#include <string>
namespace util
{
const int poid[17] =
{ 8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3, 2 };
bool validerImmatriculation(const std::string& p_immatriculation);
bool validationImmatriculationPromenade(const std::string& p_immatriculation);
bool validationImmatriculationCamion(const std::string& p_immatriculation);
bool validerNiv(const std::string& p_niv);
} // namespace util

#endif /* VALIDATIONFORMAT_H_ */
