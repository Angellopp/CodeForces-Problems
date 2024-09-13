#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define ll long long
using namespace std;

const ll MX = 1e5+10;
bool isPrime[MX];
ll fact[MX];

vector <ll> primes;

void sieve() {
    fill(isPrime, isPrime + MX, true);
    isPrime[1] = false;
    for (ll i = 2; i < MX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            fact[i] = i;
        }
        for (ll j = 0; j < primes.size() && i * primes[j] < MX; j++) {
            isPrime[i*primes[j]] = false;
            fact[i*primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

bool isC(ll n) {
    if ((n % 2 == 0 or n == 1) and n != 2) return true;
    for (int i = 0; primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            return true;       
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt;
    cin >> tt;
    sieve();
    while(tt--) {
        ll n;
        cin >> n;
        ll aa1 = (n+1) / 2, aa2 = (n-1) / 2;
        if (isC(aa1) and isC(aa2)) {cout << aa2 << " " << aa1 << "\n"; continue;}
        aa1 = (n+3) / 2, aa2 = (n-3) / 2;
        if (isC(aa1) and isC(aa2)) {cout << aa2 << " " << aa1 << "\n"; continue;}
        aa1 = (n+5) / 2, aa2 = (n-5) / 2;
        if (isC(aa1) and isC(aa2)) {cout << aa2 << " " << aa1 << "\n"; continue;}
        aa1 = (n+7) / 2, aa2 = (n-7) / 2;
        if (isC(aa1) and isC(aa2)) {cout << aa2 << " " << aa1 << "\n"; continue;}
        aa1 = (n+9) / 2, aa2 = (n-9) / 2;
        if (isC(aa1) and isC(aa2)) {cout << aa2 << " " << aa1 << "\n"; continue;}
        cout << "-1\n";
    }
      



    return 0;
}