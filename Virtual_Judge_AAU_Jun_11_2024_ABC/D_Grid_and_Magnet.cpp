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
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)

int h, w;
int maxn = 1e3;
vector <vector<char>> a(maxn, vector <char> (maxn));
vector <vector<bool>> b(maxn, vector <bool> (maxn));
vector <vector<bool>> vis(maxn, vector <bool> (maxn));

const int dx[4] = {0 , 0, -1, 1};
const int dy[4] = {-1, 1,  0, 0};

bool isvalid(int x, int y) {
    return (0 <= x and x < h and 0 <= y and y < w);
}

void ismag() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(isvalid(nx, ny) and a[nx][ny] == '#') b[i][j] = 1; 
            }
        } 
    }
}


set <pair<int,int>> mag;
int cont = 0;

void bfs(int i, int j){
    if(vis[i][j]) return;
    if(b[i][j]) {
        mag.insert({i,j});
        return;
    }
    cont++;
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (isvalid(nx, ny) and a[nx][ny] == '.') bfs(nx, ny);
    }
}

int main() {
    fastio;
    cin >> h >> w;
    for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++) 
            cin >> a[i][j];
    
    ismag();
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(a[i][j] == '#') continue;
            if(b[i][j]) {ans = max(1, ans); continue;}
            cont = 0;
            mag.clear();
            bfs(i, j);
            ans = max(cont + (int)mag.size(), ans);
        }
    }
    vector <int> aa = {1,2};
    // trace(aa, a);
    // trace(aa);
    cout << ans << "\n";
}