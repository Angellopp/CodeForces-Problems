#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;
const int INF = 1e9;

const int MX = 1e7 + 12;


// bool isPrime[MX];
int fact[MX];

vector<int> primes;
 
void sieve() {
    fill(isPrime, isPrime + MX, true);
    // isPrime[1] = false;
    for (int i = 2; i < MX; i++) {
        // if (isPrime[i]) {
        //     primes.push_back(i);
        //     fact[i] = i;
        // }
        for (int j = 0; j < primes.size() && i * primes[j] < MX; j++) {
            // isPrime[i * primes[j]] = false;
            fact[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }       
    }
}
map<int,int> mp;
void getFact(int x) {
    int 
    // vector<int> f;
    while(x != 1) {
        mp[fact[x]] =  
        f.push_back(fact[x]);
        x /= fact[x];
    }       
    return f;
}

void solve() {
    int n; 
    cin >> n;
    vector <pair<int,int>> v(n);
    for(int i = 0; i < n; i++) {cin >> v[i].ff; v[i].ss = i;}
    for(int i = 0; i < n; i++) {
        getFact(v[i].ff);
    }

}


int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}

