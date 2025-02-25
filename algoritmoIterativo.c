#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int elementoMaisFrequente (int* vet, int tam);
int* geraVetor (int tam);

int main(){
    int tam = 175000;
    int* vet = geraVetor(tam);
    if (vet == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }
    
    clock_t inicio = clock(); // Inicia a contagem de tempo
    int maisFreq = elementoMaisFrequente(vet, tam);
    clock_t fim = clock(); // Finaliza a contagem de tempo
    
    double tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("%d\n", maisFreq);
    printf("Tempo gasto: %f segundos\n", tempo_gasto);
    
    free(vet);
    return 0;
}

int elementoMaisFrequente (int* vet, int tam){
    int countMax = 0;
    int elementoMax = vet[0];
    
    for(int i = 0; i < tam; i++){
        int count = 0;
        for(int j = i; j < tam; j++){
            if(vet[i] == vet[j]){
                count++;
            }
        }
        if(count > countMax){
            countMax = count;
            elementoMax = vet[i];
        }
    }
    
    return elementoMax;
}

int* geraVetor(int tam){
    srand(time(NULL));

    int* vet = (int*)malloc(tam * sizeof(int));
    if (vet == NULL) {
        return NULL;
    }

    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 100;
    }

    return vet;
}
