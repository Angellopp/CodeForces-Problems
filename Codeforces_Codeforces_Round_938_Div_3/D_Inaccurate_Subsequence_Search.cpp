#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(i, ii, n) for(int i = ii; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

const int INF = 1e9 + 7;
const int maxn = 1e6 + 10;

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    vector <int> mpa(maxn, 0), mpb(maxn, 0);
    while (tt--) {
        int n, m, k; 
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        set<int> sb;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mpa[a[i]] = 0; mpb[a[i]] = 0;
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            mpb[b[i]] = 0; mpa[b[i]] = 0;
            sb.insert(b[i]);
        }

        for (int i = 0; i < m; i++) {
            mpa[a[i]]++; mpb[b[i]]++;
        }
        int ans = 0, cont = 0;
        for (int i : sb) {
            cont += min(mpa[i], mpb[i]);
        }
        if (cont >= k) ans++;
        for (int i = m; i < n; i++) {
            cont -= min(mpa[a[i - m]], mpb[a[i - m]]);
            mpa[a[i - m]]--;
            cont += min(mpa[a[i - m]], mpb[a[i - m]]);
            cont -= min(mpa[a[i]], mpb[a[i]]);
            mpa[a[i]]++;
            cont += min(mpa[a[i]], mpb[a[i]]);
            if (cont >= k) ans++;
        }
        cout << ans << nn;
    }
    return 0;
}