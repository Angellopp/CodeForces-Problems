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
using namespace std;

vector <bool> par(50+5);
vector <char> sol;
vector <ll> ss;
// ll ss = 0;
int n;
ll s = 0;

int dp[50+2][2+2][50+2];




void backtrack(int i, int l, int r, const ll &s) {
    if (i == n+1) {ss.emplace_back(s); return;} 
    // if (i == n+1) {ss++; return;} 
    if (l == n/2) {return backtrack(i+1, l, r+1, (s<<1)+1ll);}
    backtrack(i+1, l+1, r, (s<<1));
    if (l > r) backtrack(i+1, l, r+1, (s<<1)+1ll);
}

int main() {
    fastio;
    ll m;
    cin >> n >> m;
    if (n%2) {
        for (int i = n-1; i >= 0; i--) {
            cout << (((m>>i) & 1ll) ? ')' : '(');
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {

    }

    backtrack(1, 0, 0, s);
    for (ll x: ss) {
        cout << x << " -> ";
        for (int i = 0; i < n; i++) {
            cout << (((x>>i) & 1) == 0) ;
        }
        cout << "\n";
    }
    cout << ss.size() * (n/2+1)<<"\n";
    return 0;
}