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
    int n, aux;
    cin >> n;
    vector <int> v(n), cpy(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cpy[i] = v[i];  
    }
    for (int i = n%2; i < n; i+=2) {
        if(v[i] > v[i+1]) swap(v[i], v[i+1]);
    }
    sort(all(cpy));
    if(v == cpy) {
        cout << "YES\n";
    }
    else cout << "NO\n";

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