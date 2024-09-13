#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define jk(n) cout << "<[" << #n << "] = " << n << ">" << nn
ll MOD = 998244353;
using namespace std;

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        vector <ll> v(4);
        ll sum = 0;
        for (int i = 0; i < 4; i++) {
            cin >> v[i];
            sum += v[i];
        }
        ll n = sqrt(2*sum) + 1;
        ll n1 = sqrt(2*v[3]);
        ll n0 = sqrt(2*v[0]);

        if (v[0] != 0) n1 = n - ++n0;
        else n0 = n - ++n1;
    
        if (n1 * (n1 - 1) != 2 * v[3] or n0 * (n0 - 1) != 2 * v[0] or n * (n - 1) != 2 * sum or n1 + n0 != n) {
            cout << "Impossible" << nn;
            return 0;
        }
        int g0 = 0;
        int r = n1;
        if (n1 != 0) {
            g0 = v[1] / n1;
            r = v[1] % n1; 
        }
        int g1 = (n0 - g0 != 0);
        for (int i = 0; i < g0; i++) cout << "0";  
        for (int i = 0; i < n1 - r; i++) cout << "1";  
        for (int i = 0; i < g1; i++) cout << "0";  
        for (int i = 0; i < r; i++) cout << "1";  
        for (int i = 0; i < n0 - g0 - g1; i++) cout << "0";
    }
    return 0;
}