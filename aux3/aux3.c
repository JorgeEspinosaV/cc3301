#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reemplazo(char *ptr, int temp){
	printf("func 1: %s\n",ptr);	
	ptr -= temp;
	printf("func 2: %s\n",ptr);
	char *i = ptr;
	char *j = ptr;
	for (int k = 0;k < (temp);k++){
		*j=*i;
		j++;
	}
	*j='\0';
	printf("func 3: %s\n",ptr);
}

int main(void) {
	char cadena[] = "Aladina abarca muchas cosas";
	char patron[] = "dina";

	//declaramos e inicializamos los length
	int len_str = strlen(cadena);
	int len_pat = strlen(pat);
	//declaramos e inicializamos los pointers
	char *init_str = cadena; //apunta al inicio de la cadena
	char *init_pat = patron; // apunta al inicio del patron
	char *ptr_str = cadena;	// pointer con el cual recorreremos el string
	char *ptr_pat = patron; // pointer con el cual recorreremos el pat
	char *fin_str = init_str + len_str; // apunta al final del string '\0'
	char *fin_pat = init_pat + len_pat - 1; // apunta al final del patron
	
	while (ptr_str < fin_str){
		
	}
	return 0;
}
