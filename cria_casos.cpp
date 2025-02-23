#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
    map<int, int> ma;
    vector<int> v;

    srand(time(NULL));
    ofstream arq;
    ofstream arq2;
    arq2.open("casos(maximo).txt");
    arq.open("casos(teste).txt");

    if (!arq.is_open()) {
        return -1;
    }

    while (1) {
        int n, m;
        cin >> n;
        if (n == 0) break;

        ma.clear();
        v.clear();

        arq << n << endl;
        for (int i = 0; i < n; i++) {
            m = rand() % 100;
            ma[m]++;
            v.push_back(m);
            arq << m << " ";
        }

        arq << endl;
        arq << endl;


        vector<pair<int, int>> myVector(ma.begin(), ma.end());

        sort(myVector.begin(), myVector.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        arq2 << n << endl;
        arq2 << myVector[0].first << ": " << myVector[0].second << endl << endl;

        for (const auto& pair : myVector) {
            cout << pair.first << ": " << pair.second << endl;
        }
        cout << "\n\n\n";
    }

    return 0;
}
