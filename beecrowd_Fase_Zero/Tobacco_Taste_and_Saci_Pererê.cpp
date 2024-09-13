#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl;
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <ll> a(n+1), b(n+1);
    a.emplace_back(0); b.emplace_back(k);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    // ll l = 1, r = b[0];
    ll mx = k;
    int i = 0;
    int j = i+1
    while(mx >= a[i] and i <= n) {
        int j = i+1;
        int mxaux = mx;
        while(mxuax >= a[j]) {
            mx = max(mx, a[i] + b[i]);
            j++;
            // i++;
        }
        i=j;
    }
    
    if(mx < a[n]) {
        cout << "-1\n";
    }
    else {

    }

    for (int i = 1; i <= n; i++) {
        // if (b[i-1] - a[i] < 0) {
            // cur = 
        // }
        if()
    }
      



    return 0;
}