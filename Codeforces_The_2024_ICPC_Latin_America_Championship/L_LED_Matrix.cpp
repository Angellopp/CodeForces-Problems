#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
int mod = 1e9+7;
using namespace std;

const int maxn = 2.5e6 + 10;

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int r,c,k;
        cin >> r >> c >> k;
        vector <bool> m(r, 1);
        vector <bool> p(r, 0);

        char aux;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> aux;
                if (aux == '-') {
                    m[i] = 0;
                }
            }
            for (int j = 0; j < k; j++) {
                cin >> aux;
                if (aux == '*') {
                    p[i] = 1;
                }
            }
        }
        bool ans = 1;
        for (int i = 0; i < r; i++) {
            if (m[i] == 0 and p[i] == 1) {
                ans = 0;
                break;
            }
        }
        cout << ((ans) ? "Y" : "N") << nn;
    }
    return 0;
}
