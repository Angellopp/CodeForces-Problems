#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <bool> filas(4), columnas(3);
    bool cero = 0, si = 0, nu = 0;
    for (auto& c : s) {
        if(c == '0') cero = 1;
        else {
            if(c == '7') si = 1;
            if(c == '9') nu = 1;
            filas[((c-'0') - 1) / 3] = 1;
            columnas[((c-'0')-1)%3] = 1;
        };
    }
    if((filas[0] and cero) or ((filas[0] and filas[2] and columnas[0] and columnas[2]) and (si or nu))) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}
