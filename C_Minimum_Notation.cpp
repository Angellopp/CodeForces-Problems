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
    string s;
    cin >> s;
    int n = s.size();
    vector <int> v(n);
    multiset <int> m;
    m.insert((int)(s[n-1] - '0'));
    for (int i = n-2; i >= 0; i--) {
        int c = s[i] - '0';
        int mn = *m.begin();
        if(c <= mn) m.insert(c);
        else m.insert(min(c+1,9));
    } 
    for (auto& x : m) cout << x; cout << endl;

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
