
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eliminar(char *cadena, char *patron){
	int len_cad = strlen(cadena);
	int len_pat = strlen(patron);
	char *ptr_esc = cadena;
	for (char *ptr_lectura = cadena; *ptr_lectura != '\0';ptr_lectura++){
		printf("lectura: %s, escritura: %s, cadena: %s\n",ptr_lectura,ptr_esc,cadena);
		printf("ptr lectura: %p, ptr escritura: %p\n", ptr_lectura, ptr_esc);
		printf("-------------------------------------------\n");
		if(strncmp(ptr_lectura,patron, len_pat)==0) {
			ptr_lectura += len_pat - 1;		
		} else {
			*ptr_esc = *ptr_lectura;
			ptr_esc++;
		}
	}
	*ptr_esc = '\0';
}

int main() {
	char cadena[]  = "hola soy jorge";
	char pat[] = "soy";
	eliminar(cadena, pat);
	printf("cadena: %s, pat: %s\n", cadena, pat);
}
