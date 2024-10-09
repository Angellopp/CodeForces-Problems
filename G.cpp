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
const int MAXN = 1e6+5;

ll dif[MAXN];
int dif2[MAXN];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        dif[r + 1] -= v;
        dif[l] += v;
        
        dif2[r + 1] -= 1;
        dif2[l] += 1;
    }
    for (int i = 1; i < MAXN; i++) {
        dif[i] += dif[i - 1];
        dif2[i] += dif2[i - 1];
    }
    ll xam = 0;
    for (int i = 1; i < MAXN; i++) {
        if(dif2[i] <= k) {
            xam = max(xam, dif[i]);
        }
    }
    cout << xam << endl;
}


int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}

