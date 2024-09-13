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
using namespace std;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 10;




int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector <int> v(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        int my = v[k];
        int indmax = 1;
        for (int i = 1; i < k; i++) {
            if (v[i] > my) {
                indmax = i;
                break;
            }
        }
        swap(v[k], v[indmax]);
        // printv(v);
        int ans = (indmax == 1) ? 0 : 1;
        for (int i = indmax + 1; i <= n; i++) {
            if (v[i] > my) {
                break;
            }
            ans++;
        }
        cout << max(ans, indmax-2) << nn;
    }
    return 0;
}