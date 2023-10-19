#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"


int main(){
    char p_sec[100]; // palavra secreta
    char p_tela[100];
    int erros =0 ;
    char palavraOriginal[100];
    Sortear_Palavra(p_sec);
    Copiar_Palavra(p_sec, p_tela);

    while (1){
      forca(erros, p_sec);
      Comparar_Palavra(p_sec, p_tela, &erros);
    }
}