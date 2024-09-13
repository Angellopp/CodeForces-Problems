#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int a, b;

const int maxn = 1000 + 5;

int dis[maxn][maxn];
char v[maxn][maxn];

void bfs(int x, int y) {
    queue <tuple<int,int>> q;
    q.emplace(x,y);
    while (!q.empty()) {
        auto vv = q.front();
        q.pop();
        int vf, vs;
        tie(vf, vs) = vv;
        for (int i = 0; i < 4; i++) {
            int nx = vf + dx[i];
            int ny = vs + dy[i];
            if (nx >= 0 and nx < a and ny >= 0 and ny < b and dis[nx][ny] == -1 and v[nx][ny] != 'T') {
                dis[nx][ny] = dis[vf][vs] + 1;
                q.emplace(nx, ny);
            }
        }
    }

}


int main() {
    fastio;
    memset(dis, -1, sizeof(dis));
    cin >> a >> b;
    vector <tuple<int,int,int>> vp;
    pair<int,int> p, e; 
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++) {
            cin >> v[i][j];
            if(v[i][j] == 'S') p = {i, j};
            if(v[i][j] == 'E') e = {i, j};
            if(v[i][j] - '0' > 0 and v[i][j] - '0' <= 9) {
                vp.emplace_back(i, j, v[i][j] - '0');
            }
        }
    }
    bfs(e.first, e.second);
    ll ans = 0;
    for (auto [x,y,z] : vp) {
        if (dis[x][y] != -1) {
            if (dis[x][y] <= dis[p.first][p.second]) {
                ans += 1ll*z;
            }
        }
    }
    cout << ans << "\n";
}