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

int main() {
    fastio;
    vector <ll> as(20+4), aux(20+4), ans(20+4);
    ans[1] = 1; as[1] = 1;
    for (int i = 2; i <= 21; i++) {
        for (int j = i-1; j >= 1; j--) aux[j] = aux[j+1] + as[i-j];                                     
        for (int j = 1; j <= i ; j++) as[j] = aux[j];
        if (i != 2) ans[i-1] = 2*as[1]; 
    }
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}