#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

vector<bool> vis(200000+5, false);
int ciclos(vector<int>& v) {
    vis.assign(v.size(), false);
    ll ans = 0, cur = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!vis[i]) {
            cur = i;
            while (!vis[cur]) {
                vis[cur] = true;
                cur = v[cur] - 1;
            }
            ans++;
        }
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
        map<int, int> mp;
        vector <int> v1(n), v2(n), aux1(n), aux2(n);
        readv(v1, n);
        readv(v2, n);
        aux1 = v1; aux2 = v2;
        sort(all(aux1)); sort(all(aux2));
        
        if (aux1 != aux2) {
            cout << "No" << nn;
            continue;
        }
        set <int> s;
        for (int i = 0; i < n; i++) {
            s.insert(v1[i]);
        }
        if (s.size() != n) {
            cout << "Yes" << nn;
            continue;
        }
        cout << ((ciclos(v1) % 2 != ciclos(v2) % 2) ? "No" : "Yes") << nn;
    }
    return 0;
}