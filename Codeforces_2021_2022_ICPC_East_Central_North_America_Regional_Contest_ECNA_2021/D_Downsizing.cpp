#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define cp(x) cerr << " [ " << #x << " = (" << x.F << ", " << x.S << ") ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define double long double
#define Punto pair<double,double>
using namespace std;

const double pi = acos(-1);
pair<int,int> ori; 
int r, n;

double dis(Punto u, Punto v = {0,0}) {
    return sqrtl((u.F - v.F) * (u.F - v.F) + (u.S - v.S) * (u.S - v.S));
}
int sgn(double u) {
    return ((u >= 0) ? 1 : -1);
}
void centrar(Punto& u, Punto c) {
    u = {u.F - c.F, u.S - c.S};
}
double pcruz2(Punto u, Punto v, Punto c = {0,0}) {
    return (((u.F-c.F) * (v.S-c.S) - (u.S-c.S) * (v.F-c.F)) / 2);
}
Punto circuncentro(Punto u, Punto v, Punto c = {0,0}) {
    if ((u.F - c.F) * (v.S - c.S) == (v.F - c.F) * (u.S - c.S)) return u;
    u = {(u.F - c.F) / 2, (u.S - c.S) / 2};
    v = {(v.F - c.F) / 2, (v.S - c.S) / 2};
    return {((u.F*u.F+u.S*u.S)*v.S-(v.F*v.F+v.S*v.S)*u.S)/(u.F*v.S-v.F*u.S) + c.F,((v.F*v.F + v.S*v.S)*u.F-(u.F*u.F+u.S*u.S)*v.F)/(u.F*v.S-v.F*u.S) + c.S};
}
Punto inv_punto(Punto u, Punto c = {0,0}) {
    double du = dis(u, c);
    return {1.0 * r * r * u.F / (du * du), 1.0 * r * r * u.S / (du * du)};
}
double area_sec_cir(Punto u, Punto v, Punto c = {0,0}) {
    double dif = dis(u, v);
    double du = dis(u, ori);
    double dv = dis(v, ori);
    double r = dis(u, c);
    if(r == 0) return 0;
    double ang = acos((du * du + dv * dv - dif * dif) / (2 * du * dv));  
    if(ang > pi/2) return (r * r * ang + abs(pcruz2(u, v, c)));
    return (r * r * ang - abs(pcruz2(u, v, c)));
}
double area_inv(Punto ui, Punto vi) {
    Punto c = circuncentro(ui, vi);
    double area_p = pcruz2(ui, vi); 
    double area_c = sgn(area_p) * area_sec_cir(ui, vi, c);
    return area_p + area_c;
}

double area_pol_inv(vector<Punto>& v, int sentido = 1) {
    double ans = 0;
    for (int i = 0; i+1 < v.size(); i++) ans += area_inv(v[i], v[i+1]); ans +=area_inv(v.back(), v[0]);
    return ans;
}

int main() {
    fastio;
    cout << fixed << setprecision(11);
    cerr << fixed << setprecision(11);
    cin >> ori.F >> ori.S >> r >> n;
    vector<Punto> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F >> v[i].S;
        centrar(v[i], ori);
    }
    ori = {0,0};
    vector<Punto> vi(n);
    for (int i = 0; i < n; i++) {
        vi[i] = inv_punto(v[i]);
    }
    cout << abs(area_pol_inv(vi)) << "\n";
}