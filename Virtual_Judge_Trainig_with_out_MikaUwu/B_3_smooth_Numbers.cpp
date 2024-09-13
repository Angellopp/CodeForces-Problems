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
    ll n;
    cin >> n;
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 2 == 0) {
        n /= 2;
    }
    if (n == 1) {
        cout << "Yes\n";
    }
    else cout << "No\n";
    return 0;
}