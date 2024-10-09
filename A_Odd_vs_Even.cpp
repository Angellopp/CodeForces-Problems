#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

void solve() {
    ll n;
    cin >> n;
    int acc = 0;
    while(n %2 == 0) {
        n/=2;
        acc++;
    }
    if(acc == 0) {
        cout << "Odd\n";
    }
    if(acc == 1) {
        cout << "Same\n";
    }
    if(acc > 1) {
        cout << "Even\n";
    }
}

int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    // tt =1;
    while(tt--) {
        solve();
    }
}