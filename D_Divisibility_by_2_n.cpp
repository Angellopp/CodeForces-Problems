#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define cp(x) cerr << " [ " << #x << " = (" << x.F << ", " << x.S << ") ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long
#define double long double
#define clz(x) __builtin_clz(x) 
#define ctz(x) __builtin_ctz(x) 

using namespace std;

int f(int n) {
    int ans = 0;
    while(n % 2 == 0) {
        n/=2;
        ans++;
    }
    return ans;
}

void solve() {
    int n, N, cnt = 0;
    cin >> n;
    N = n;
    vector <int> v(n);
    for (int &x : v) cin >> x;
    for (int i = 0; i < n; i++) cnt += f(v[i]);
    
    if(cnt >= n) {
        cout << 0 << endl;
        return;
    }
    vector <int> pot;
    while(N > 1) {
        N/=2;
        pot.push_back(N);
    }
    int sz = pot.size(), ans = 0;
    for(int i = 0; i+1 < sz; i++) pot[i]-=pot[i+1];
    for(int i = sz-1; i >= 0; i--) {
        for (int j = 0; j < pot[i]; j++) {
            cnt += (i+1);
            ans++;
            if(cnt >= n) {
                cout << ans << endl;
                return;
            }
        }
    }
    if(cnt < n) cout << -1 << endl;
    return;
}

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}