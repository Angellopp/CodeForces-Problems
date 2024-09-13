#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

const ll MX = 1e5 + 120;
bool isPrime[MX];
ll fact[MX];

vector<ll> primes;
 
void sieve() {
    fill(isPrime, isPrime + MX, true);
    isPrime[1] = false;
    for (ll i = 2; i < MX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            fact[i] = i;
        }
        for (ll j = 0; j < primes.size() && i * primes[j] < MX; j++) {
            isPrime[i * primes[j]] = false;
            fact[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}
int getDivisors(ll x) {
    ll ans = 1;
    while (x > 1) {
        ll f = fact[x]; 
        ll num = 1;
        ll sz = ans;
        while (x % f == 0) {
            num *= f;
            x /= f;
            ans += sz;
        }
    }
    return ans;
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    // sieve();
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector <int> div;
        for (int i = 1; i <= n; i++) {
            // cout << fact[i] << " ";
            if (n % i == 0) {
                div.emplace_back(i);
            }
        }
        for (auto x : div) {
            for (int i = 0; i < n; i++) {
                
            }
        }
        // for (auto x : div) cout << x << " ";
        cout << nn;

    }        

    return 0;
}