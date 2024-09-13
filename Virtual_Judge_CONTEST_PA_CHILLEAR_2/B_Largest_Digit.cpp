#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;

int maxcif (string n) {
    int mx = 0;
    for (int i = 0; i < n.size(); i++){ 
        mx = max(mx, n[i] - '0');
    }
    return mx;
}

int main() {
    fastio;
    int tt;
    cin >> tt;
    while(tt--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int dif = b-a;
        int dif2 = d-c+1;
        if(dif + dif2 > 9) {
            cout << "9\n"; 
            continue;
        }
        int ans = 0;
        for (int i = a; i <= b; i++) {
            for (int j = c; j <= d; j++) {
                string n = to_string(i+j);
                ans = max(ans, maxcif(n));
            }
        }
        cout << ans << "\n";

    }



}