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
    int q; cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        if(a[0] == '1') {
            cout << "YES" << endl;
            continue;
        }
        int i = 0;
        for (i ; i < n; i++) {
            if(a[i] == '1') {
                i--;
                break;
            } 
        }
        bool can = 1;
        for (int j = 0; j <= i; j++) {
            if(b[j] == '1') {
                can = 0;
            }
        }
        cout << ((can) ? "YES" : "NO") << endl;
    }

}