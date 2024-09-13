#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
ll MOD = 998244353;
using namespace std;


int main() {
    fast_io;
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <vector<char>> v(2, vector<char> (n));
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < n; j++) 
                cin >> v[i][j];
        bool can = 1;
        for (int i = 1; i < n; i+=2)
            if (v[0][i] == '<') {
                if (v[1][i-1] == '<') {can = 0; break;}
                if (i != n - 1 and v[1][i+1] == '<') {can = 0; break;}
            }
        
        (can) ? cout << "YES" << nn : cout << "NO" << nn;
    }
    return 0;
}