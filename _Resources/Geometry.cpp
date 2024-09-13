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

typedef double tipo;
struct pto {
    tipo x, y;
    pto operator+(const pto& o) const { return {x+o.x, y+o.y}; }
    pto operator-(const pto& o) const { return {x-o.x, y-o.y}; }
    tipo operator*(const pto& o) const { return x*o.x + y*o.y; }
    tipo operator^(const pto& o) const { return x*o.y - y*o.x; }
};

pto operator*(tipo k, const pto& p) { return {k*p.x, k*p.y}; }
pto operator/(const pto& p, tipo k) { return {p.x/k, p.y/k}; }
ostream &operator<<(ostream& os, const pto& p) {
    return os << "(" << p.x << "," << p.y << ")";
}
istream &operator>>(istream& is, pto& p) {
    return is >> p.x >> p.y;
}   

const double pi = acos(-1);
pto ori; 
int r, n;

double dis(pto u, pto v = {0,0}) {
    return sqrtl((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
}
int sgn(double u) {
    return ((u >= 0) ? 1 : -1);
}
void centrar(pto& u, pto c) {
    u = u - c;
}
double pcruz2(pto u, pto v, pto c = {0,0}) {
    return ((u-c) ^ (v-c) / 2) ;
}
pto circuncentro(pto u, pto v, pto c = {0,0}) {
    if ((u.x - c.x) * (v.y - c.y) == (v.x - c.x) * (u.y - c.y)) return u;
    u = (u - c)/2.0;
    v = (v - c)/2.0;
    return {((u.x*u.x+u.y*u.y)*v.y-(v.x*v.x+v.y*v.y)*u.y)/(u.x*v.y-v.x*u.y) + c.x,((v.x*v.x + v.y*v.y)*u.x-(u.x*u.x+u.y*u.y)*v.x)/(u.x*v.y-v.x*u.y) + c.y};
}
pto inv_punto(pto u, pto c = {0,0}) {
    double du = dis(u, c);
    return {1.0 * r * r * u.x / (du * du), 1.0 * r * r * u.y / (du * du)};
}
double area_sec_cir(pto u, pto v, pto c = {0,0}) {
    double dif = dis(u, v);
    double du = dis(u, ori);
    double dv = dis(v, ori);
    double r = dis(u, c);
    if(r == 0) return 0;
    double ang = acos((du * du + dv * dv - dif * dif) / (2 * du * dv));  
    if(ang > pi/2) return (r * r * ang + abs(pcruz2(u, v, c)));
    return (r * r * ang - abs(pcruz2(u, v, c)));
}
double area_inv(pto ui, pto vi) {
    pto c = circuncentro(ui, vi);
    double area_p = pcruz2(ui, vi); 
    double area_c = sgn(area_p) * area_sec_cir(ui, vi, c);
    return area_p + area_c;
}

double area_pol_inv(vector<pto>& v, int sentido = 1) {
    double ans = 0;
    for (int i = 0; i+1 < v.size(); i++) ans += area_inv(v[i], v[i+1]); ans +=area_inv(v.back(), v[0]);
    return ans;
}

int main() {
    fastio;
    cout << fixed << setprecision(11);
    cin >> ori >> r >> n;
    vector<pto> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        centrar(v[i], ori);
    }
    ori = {0,0};
    vector<pto> vi(n);
    for (int i = 0; i < n; i++) {
        vi[i] = inv_punto(v[i]);
    }
    cout << abs(area_pol_inv(vi)) << "\n";
}