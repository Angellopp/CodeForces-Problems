#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;  

int main() {
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int ans = 1e9+2;
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, max(v[i], v[i+1]));
        }
        cout << ans -1<< "\n";
    }
}