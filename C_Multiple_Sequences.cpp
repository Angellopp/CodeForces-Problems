#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

const int N = 2e5 + 50;
const int MOD = 998244353;

const ll MX = N;
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

vector<int> getDivisors(ll x) {
    vector<int> div;
    div.emplace_back(0);
    ll ans = 1;
    while (x > 1) {
        ll f = fact[x]; 
        ll num = 0;
        // ll sz = ans;
        while (x % f == 0) {
            num++;
            // num *= f;
            x /= f;
            // ans += sz;
        }
        div.emplace_back(num);
    }
    return div;
}


int mul_mod(int a, int b) {
    return 1ll * a * b % MOD;
}
int sum_mod(int a, int b) {
    return (1ll * a + 1ll*b) % MOD;
}

int pow_mod(int a, int e) {
    int r = 1;
    while(e) {
        if (e & 1) r = mul_mod(r, a);
        a = mul_mod(a, a);
        e >>= 1;
    }
    return r;
}

int inv_mod(int a) { 
    return pow_mod(a, MOD - 2);
}
int factorial[N];

int C(int n, int k) {
    if (k > n) return 0;
    int num = factorial[n];
    int den = mul_mod(factorial[k], factorial[n - k]);
    return mul_mod(num, inv_mod(den));
}

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int tope = m;
    sieve();
    for(int i = 1; i <= m; i++) {
        vector <int> div = getDivisors(i);
        int aux = 1;
        for(auto x : div) {
            aux = mul_mod(aux, C(x+n-1, n-1));
        }
        ans = sum_mod(ans, aux);
    }
    cout << ans << endl;
}

int main() {
    fastio;
    factorial[0] = 1;
    for (int i = 1; i < N; i++) {
        factorial[i] = 1ll * factorial[i - 1] * i % MOD;
    }
    int tt = 1;
    // cout << endl << C(6,2);
    // cin >> tt;
    // tt =1;
    while(tt--) {
        solve();
    }
}