#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 10;

set<int> ans, let;
bool can(string s, int l, int r){
    string _s = s;
    reverse(all(_s));
    if(s != _s) return true;
    if(s.size() <= 2) return false;
    int n = r - l + 1;
    int m = (n-1) / 2;
    
    string s1 = s.substr(0, m);
    string s2 = s.substr(m, n - m);
    ans.insert(l + m - 1);
    return can(s1, l, l + m - 1) and can(s2, l + m, r);
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, c, d, aux;
        multiset <int> s, cc;
        cin >> n >> c >> d;
        for(int i = 0; i < n*n; i++) {
            cin >> aux;
            s.insert(aux);
        }
        int mn = *s.begin();
        // cout << mn << nn;
        for (int i = 0; i < n; i++) {
            cc.insert(mn + i*c);
            for (int j = 1; j < n; j++) {
                cc.insert(mn + i*c + j*d);
            }
        }

        if (cc == s) {
            cout << "YES" << nn;
        } else {
            cout << "NO" << nn;
        }
        // for (int i : cc) cout << i << " "; cout << nn;
        // for (int i : s) cout << i << " "; cout << nn;

    }
    return 0;
}