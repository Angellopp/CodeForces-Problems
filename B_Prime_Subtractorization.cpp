#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

const ll MX = 1e7 + 10;
bool isPrime[MX];
vector<int> ans(MX, 0);
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

void solve() {
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    sieve();
    ans[5] = 2;
    for(int i = 6; i < MX; i++) {

        ans[i] += ans[i-1] + (isPrime[i-2] and isPrime[i]);
    }
    
    for (int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
