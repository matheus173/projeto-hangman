#include <stdio.h>
#include <Stdlib.h>
#include <String.h>
#include<time.h>

    void forca(int estado,char *p_sec){
        if(estado == 0){
            printf("\n------------------");
            printf("\n|                |");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n-\n");
            printf("      6 tentativas!\n\n");
            } else if(estado ==1){
                printf("\n------------------");
                printf("\n|                |");
                printf("\n|                0");
                printf("\n|");
                printf("\n|");
                printf("\n|");
                printf("\n|");
                printf("\n\n-");
                printf("      5 tentativas!\n\n");
            } else if(estado ==2){
                    printf("\n------------------");
                    printf("\n|                |");
                    printf("\n|                0");
                    printf("\n|                |");
                    printf("\n|");
                    printf("\n|");
                    printf("\n|");
                    printf("\n\n-");
                    printf("      4 tentativas!\n\n");
            }else if(estado == 3){

                printf("\n------------------");
                printf("\n|                |");
                printf("\n|                0");
                printf("\n|               -|");
                printf("\n|");
                printf("\n|");
                printf("\n|");
                printf("\n\n-");
                printf("      3 tentativas!\n\n");
            } else if(estado == 4){

                printf("\n------------------");
                printf("\n|                |");
                printf("\n|                0");
                printf("\n|               -|-");
                printf("\n|");
                printf("\n|");
                printf("\n|");
                printf("\n\n-");
                printf("      2 tentativas!\n\n");
            }   else if(estado == 5) {

                    printf("\n------------------");
                    printf("\n|                |");
                    printf("\n|                0");
                    printf("\n|               -|-");
                    printf("\n|               /");
                    printf("\n|");
                    printf("\n|");
                    printf("\n\n-");
                    printf("      1 tentativa!\n");
                    printf("      O fim esta proximo!\n\n");
            }   else if (estado == 6){

                    printf("\n------------------");
                    printf("\n|                |");
                    printf("\n|                0");
                    printf("\n|               -|-");
                    printf("\n|               / \\");
                    printf("\n|");
                    printf("\n|         Pedeu o game!");
                    printf("\n-");
                    printf("Palavra secreta: %s\n", p_sec);
                    exit(1);
            }
        }

       void Sortear_Palavra(char *palavra) {
    // Defina aqui um array de palavras que você deseja usar no jogo
    char *palavras[] = {"computador", "programacao", "jogos", "desenvolvimento", "algoritmo", "openai"};

    // Obtém o número de palavras no array
    int numPalavras = sizeof(palavras) / sizeof(palavras[0]);

    // Inicializa a semente para geração de números aleatórios
    srand(time(NULL));

    // Sorteia um índice aleatório para selecionar uma palavra do array
    int indice = rand() % numPalavras;

    // Copia a palavra sorteada para a variável 'palavra'
    strcpy(palavra, palavras[indice]);
}
        
       void Copiar_Palavra(char *p_sec, char *p_tela){
            strcpy (p_tela, p_sec);

            for(int i=0; i< strlen(p_tela);i++){
                p_tela[i] = '_';
            }
        }

       void Comparar_Palavra(char *p_sec, char *p_tela, int *erros) {
            printf("Adivinhe: ");
            for (int i = 0; i < strlen(p_tela); i++) {
                printf("%c ", p_tela[i]);
        }

            // Receber a letra
            printf("\nLetra: ");
            char letra;
            scanf(" %c", &letra);

        // Verifica se a letra está correta
        int sera_que_errou = 1;
        for (int i = 0; i < strlen(p_tela); i++) {
            if (letra == p_sec[i]) { // Correto
                p_tela[i] = letra;
                sera_que_errou = 0;
            }
        }

        // Atualiza o estado da forca se a letra estiver errada
        if (sera_que_errou) {
            (*erros)++; // Incrementa o contador de erros
        }
        
        int acertou = 1;
        for (int i = 0; i < strlen(p_tela); i++) {
        if (p_tela[i] != p_sec[i]) {
            acertou = 0;
            break;
        }
    }

        if (acertou) {

        printf("Palavra secreta: ");
        for (int i = 0; i < strlen(p_tela); i++) {
            printf("%c", p_tela[i]);
        }
        printf("\nVocê ganhou!");
        printf("\nYou Win!!");
        exit(1);
    } 

}