#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;


int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if(n > 3) {
            cout << 1 << " " << 1 << nn;
            cout << n << " " << n << nn;
            bool izq = 1;
            bool der = 1;
            for (int i = 1; i <= n-2; i++) {
                if (i % 2 != 0) {
                    if(izq)  cout << i+1 << " " << 1;
                    else cout << 1 << " " << i+1;
                    izq = !izq;
                }
                else {
                    if(der) cout << n - i << " " << n;
                    else cout << n << " " <<n -i;
                    der = !der;
                }
                cout << nn;
            }
        }
        else {
            if(n == 3) {
                cout << 2 << " " << 1 << nn;
                cout << 2 << " " << 3 << nn;
                cout << 3 << " " << 1 << nn;
            }
            if(n == 2) {
                cout << 1 << " " << 1 << nn; 
                cout << 1 << " " << 2 << nn; 
            }
        }
        cout << nn;

    }
    return 0;
}