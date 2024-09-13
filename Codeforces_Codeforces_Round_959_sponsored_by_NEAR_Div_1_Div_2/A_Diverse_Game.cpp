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
    int q;
    cin >> q;
    int a[13][13];
    while(q--) {
        int n, m; 
        cin >> n >> m;
        if(n == m and n == 1) {
            cin >> a[0][0];    
            cout << "-1\n";
            continue;
        } 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                cout << (a[i][j]) % (n * m) + 1 << " ";
            }
            cout << endl;
        }
        
    }
}