#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;

int main() {
    int tt;
    cin  >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        int x = (m + 1) / 2;
        int y = 5 * 3 * x - n - 4*m;
        if (y >= 0) cout << x << "\n";
        else {
            int z = (-y + 14) / 15;
            cout << x+z << "\n";
        }

    }
}