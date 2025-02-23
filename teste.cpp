#include <bits/stdc++.h>
#include <chrono>

using namespace std;




int main()

{

    auto inicio = std::chrono::high_resolution_clock::now();
    map<int,int>  ma;
    vector<int> v;

    srand(time(NULL));

    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        m = rand()%100;
        ma[m]++;
        v.push_back(m);
    }

    for(auto a : v){
        cout << a << " ";
    }

    cout << "\n\n\n";

    vector<pair<int, int>> myVector(ma.begin(), ma.end());

    sort(myVector.begin(), myVector.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Ordena pelo segundo elemento (valor)
    });

    for (const auto& pair : myVector) {
        cout << pair.first << ": " << pair.second << endl;
    }

    auto resultado = std::chrono::high_resolution_clock::now() - inicio;
    long long seconds = std::chrono::duration_cast<std::chrono::seconds>(resultado).count();

    printf("O tempo de execução foi %lld segundos", seconds);



     return 0;
}