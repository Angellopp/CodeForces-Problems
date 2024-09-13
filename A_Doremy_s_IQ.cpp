#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define cp(x) cerr << " [ " << #x << " = (" << x.F << ", " << x.S << ") ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long
#define double long double
using namespace std;

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        int n, k;
        cin >> n >> k;
        vector <int> v(n);
        vector <char> ans(n, '0');
        for (int &x : v) cin >> x;
        int q = 0;
        for (int i = n-1; i >= 0; i--) {
            if(v[i] <= q) {
                ans[i] = '1';
            }
            else if(v[i] > q and q < k) {
                ans[i] = '1';
                q++;
            }
        }
        for (char& c : ans) cout << c; cout << endl;
    }
    return 0;
}