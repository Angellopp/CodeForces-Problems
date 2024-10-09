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
void solve() {
    ll b, c, d;
    cin >> b >> c >> d;
    ll a = 0;
    ll d2 = d - (b - c);
    if (d2 < 0) {
        cout << -1 << endl; return;
    }
    for (int i = 0; i < 62; i++) {
        if (d2>>i & 1) {
            if((b>>i & 1) == 0) {a += 1ll<<i ; continue;}
            if((c>>i & 1) == 1) continue;
            cout << -1 << endl; return;
        }
        else {
            if((b>>i & 1) == 1) {a += 1ll<<i; continue;}
            if((c>>i & 1) == 0) continue;
            cout << -1 << endl; return;
        }
    }
    cout << a << endl;
}

int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

/*
010-
010
----
000

010-
000
----
010
*/