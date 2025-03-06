#include <bits/stdc++.h>
#include <time.h>

using namespace std;

vector<int> Gerador_De_Vetor_Maximal(int tamanho)
{
    srand(time(NULL));

    vector<int> Vetor(tamanho);
    vector<bool> VetorPosicao(tamanho,false);

    int NumeroPosicoes = floor(tamanho/2) + 1;
    int NumeroMaisRep = rand()%100;

    for(int i = 0; i < NumeroPosicoes; i++)
    {
        int posicao = rand()%tamanho;

        while(VetorPosicao[posicao])
        {
            posicao++;
            posicao %= tamanho;
        }

        VetorPosicao[posicao] = true;
        Vetor[posicao] = NumeroMaisRep;
    }

    for(int i = 0; i < tamanho; i++)
    {
        if(!VetorPosicao[i])
        {
            int elemento = rand()%100;
            Vetor[i] = elemento;
        }
    }

    cout << "Numero mais repetido (na geracao): " << NumeroMaisRep << endl;
    return Vetor;
}

vector<int> Gerador_De_Vetor(int tamanho)
{
    vector<int> v;
    srand(time(NULL));
    for(int i = 0; i < tamanho; i++)
    {
        v.push_back(rand()%100);
    }
    return v;
}

//-------------------------------------------------------------------------------------------------------------------------------
int majorIterativo(vector<int>& vetor, int tamanho)
{
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

//-------------------------------------------------------------------------------------------------------------------------------
int elementoMajoritarioDaC(vector<int>& vetor, int inicio, int fim)
{
    // Caso base: Se há apenas um elemento
    if (inicio == fim)
    {
        return vetor[inicio];
    }

    // Dividir o vetor em duas metades
    int meio = inicio + (fim - inicio) / 2;
    int numeroEsquerda = elementoMajoritarioDaC(vetor, inicio, meio);
    int numeroDireita = elementoMajoritarioDaC(vetor, meio + 1, fim);

    // Contar as ocorrências de cada número nas duas metades
    int contadorEsquerda = 0, contadorDireita = 0;
    for (int i = inicio; i <= fim; i++)
    {
        if (vetor[i] == numeroEsquerda) contadorEsquerda++;
        if (vetor[i] == numeroDireita) contadorDireita++;
    }

    // Retornar o número que aparece mais vezes
    if (contadorEsquerda > contadorDireita)
    {
        return numeroEsquerda;
    }
    else
    {
        return numeroDireita;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------
int combinar(vector<int> &A, int inicio, int meio, int fim, int numeroEsquerda, int numeroDireita) {
    int esq = inicio, dir = meio + 1;
    int tam = fim - inicio + 1;
    vector<int> D(tam);
    int posD = 0;

    while (esq <= meio && dir <= fim) {
        if (A[esq] <= A[dir]) {
            D[posD++] = A[esq++];
        } else {
            D[posD++] = A[dir++];
        }
    }
    while (esq <= meio) {
        D[posD++] = A[esq++];
    }
    while (dir <= fim) {
        D[posD++] = A[dir++];
    }

    int contaEsq = 0, contaDir = 0, elemMax = D[0], elemAtual = D[0];
    int contaMax = 0, contaAtual = 0;

    for (int i = 0; i < tam; i++) {
        if (D[i] == numeroEsquerda) {
            contaEsq++;
        } else if (D[i] == numeroDireita) {
            contaDir++;
        } else if (D[i] == elemAtual) {
            contaAtual++;
        } else {
            if (contaMax < contaAtual) {
                contaMax = contaAtual;
                elemMax = elemAtual;
            }
            elemAtual = D[i];
            contaAtual = 1;
        }
    }
    if (contaMax < contaAtual) {
        contaMax = contaAtual;
        elemMax = elemAtual;
    }

    for (int i = 0; i < tam; i++) {
        A[inicio + i] = D[i];
    }

    if (contaEsq > contaDir && contaEsq > contaMax) {
        return numeroEsquerda;
    } else if (contaDir > contaEsq && contaDir > contaMax) {
        return numeroDireita;
    }
    return elemMax;
}

int majorMelhorado(vector<int> &A, int inicio, int fim) {
    if (inicio == fim) {
        return A[inicio];
    }
    int meio = inicio + (fim - inicio) / 2;
    int numeroEsquerda = majorMelhorado(A, inicio, meio);
    int numeroDireita = majorMelhorado(A, meio + 1, fim);
    return combinar(A, inicio, meio, fim, numeroEsquerda, numeroDireita);
}

//-------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int n, opc = 0;
    vector<int> v;
    while(1)
    {
        //Escolha do tipo de vetor
        printf("\n1) Vetor com elemento Maximal garantido (mais lento)\n2) Vetor com elementos aleatorios\n3)Sair\nEscolha:");
        while(opc < 1 || opc > 3) cin >> opc;
        if(opc == 3) break;

        while(1){
            //Inserção do tamanho do vetor
            cout << "Insira valor de n (se <= 0 finaliza): ";
            cin >> n;
            if(n <= 0) break;

            //Gera o vetor
            if(opc ==2)v = Gerador_De_Vetor(n);
            else v = Gerador_De_Vetor_Maximal(n);

            //Calcula o tempo do iterativo
            clock_t inicioIterativo = clock();
            int resultadoIterativo = majorIterativo(v, n);
            clock_t fimIterativo = clock();
            double tempoIterativoSeg = double(fimIterativo - inicioIterativo) / CLOCKS_PER_SEC;

            cout << "Metodo | Resultado | Tempo (segundos)" << endl;
            cout << "Iterativo | " << resultadoIterativo << " | " << tempoIterativoSeg << endl;

            //Calcula o tempo do Divide and Conquer
            clock_t inicioDAC = clock();
            int resultadoDAC = elementoMajoritarioDaC(v, 0, n - 1);
            clock_t fimDAC = clock();
            double tempoDACSeg = double(fimDAC - inicioDAC) / CLOCKS_PER_SEC;

            cout << "Divide And Conquer | " << resultadoDAC << " | " << tempoDACSeg << endl;

            //Calcula o tempo do aprimorado
            clock_t inicioMelhor = clock();
            int resultadoMelhor = majorMelhorado(v,0,n-1);
            clock_t fimMelhor = clock();
            double tempoMelhorSeg = double(fimMelhor - inicioMelhor)/CLOCKS_PER_SEC;

            cout << "Divide And Conquer Melhorado | " << resultadoMelhor << " | " << tempoMelhorSeg << endl;
            //Limpa o vetor
            v.clear();
            cout << "\n\n\n";
        }
        //Limpa o vetor se ele não estiver vazio
        if(!v.empty()) v.clear();
    }
    return 0;
}
