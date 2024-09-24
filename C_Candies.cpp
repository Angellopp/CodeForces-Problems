#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define endl '\n'
using namespace std;

int main() {
    fastio;
    int n, xd;
    cin >> n;
    vector <int> pre(n+1, 0);
    for (int i = 0; i < n; i++) cin >> xd, pre[i+1] = pre[i] + xd;
    int q, l, r; cin >> q;
    while(q--) {
        cin >> l >> r;
        cout << (pre[r] - pre[l-1]) / 10 << endl;
    }
}