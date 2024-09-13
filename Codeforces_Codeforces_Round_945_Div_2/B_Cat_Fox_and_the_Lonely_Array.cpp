#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector <int> pre(n), suf(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) pre[i] = v[i];
            else pre[i] = pre[i-1] | v[i];
        }
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) suf[i] = v[i];
            else suf[i] = suf[i+1] | v[i];
        }

        for (int i = 0; i < n; i++) {
            cout << pre[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << suf[i] << " ";
        }
        cout << "\n";
        int xx;
        for (int i = 0; i < n; i++) {
            if(pre[i] == suf[n-1-i]){
                xx = i;
                break;  
            }
        }
        if (xx == n-1) {
            cout << n << "\n";
        }
        else {
            for (int k = xx; k < n; k++) {
                if(pre[k] != suf[n-1-k]) {
                    continue;
                }
                else {
                    int aux = pre[k];
                    bool can = 1;
                    for (int j = 0; j + k + 1< n; j++) {
                        int aux2 = 0;
                        for (int x = 0; x < k+1; x++) {
                            aux2 |= v[j+x];
                        }
                        // cout << "aux2" << " : " << aux2 << "\n"; 
                        if (aux != aux2) {
                            can = 0;
                            break;
                        }
                    }
                    if (can) {
                        cout << k+1 << "\n";
                        break;
                    }
                    // else {
                    //     cout << k+1 << "\n";
                    //     break;
                    // }
                }
            }
        }
    }
    
}