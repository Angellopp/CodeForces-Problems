#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;  

int main() {
    fast_io;
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        int xd = a ^ b;
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (((xd >>i) & 1) == 1) break;
            ans ++;
        }
        cout << (1<<ans) << "\n";
    }
}