#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl '\n';
#define dd(x) cerr << #x << "=" << x << "." << endl;
#define ll long long
#define ff first
#define ss second
using namespace std;

typedef double tipo;
struct pto {
    tipo x, y, z;
    pto operator+(const pto& o) const { return {x + o.x, y + o.y, z + o.z}; }
    pto operator-(const pto& o) const { return {x - o.x, y - o.y, z - o.z}; }
    tipo operator*(const pto& o) const { return x * o.x + y * o.y + z * o.z; }
    pto operator^(const pto& o) const { 
        return {
            y * o.z - z * o.y,
            z * o.x - x * o.z,
            x * o.y - y * o.x
        };
    }
};
pto operator*(tipo k, const pto& p) { return {k * p.x, k * p.y, k * p.z}; }
pto operator/(const pto& p, tipo k) { return {p.x / k, p.y / k, p.z / k}; }
ostream& operator<<(ostream& os, const pto& p) {
    return os << "(" << p.x << "," << p.y << "," << p.z << ")";
}
istream& operator>>(istream& is, pto& p) {
    return is >> p.x >> p.y >> p.z;
}
tipo modulo(pto u) {
    return sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
}
tipo producto_mixto(const pto& u, const pto& v, const pto& w) {
    return u * (v ^ w); // u · (v × w)
}
bool orientacion_punto_en_plano(const pto& X, const pto& Y, const pto& Z, const pto& S) {
    pto u = Y - X;  
    pto v = Z - X;  
    pto w = S - X;  

    pto normal = u ^ v;  

    double producto = normal * w;  

    if (producto > 0) return 1;
    if (producto < 0) return 0;
}

void solve() {
    int n; cin >> n;
    pto c, s;
    cin >> c;
    cin >> s;
    // cout << c;
    // cout << endl;
    vector<pto> v(n); 
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].z = 0;
    }
    v.push_back(v[0]);
    bool can = 1;
    for (int i = 0; i < n; i++) {
        // pto v1 = v[i] - s;
        // pto v2 = v[i+1] - s;
        // pto v3 = s-c;
        if(orientacion_punto_en_plano(v[i], v[i+1], c, s) == 1) can = 0;
        // cout << " ";
        // cout << modulo(v2 ^ v3);
        // cout << " ";
        // cout << modulo(v3 ^ v1);
    }
    if(can) {cout << "N" << endl;}
    else cout << "S" << endl;
    
}

int main() {
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}