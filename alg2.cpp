#include <bits/stdc++.h>
#include <time.h>

using namespace std;

vector<int> Gerador_De_Vetor(int tamanho){
    srand(time(NULL));

    vector<int> Vetor(tamanho);
    vector<bool> VetorPosicao(tamanho,false);

    int NumeroPosicoes = floor(tamanho/2) + 1;
    int NumeroMaisRep = rand()%100;

    for(int i = 0; i < NumeroPosicoes; i++){
        int posicao = rand()%tamanho;

        while(VetorPosicao[posicao]){
            posicao++;
            posicao %= tamanho;
        }

        VetorPosicao[posicao] = true;
        Vetor[posicao] = NumeroMaisRep;
    }

    for(int i = 0; i < tamanho; i++)
    {
        if(!VetorPosicao[i]){
            int elemento = rand()%100;
            Vetor[i] = elemento;
        }
    }

    cout << "Numero mais repetido (na geracao): " << NumeroMaisRep << endl;
    return Vetor;
}

vector<int> Gerador_De_Vetor2(int tamanho){
    vector<int> v;
    srand(time(NULL));
    for(int i = 0; i < tamanho;i++){
        v.push_back(rand()%100);
    }
    return v;
}

int NumeroMaisRepetidoNaive(vector<int> vetor, int tamanho){
    int NumeroMaisRepetido = 0;
    int ContadorTotal = 0;

    for(int i = 0; i < tamanho; i++)
    {
        int ContadorAtual = 1;
        for(int j = i + 1; j < tamanho; j++)
        {
            if(vetor[j] == vetor[i]) ContadorAtual++;
        }
        
        if(ContadorAtual > ContadorTotal)
        {
            ContadorTotal = ContadorAtual;
            NumeroMaisRepetido = vetor[i];
        }
    }
    return NumeroMaisRepetido;
}


int NumeroMaisRepetidoDivAndConquer(vector<int>& vetor, int inicio, int fim) {
    // Caso base: Se há apenas um elemento
    if (inicio == fim) {
        return vetor[inicio];
    }

    // Dividir o vetor em duas metades
    int meio = inicio + (fim - inicio) / 2;
    int numeroEsquerda = NumeroMaisRepetidoDivAndConquer(vetor, inicio, meio);
    int numeroDireita = NumeroMaisRepetidoDivAndConquer(vetor, meio + 1, fim);

    // Contar as ocorrências de cada número nas duas metades
    int contadorEsquerda = 0, contadorDireita = 0;
    for (int i = inicio; i <= fim; i++) {
        if (vetor[i] == numeroEsquerda) contadorEsquerda++;
        if (vetor[i] == numeroDireita) contadorDireita++;
    }

    // Retornar o número que aparece mais vezes
    if (contadorEsquerda > contadorDireita) {
        return numeroEsquerda;
    } else {
        return numeroDireita;
    }
}
int main()
{
    int n;
    vector<int> v;

    while(1)
    {
        cout << "Insira valor de n (se <= 0 finaliza): ";
        cin >> n;
        if(n <= 0) break;

        vector<int> v = Gerador_De_Vetor(n);

        /*clock_t inicioNaive = clock();
        int resultadoNaive = NumeroMaisRepetidoNaive(v, n);
        clock_t fimNaive = clock();
        double tempoNaiveSeg = double(fimNaive - inicioNaive) / CLOCKS_PER_SEC;

        cout << "Metodo | Resultado | Tempo (segundos) | Tempo (milissegundos)" << endl;
        cout << "Ingenuo | " << resultadoNaive << " | " << tempoNaiveSeg << endl;*/

        clock_t inicioDAC = clock();
        int resultadoDAC = NumeroMaisRepetidoDivAndConquer(v, 0, n - 1);
        clock_t fimDAC = clock();
        double tempoDACSeg = double(fimDAC - inicioDAC) / CLOCKS_PER_SEC;

        cout << "Divide And Conquer | " << resultadoDAC << " | " << tempoDACSeg << endl;

        v.clear();
        cout << "\n\n\n";
    }

    return 0;
}
