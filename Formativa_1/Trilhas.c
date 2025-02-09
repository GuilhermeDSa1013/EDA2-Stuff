#include <stdio.h>
#include <limits.h>

#define VALORMAXIMO INT_MAX

int main(){
    //declarando variáveis
    int N, M, Ha, Hb;
    int esfMin = VALORMAXIMO;
    int melhorTrilha;
    int esf1, esf2;

    scanf("%d", N); //lendo o numero de trilhas

    for(int i = 1; i <= N; i++){
        esf1, esf2 = 0; //ambas as trilhas comecam com esforço 0
        scanf("%d %d", &M, &Ha);

        for (int j = 1; j < M; j++){
            scanf("%d", &Hb);

            //começo a fazer as comparações
            if (Ha > Hb){
                esf1 += Ha - Hb; //eu vou somando o esforço, fazendo a subtração dos pontos de altura
            } else {
                esf2 += Hb - Ha;
            }

            Ha = Hb;
        }

        while (getchar() != '\n');

        if (esf1 > esf2){
            esf1 = esf2;
        }

        if (esf1 < esfMin){
            esfMin = esf1;
            melhorTrilha = i;
        }
    }

    printf("%d\n", melhorTrilha);

    return 0;
}