#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
ll MOD = 998244353;
using namespace std;

const ll MX = 1e5+5;
int fact[MX];
bool isPESI[MX];
vector <int> PESI;

void sieve(int n) {
    fill(isPESI, isPESI + n, true);
    PESI.emplace_back(1);
    for (ll i = 2; i <= n; i++) {
        if (isPESI[i] == 1 and n % i == 0) {
            for (int j = i; j <= n; j += i) {
                isPESI[j] = 0; 
            }
        }
        if (isPESI[i] == 1) PESI.emplace_back(i);
    }
}   
int main() {
    fast_io;
    int tt = 1;
    while (tt--) {
        int n;
        cin >> n;
        sieve(n);
        ll res = 1;
        for (int i = 0; i < PESI.size() - 1; i++){
            res *= PESI[i];
            res %= n;
        }
        if (res == 1 and n > 2) PESI.pop_back();

        cout << PESI.size() << nn;
        for (int i : PESI)
            cout << i << " ";
         
        cout << nn;
        
    }
    return 0;
}