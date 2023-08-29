#include <stdio.h>

#include "suma.h"

Bcd sumaBcd(Bcd x, Bcd y) {
/* 
Inicializamos el acarreo (si suma de digitos, x_i + y_i)
es mayor a 9
*/
    Bcd acarreo = 0;
// Inicializamos el total el cual retorna esta funcion
    Bcd total = 0;
//for loop que itera para obtener los digitos (x_i, y_i)
//y sumarlos
    for(int i = 0; i<16; i++){
// obtenemos los digitos x_i, y_i
       Bcd x_i = (x>>(i*4)) & 0xf;
       Bcd y_i = (y >> (i*4)) & 0xf;
//sumamos los digitos mas el acarreo
       Bcd suma=x_i+y_i+acarreo;
//volvemos a definir el acarreo (si suma es mayor a 10, acarreo = 1,
//de lo contrario es 0)
       acarreo = suma>=10?1:0;
//ajustamos el digito entre [0,9] (BCD)
       suma%=10;
//Colocamos el digito calculado en el total
       total|=(suma<<(i*4));
    }
//verificamos que no haya overflow (desbordamiento > 0xfff...fff)
    if (acarreo) {
       return 0xffffffffffffffff;
    }
    return total;
}
