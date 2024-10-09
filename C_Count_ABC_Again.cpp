#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int fact[N];
int mul_mod(int a, int b) {
    return 1ll * a * b % MOD;
}

int pow_mod(int a, int e) {
    int r = 1;
    while(e) {
        if (e & 1) r = mul_mod(r, a);
        a = mul_mod(a, a);
        e >>= 1;
    }
    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i +2 < n; i++) {
        if(s[i] == 'A' and s[i+1] == 'B' and s[i+2] == 'C') ans++;
    }
    for (int i = 0; i < k; i++) {
        int ix;
        char c;
        cin >> ix >> c; ix--;
        int aux1 = 0, aux2 = 0;
        for (int j = max(0, ix-2); j < n and j <= ix; j++) {
            if(s[j] == 'A' and s[j+1] == 'B' and s[j+2] == 'C') aux1++;
        }
        s[ix] = c;
        for (int j = max(0, ix-2); j < n and j <= ix; j++) {
            if(s[j] == 'A' and s[j+1] == 'B' and s[j+2] == 'C') aux2++;
        }
        ans += aux2 - aux1;
        cout << ans << endl;
    }
    
}

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}