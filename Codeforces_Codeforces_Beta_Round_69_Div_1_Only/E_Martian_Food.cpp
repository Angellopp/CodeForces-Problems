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

double dist (double x1, double y1) {
    return sqrt(x1 * x1 + y1 * y1);
}


int main() {
    fastio;
    cout << fixed << setprecision (10);
    int tt;
    cin >> tt;
    while (tt--){
        double R, r, k;
        cin >> R >> r >> k;
        double new_r = r * (R - r) / R;     
        double r_x = r * (R + r) / R, r_y = 2 * k * new_r;
        double dist_r = dist(r_x, r_y);
        double sen_al = r_y / dist_r, cos_al = r_x / dist_r;
        double c = dist(r_x - cos_al * new_r , r_y - sen_al * new_r);
        double a = dist(r_x + cos_al * new_r, r_y + sen_al * new_r);
        cout << 2 * r * r * ((a - c) / (a * c)) << "\n";
    }


    return 0;
}