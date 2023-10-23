#include <stdio.h>
#include <string.h>

int main(){
	char buf[80];
	FILE *in = fopen("pers.txt", "r");
	FILE *out = fopen("datos.txt", "w");
	for(;;){
		if(fgets(buf, 80, in)==NULL)
			break;
		fputs(buf, out);
		puts(buf);
	}
	return 0;
}
