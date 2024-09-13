




















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
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e8;

const int maxn = 1e5+3;

int main() {
    fastio;
    int n;
    cin >> n;
    while(n--){
        vector <int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(all(a));
        int ans = 0;
        for (int i = 0; i <=5 ; i++) {
            for (int j = 0; i+j <= 5; j++) {
                for (int k = 0; i+j+k <= 5; k++) {
                    ans = max((a[0] + i) * (a[1] + j) * (a[2] + k), ans);
                }
            }
        }
        cout << ans << endl; 
    }
}
