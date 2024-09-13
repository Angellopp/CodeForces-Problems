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

ll pow(int a, int b) {
    ll ans = 1;
    for (int i = 0; i < b; i++) ans *= a;  
    return ans;
}

int main() {
    fastio;
    // int tt;
    // cin >> tt;
    // for (int i = 1; i <= 10; i++){
        // ll p10i = pow(10, i);
        // ll a1 = p10i, a2 = a1-1, a3 = a2-1;

    // }
    for (int j = 1; j <= 10; j++){
        string a = to_string(pow(10,j));
        // cout << a << "\n";
        ll i = pow(10,j);
        if (a[0] == '8' or a[0] == '9' or a[0] == '1') {
            cout << i << " -> " << "[" << i*i << ", " << i*(i+2) <<"]\n";
        }
    }// while (tt--) {

    // }
}