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


int mod = 1e9 + 7;
void solve() {
    string a, b;
    cin >> a >> b;
    int j = 0;
    for (int i = 0; i < a.size() and j < b.size(); i++) {
        if (a[i] == '?') a[i] = b[j++]; 
        else if (a[i] == b[j]) {
            j++;
        }
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '?') a[i] = 'a';
    }
    if(j == b.size()) {
        cout << "YES" << endl << a << endl;
    }
    else cout << "NO\n";


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
