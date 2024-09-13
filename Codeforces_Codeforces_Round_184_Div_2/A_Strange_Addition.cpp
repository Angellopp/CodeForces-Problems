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

int num1(int n) {
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        if ((n >> i) & 1) ans++;
    }
    return ans;
}

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n, aux;
        cin >> n;
        vector <string> v;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            string s = to_string(aux);
            string ceros(3 - s.size(), '0');
            s = ceros + s;
            v.emplace_back(s);
        }
        vector <string> ans(8, "a");
        for (string ss: v) {
            int x = (ss[2] != '0') + (ss[1] != '0') * 2 + (ss[0] != '0') * 4;
            ans[x] = ss;
        }
        int pos = 0;
        for (int i = 0; i < 8; i++) pos += (ans[7-i] != "a") << i;

        int maxn = 0;
        vector <int> ansss;
        for (int i = 0; i < 256; i++) {
            if (i & pos) {
                int _n = i & pos;
                vector <int> aux;
                for (int i = 7; i >= 0; i--) 
                    if ((_n >> i) & 1) aux.emplace_back(7-i);
                
                bool can = 1;
                for (int i = 0; i < aux.size(); i++) {
                    for (int j = i+1; j < aux.size(); j++) {
                        if (aux[i] & aux[j]) {
                            can = 0;
                            break;
                        }
                    }
                }
                if (can) {
                    if (maxn < aux.size()) {
                        ansss = aux;
                        maxn = aux.size();
                    }
                }
            }
        }
        cout << maxn << nn;
        for (int i = 0; i < maxn; i++) 
            cout << stoi(ans[ansss[i]]) << " ";
        cout << nn;
    }
    return 0;
}