#include <bits/stdc++.h>

using namespace std;




int main()
{
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


     return 0;
}