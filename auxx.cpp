#include <bits/stdc++.h>
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define all(x) x.begin(), x.end()
#define print_v(x) cerr << #x << "[]: "; for (auto e : x) cerr << e <<" "; cerr << '\n'
#define RAYA cerr << string(15,'=')
using namespace std;
typedef long long ll;


int k;
const int INF = 2e9+10;



int LIS(vector<int> &a) {
    const int n = a.size();
    vector<int> d(n + 1, INF);
    d[0] = -INF;
    for (int i = 0; i < n; i++) {
        int l = upper_bound(all(d), a[i]) - d.begin();
        if (d[l - 1] <= a[i]) {
            d[l] = min(d[l], a[i]);
        }
    }
    cout << "ans\n";
    for (int i = 0; i < n+1; i++) {
        cout << d[i] << " ";
    }
    for (int l = n; l >= 1; l--) {
        if (d[l] < INF) return l;
    }
    return 1;
}

int main() {
    cout << (2*15.2+4*13+4*17+4*13.5+4*10.8+4*11.7) / (4*5+2) << endl;
    return 0;
}