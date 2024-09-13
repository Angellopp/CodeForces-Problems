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

void solve() {
    int n, aux;
    cin >> n;
    n+=2;
    multiset <ll> v;
    ll mx = -1;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v.insert(aux);
        sum += 1ll * aux;
        mx = max(mx, 1ll * aux);
    }
    if (n == 3) {
        vector <int> a;
        for(auto x : v) {
            a.push_back(x);
            dbg(x);
        }
        if(a[0] == a[1]) cout << a[0] << endl;
        else if(a[1] == a[2]) cout << a[1] << endl;
        else cout << -1 << endl;
        return;
    }
    ll sum1 = sum - 2*mx;
    // auto it = v.find(mx);
    v.erase(v.find(mx));
    auto it2 = v.find(sum1);
    if(it2 != v.end()) {
        v.erase(it2);
        for (auto x : v) cout << x << " "; cout << endl;
        return;
    }
    sum -= mx;
    mx = -1;
    for(auto x : v) mx = max(mx, 1ll*x);
    ll sum2 = sum - mx;
    it2 = v.find(sum2);
    if(it2 != v.end()) {
        v.erase(it2);
        for (auto x : v) cout << x << " "; cout << endl;
        return;
    }
    cout << -1 << endl;
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