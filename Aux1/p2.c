#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// P2
// Programe la funcion int decimal(int binario), a la cual usted le entrega un numero
// decimal representando a un binario y debe retornar el numero decimal al cual corresponda dicha representacion en bits, es decir:
// >> ./aDecimal 1001
// 9

// declaramos decimal
int decimal(char *binario);

// declaramos potencia
int power(int base, int exponente);

int main(int argc, char *argv[]) {
	char *binario = argv[1];
	int total = 0;
	total = decimal(binario);
	printf("%d\n", total);
	return 0;
}


int decimal(char* binario) {
	int n = strlen(binario);
	int resultado = 0;
	int tmp = 0;
	int tmp_i = 0;
	int pow_2 = 0;
	for (int i = 0; i < n; i++) {
		char str = binario[i];
		tmp_i = binario[i] - '0';
		tmp = resultado;
		pow_2 = power(2, n-1-i);
		resultado = tmp + pow_2*tmp_i;
	}
	return resultado;
}

int power(int base, int exponente) {
	int resultado = 1;
	int tmp = 0;
	for (int i = 0; i < exponente; i++){
		tmp = resultado;
		resultado = tmp * base;
	}
	return resultado;
}
