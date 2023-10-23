#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elim.h"

static int comp(const char *str,const char *pat, int n){
   while (n--){
      if(*str=='\0' || *str!=*pat){
         return 1;
      }
      str++;
      pat++;
   }
   return 0;
}

void eliminar(char *str, char *pat) {
   int len_pat = strlen(pat); // largo del patron
   char *ptr_escritura = str; // ptr que reescribira str sin el pat
   
   for (char *ptr_lectura = str; *ptr_lectura != '\0';ptr_lectura++){
      if(comp(ptr_lectura, pat, len_pat)==0) {
         ptr_lectura += len_pat-1;
      } else {
         *ptr_escritura = *ptr_lectura;
         ptr_escritura++;
      }
   }
   *ptr_escritura = '\0';
}

char *eliminados(char *str, char *pat) {
   int len_pat = strlen(pat); // largo del patron
   int len_str = strlen(str); // largo del str
   char *ptr_escritura = malloc(len_str+1);// creamos la nueva str
   char *ptr_init = ptr_escritura;
   for (char *ptr_lectura = str; *ptr_lectura != '\0';ptr_lectura++){
      if(comp(ptr_lectura,pat, len_pat)==0) {
         ptr_lectura += len_pat - 1;
      } else {
         *ptr_escritura = *ptr_lectura;
         ptr_escritura++;
      }
   }
   *ptr_escritura = '\0';
   return ptr_init;
}
