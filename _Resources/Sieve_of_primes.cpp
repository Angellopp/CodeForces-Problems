#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MX = 1e6 + 120;
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
ll getDivisors(ll x) {
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