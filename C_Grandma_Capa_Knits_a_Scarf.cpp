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
#define clz(x) __builtin_clz(x) 
#define ctz(x) __builtin_ctz(x) 

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1e9;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        int l = 0, r = n-1, cnt = 0;
        while(l < r) {
            if(s[l] == s[r]) {
                l++, r--;
            }
            else if (s[l] == c) {
                l++;
                cnt++;
            }
            else if (s[r] == c) {
                r--;
                cnt++;
            }
            else {
                cnt = 1e9;
                break;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ((ans == 1e9) ? -1 : ans) << endl;
}

int main() {
    fastio;
    int q;
    cout << fixed << setprecision(10);
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
