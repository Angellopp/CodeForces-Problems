#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

ll solve() {
    ll n, k;
    cin >> n >> k;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    map <int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[v[i] % k].emplace_back(v[i]);
    }
    int ni = 0;
    ll ax = 0, ans = 0;
    for (auto x : mp) {
        int sz = x.S.size();
        ni += (sz & 1);
        if(ni > 1) return -1;
        for (int i = 0; i < (sz / 2 * 2); i++) {
            if (i % 2) ax += 1ll*x.S[i];
            else ax -= 1ll*x.S[i];
        }
        ans = ax;
        if(sz & 1) {
            for (int i = sz-1; i >= 2; i-=2) {
                ax = 1ll*ax + x.S[i] - 2*x.S[i-1] + x.S[i-2];
                ans = min(ans, ax);
            }
            ax = ans;
        }
    }
    return ans/k;    
}


int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        cout << solve() << endl;
    }
    return 0;
}
