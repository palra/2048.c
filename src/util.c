#include "util.h"
#include <math.h>

/*! \fn nbDigits
 *
 *  Retourne le nombre de chiffres de lla représentation décimale d'un entier
 *  
 *  \param x : entier
 *  
*/
int nbDigits(int x)
{
    return (x != 0) ? (int) (log10 (abs (x))) + 1 : 1;
}