#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <vector <char>> v(n, vector <char> (n));
    vector <vector <char>> ans(n, vector <char> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    vector <int> aux1(n), aux2(n), aux3(n), aux4(n);
    for(int i = 0; i < n-1; i++) {
        aux1[i] = v[0][i];
    }
    for(int i = 0; i < n-1; i++) {
        aux2[i] = v[i][n-1];
    }
    for(int i = 0; i < n-1; i++) {
        aux3[i] = v[n-1][n-1-i];
    }
    for(int i = 0; i < n-1; i++) {
        aux4[i] = v[n-1-i][0];
    }
    for (int i = 0; i < n-1; i++) {
        v[0][i+1] = aux1[i];
    }
    for (int i = 0; i < n-1; i++) {
        v[i+1][n-1] = aux2[i];
    }
    for (int i = 0; i < n-1; i++) {
        v[n-1][n-2-i] = aux3[i];
    }
    for (int i = 0; i < n-1; i++) {
        v[n-i-2][0] = aux4[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }


    
    
}