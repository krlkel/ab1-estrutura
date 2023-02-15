#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int troca(char item)
{
    if (item == 'q'|| item == 'h' || item == 'í') return 1; 
    else if (item == 'w' || item == 'z' || item == 'm') return 2;
    else if (item == 'e' || item == 'g' || item == 'é') return 3;
    else if (item == 'r' || item == 'x' || item == 'ó') return 4;
    else if (item == 't' || item =='f' || item == 'ç') return 5;
    else if (item =='y' || item =='c' || item == 'õ') return 6;
    else if (item =='u' || item =='d' || item == 'l') return 7;
    else if (item =='i' || item =='v' || item == 'ô') return 8;
    else if (item == 'o' || item =='s' || item == 'k') return 9;
    else if (item =='p' || item =='b' || item =='â') return 10;
    else if (item == 'á' || item =='a' || item =='j') return 11;
    else if (item == 'ã' || item =='n' || item == 'ê') return 12;
}

int resto1(int soma){
    if(soma % 4 == 0) printf("você irá desenhar a planta de uma casa com 1 andar\n");
    else if(soma % 4 == 1) printf("você irá desenhar a planta de uma casa com 2 andares\n");
    else if(soma % 4 == 2) printf("você irá desenhar a planta de uma casa com 2 andares e um sótão\n");
    else if(soma % 4 == 3) printf("você irá desenhar a planta de uma casa com 2 andares e um porão\n");    
}

int resto2(int soma){
    if(soma % 4 == 0) printf("você irá desenhar uma casa hexagonal\n");
    else if(soma % 4 == 1) printf("você irá desenhar uma casa em forma de circunferência\n");
    else if(soma % 4 == 2) printf("você irá desenhar uma casa quadrada\n");
    else if(soma % 4 == 3) printf("você irá desenhar uma casa retangular\n");
}

int resto3(int soma){
    if(soma % 4 == 0) printf("a casa terá um local de música\n");
    else if(soma % 4 == 1) printf("a casa terá uma sala de ginástica\n");
    else if(soma % 4 == 2) printf("a casa terá uma sala de estudo\n");
    else if(soma % 4 == 3) printf("a casa terá uma sala de jogos\n");
}

int resto4(int soma){
    if(soma % 3 == 0) printf("a casa terá 3 quartos, 2 banheiros e 1 closet\n");
    else if(soma % 3 == 1) printf("a casa terá 2 quartos, 2 banheiro, 2 closets\n");
    else if(soma % 3 == 2) printf("a casa terá 3 quartos, 2 banheiros e 1 closet\n");
    else if(soma % 3 == 3) printf("a casa terá 2 quartos, 2 banheiros, 2 closets\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char nome[4][25], aux[25];
    printf("Digite seu nome: ");
    scanf("%s %s %s %s", nome[0], nome[1], nome[2], nome[3]);
    nome[0][0] = tolower(nome[0][0]);
    nome[1][0] = tolower(nome[1][0]);
    nome[2][0] = tolower(nome[2][0]);
    nome[3][0] = tolower(nome[3][0]);
    //printf("%s %s %s %s \n", nome[0], nome[1], nome[2], nome[3]);
    for (int i = 1; i < 4; i++) { 
        for (int j = 1; j < 4; j++) {
            if (strcmp(nome[j - 1], nome[j]) > 0) {
            strcpy(aux, nome[j - 1]);
            strcpy(nome[j - 1], nome[j]);
            strcpy(nome[j], aux);
            }
        }
    }
    //printf("%s %s %s %s \n", nome[0], nome[1], nome[2], nome[3]);
    int soma1 = 0;
    for (int i = 0; i < strlen(nome[0]); i++){
        soma1 += troca(nome[0][i]);
    }
    int soma2 = 0;
    for (int q = 0; q < strlen(nome[1]);q++){
        soma2 += troca(nome[1][q]);
    }
    int soma3 = 0;
    for (int p = 0; p < strlen(nome[2]); p++){
        soma3 += troca(nome[2][p]);
    }
    int soma4 = 0;
    for (int l = 0; l < strlen(nome[3]); l++){
        soma4 += troca(nome[3][l]);
    }
   //int soma_total = soma1 + soma2 + soma3 + soma4;
    //printf("%d", soma_total);
    resto1(soma1);
    resto2(soma2);
    resto3(soma3);
    resto4(soma4);
    return 0;
}

