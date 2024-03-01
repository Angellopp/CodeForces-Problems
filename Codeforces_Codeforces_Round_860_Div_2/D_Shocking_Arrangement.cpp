#include <bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)

using namespace std;

int main() {
    fast_io;
    int tt;
    cin >> tt;
    vector <int> v(300000);
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.begin() + n);
        for (int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}