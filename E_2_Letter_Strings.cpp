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

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool ver(int i, int j, int n, int m) {
    return(0 <= i and i < n and 0 <= j and j < m);
}

int maxn = 500+4;
void solve() {
    int n;
    string s;
    cin >> n;
    map<char, int> mp1, mp2;
    map<string, int> mp3;
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp1[s[0]]++;
        mp2[s[1]]++;
        mp3[s]++;
    }
    ll ans = 0; 
    for (auto x : mp1) {
        ans += 1ll * x.S * (x.S-1) / 2; 
    }
    for (auto x : mp2) {
        ans += 1ll * x.S * (x.S-1) / 2; 
    }
    for (auto x : mp3) {
        ans -= 1ll * x.S * (x.S-1); 
    }
    cout << ans << endl;
}

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
