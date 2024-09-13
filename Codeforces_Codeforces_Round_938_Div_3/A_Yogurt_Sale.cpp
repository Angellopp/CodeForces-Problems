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
        int n, a, b;
        cin >> n >> a >> b;
        int ans = 0;
        if(b >= 2*a) {
            ans = n * a;
        }
        else {
            ans =( n/2) * b;
            ans += (n % 2) * a;
        }
        cout << ans << nn;
    

    }
    return 0;
}