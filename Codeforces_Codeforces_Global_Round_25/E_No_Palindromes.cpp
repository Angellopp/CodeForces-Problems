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
string s;

set<int> ans;
bool pal(string s) {
    string _s = s;
    reverse(all(_s));
    return s == _s;
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        cin >> s;
        int n = s.size();
        if(!pal(s)) {
            cout << "YES" << nn << 1 << nn << s << nn;
            continue;
        }
        int i = 0;
        while(s[i] == s[0]) {
            i++;
        }
        i++;
        if(i < n and !pal(s.substr(0,i)) and !pal(s.substr(i, n-i))) {
            cout << "YES" << nn << 2 << nn << s.substr(0,i) << " " << s.substr(i) << nn;
            continue;
        }
        i++;
        if(i < n and !pal(s.substr(0,i)) and !pal(s.substr(i, n-i))) {
            cout << "YES" << nn << 2 << nn << s.substr(0,i) << " " << s.substr(i) << nn;
            continue;
        }
        cout << "NO" << nn; 



         
    }
    
    return 0;
}