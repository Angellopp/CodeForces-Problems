#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for (int i = 0; i < n-1; i++) cin >> v[i];
    int acc = 0;
    for (int i = 0; i < k; i++) acc += v[i];
    int ans = acc;
    for (int i = k; i < n-1; i++) {
        acc += (v[i] - v[i-k]);
        ans = min(ans, acc);
    }
    cout << ans << "\n";
}