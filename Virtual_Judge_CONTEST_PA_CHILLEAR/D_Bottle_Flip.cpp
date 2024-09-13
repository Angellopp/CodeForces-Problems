#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    double l, r, ai, ag;
    cin >> l >> r >> ai >> ag;
    double div = ag / ai;
    div = sqrt(div);
    double ans = l / (div+1);
    cout << setprecision(10) << fixed << ans << "\n";
    
}