#include <bits/stdc++.h>
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define print_v(x) cerr << #x << "[]: "; for (auto e : x) cerr << e <<" "; cerr << '\n'
#define RAYA cerr << string(15,'=')
using namespace std;
typedef long long ll;
int n;
const char pos[] = {'B', 'B', 'A', 'A'};
const ll INF = 9e18;
vector<pair<int,int>> a;

pair<int,int> conv(string s) {
    int idx = find(s.begin(), s.end(), '-') - s.begin();
    string r1 = s.substr(0,idx);
    string r2 = s.substr(idx + 1);
    return {stoi(r1), stoi(r2)};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    cin >> n;
    string s;
    vector <pair<int, int>> p, p1, p2;
    vector<int> ind;
    int cnt11 = 0;
    int idx = 1e9;
    bool bad = false;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (i != 0 and p.back() == conv(s)) continue;
        p.emplace_back(conv(s));
        ind.emplace_back(i);
        if (cnt11 == 1) {
            idx = i;
            bad = true;
        }
        if(conv(s).first == 11) cnt11++;
        if (cnt11 == 1) {
            idx = i;
            bad = true;
        }
        if(conv(s).second == 11) cnt11++;
    }

    p1 = p;
    pair<int,int> aux;
    for (int i = 0; i < p.size(); i++) {
        if((p[i].first + p[i].second) % 4 == 0 or (p[i].first + p[i].second) % 4 == 3) {
            aux = p[i];
            p1[i] = {aux.second ,aux.first};
        }
    }
    bool xd1 = 1;
    for (int i = 1; i < p1.size(); i++) {
        if(p1[i].first < p1[i-1].first or p1[i].second < p1[i-1].second) {
            xd1 = 0;
            idx = min(idx, ind[i]);
            break;
        }
    }
    if (bad) {
        cout << "error " << idx+1 << " \n"; 
    }
    else if (xd1)  {
        cout << "ok\n";
    }
    else {
        cout << "error " << idx+1 << " \n"; 
    }


    return 0;
}
