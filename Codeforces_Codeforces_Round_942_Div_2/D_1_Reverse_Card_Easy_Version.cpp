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


int f(int i, vector <int> &v){
    int n = v.size(); 
    int ans = 0;
    for (int j = 0; j < n; j++) {
        // if (v[j] > i) break;
        ans += max(i - v[j], 0);
    }
    // uu(i);
    // uu(ans);
    return ans;

}

int upper_bound(int i, int n, vector <int> &v, int k){
    uu(k);
    int lo = i;
    int hi = n;
    while(lo < hi){
        int mi = lo + (hi - lo + 1) / 2;
        if(f(mi, v) <= k) lo = mi;
        else hi = mi-1;
        // uu(hi);
    }
    return lo;
}

int main() {
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += (m/i + 1) / i;
        }
        cout << ans - 1 << nn;
    }
    return 0;
}