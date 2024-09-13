#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MX = 1e7 + 120;
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

int main() {
    sieve();
    ll n;
    cin >> n;
    ll mx = 0;
    bool found = 0;
    set <ll> s;
    for (ll i = 1; i <= n; i++) {
        ll n1 = i;
        ll n2 = i+1;

        (n1 % 2 == 0) ? n1 /= 2 : n2 /= 2 ;
        ll gcd = __gcd(n1, n2);
        n1 /= gcd;
        n2 /= gcd;

        ll ans = getDivisors(n1) * getDivisors(n2) * getDivisors(gcd) * getDivisors(gcd);
        s.insert(ans);
        mx = max(mx, ans);

        if(ans >= 500 and found == 0) {
            cout <<"("<< i << " * " << i+1 << ")/2 = " << i * (i+1) / 2 << " : "<< ans << "\n";
            // cout <<  << " " << n2 << " " << gcd << "\n";
            found = 1;
        }
    }
    cout << "MAX : " << mx << "\n";
    for (auto x : s) {
        cout << x << " ";
    }
}