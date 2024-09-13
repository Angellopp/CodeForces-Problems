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

const int MAXN = 1e7;
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

vector <ll> cua;
vector <vector<ll>> dig;
int main() {
    fastio;
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(all(s));
    int ans = 0;
    for (ll i = 0; i * i < 1e13; i++) {
        string aux = to_string(i * i);
        // cout << aux.size();
        int dif = n - aux.size();
        // cout << dif << " s";
        for (int j = 0; j < dif; j++) {
            aux.push_back('0');
        }
        sort(all(aux));
        // cout << aux << " ";
        if (aux == s) ans++;
    }
    cout << ans << "\n";


    

    
}