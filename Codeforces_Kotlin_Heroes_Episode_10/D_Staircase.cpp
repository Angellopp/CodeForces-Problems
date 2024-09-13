#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    int a[300000+2];
    while(tt--) {
        int n;
        cin >> n;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += 1ll * 2 * a[i];
        }
        a[n] = 0;
        int aux1, cont = 0;
        for (int i = 0; i < n + 1; i++) {
            if(a[i] != 0) {
                if(cont % 2 == 0) {
                    aux1 = max(aux1, a[i]);
                }
                cont++;
            }
            else {
                if(cont % 2 == 1) sum -= 1ll * aux1;
                cont = 0;
                aux1 = 0;
            }
        }
        cout << sum << endl;
    }
}