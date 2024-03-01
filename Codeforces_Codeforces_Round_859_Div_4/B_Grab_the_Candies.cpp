#include <bits/stdc++.h>
using namespace std;

int main(){
    int tt, n, aux; 
    cin >> tt;
    while (tt--) {
        cin >> n;
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++){    
            cin >> aux;
            (!(aux % 2)) ? even+=aux : odd+=aux;
        }
        (even > odd) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}