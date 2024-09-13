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

int f (string &s, string &t) {
    for(int i = 0; i < t.size(); i++){
        if (s.size() <= i) return s.size();
        if (s[i] != t[i]) return i;
    }
  return (int)t.size();
}

int main() {
    fastio;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <string> v(n);
    vector <int> pre(n+1), suf(n+1);
    int ans  = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        pre[i] = f(v[i], s);
    }
    reverse(all(s));
    for (int i = 0; i < n; i++){
        reverse(all(v[i]));
        suf[i] = f(v[i], s);
    }
    vector <int> anss;
    for(int i = 0; i < n; i++){
        bool can = 0;
        int sv = v[i].size(), ss = s.size();
        if (pre[i] == sv and sv == ss) can = 1;
        if (pre[i] + suf[i] >= sv and sv + 1 == ss) can = 1;
        if (pre[i] + suf[i] >= sv-1 and sv - 1 == ss) can = 1;
        if (pre[i] + suf[i] == sv-1 and sv == ss) can = 1;
        // if (can) cout << i+1 << " "; 
        if (can) anss.emplace_back(i+1); 
    }
    cout << anss.size() << "\n";
    for (int i : anss) {
        cout << i << " ";
    }
    cout << "\n";
  


    
}