#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
vector <int> v((int)2e5);
int n;
void solve() {
    int n;
    vector <vector<int>> v(n, vector <int>(n));

    vector <int> sv(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(v[j][i] = 1) sv[i]++;
        }
    }

}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}