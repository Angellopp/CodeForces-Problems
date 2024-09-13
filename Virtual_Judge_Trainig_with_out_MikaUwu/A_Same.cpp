#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

const int MAXN = 1e5 + 10;
int FT[MAXN];
bool FTT[MAXN]{0};

int getFT (int b) {
    int v = 0;
    for (int x = b; x; x -= x & -x) v += FT[x];
    return v;
}

void setFT (int p, int v) {
    for (int x = p; x < MAXN; x += x & -x) FT[x] += v;
}

int get(int a, int b) {return getFT(b) - getFT(a-1);}
void update(int x, int v) {setFT(x, v);}

int main() {
    fastio;
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int eq = v[0];
    bool can = 1;
    for (int i = 0; i < n; i++) {
        if (v[i] != eq) {
            can = 0;
        } 
    }
    cout << ((can) ? "Yes" : "No") << "\n";

    return 0;
}