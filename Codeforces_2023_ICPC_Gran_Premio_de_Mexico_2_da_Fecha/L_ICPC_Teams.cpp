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
    long double n;
    vector <long double> vel(3);
    cin >> n >> vel[0] >> vel[1] >> vel[2];
    vector <long double> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    sort(vel.begin(), vel.end());
    long double tope = ((n-3 >= 0) ? v[n-3] : 0);
    long double ag = 2*tope;
    for (int i = 0; i <= n-3; i++) {
        ag += v[i];
        // v[i] = max((long double)0,v[i]- tope);
    }
    // for (int i = 0; i < n; i++) {
    //     cout << v[i] << " ";
    // }cout << "\n";
    long double ayu = 0;
    if(n == 1) {
        ayu = (1.0) * v[n-1] / (vel[2]);
    }
    else if (n == 2) {
        ayu = (1.0) * (2 * v[n-2]) / (vel[1]+vel[2]);
        ayu += (1.0) * (v[n-1] - v[n-2]) / (vel[2]);
    }
    else {
        v[n-2] -= tope;
        v[n-1] -= tope;
        ayu = (1.0) * ag / (vel[0]+vel[1]+vel[2]);
        ayu += (1.0)*2*v[n-2] / (vel[1] + vel[2]);
        v[n-1] -= v[n-2];
        ayu += (1.0) * v[n-1] / (vel[2]);

    }

    cout << ayu << "\n"; 
    int ss = ceil(ayu);
    // if (ayu - (1.0)*ss > (1.0) * 0) {
        // cout << ss + 1 << "\n"; 
    // } 
    // else {
        cout << ss << "\n"; 
    // }
    // cout << "\n" << ss << "\n";
    return 0;
}