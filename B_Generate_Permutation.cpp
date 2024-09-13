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
#define clz(x) __builtin_clz(x) 
#define ctz(x) __builtin_ctz(x) 

using namespace std;

// vector <int> f;
int n, k;

void solve() {
    cin >> n;
    if(n %2 == 0) {
        cout << -1 << endl; return;
    }
    int ini = 0;
    // vector <int> v(n+1);
    int i = 1;
    for(i = 1; i<= n; i+=2) {
        cout << i << " ";
    }
    i-=3;
    for(i; i > 0; i-=2) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    fastio;
    int q;
    cout << fixed << setprecision(10);
    cin >> q;
    // f.emplace_back(1); f.emplace_back(1);
    // for (int i = 2; f.back() <= 2e5; i++) {
    //     f.emplace_back(f[i-1] + f[i-2]);
    // }
    while(q--) {
        solve();
    }
    return 0;
}
