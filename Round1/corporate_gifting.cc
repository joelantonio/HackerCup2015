#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

#define all(x) x.begin(), x.end()
#define f(i, a, b) for(int i = (a); i <= (b); i++)
#define fd(i, a, b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define faster_io() ios_base::sync_with_stdio(false)
#define pb push_back
#define pii pair<int, int>
#define SZ(x) ((int)x.size())
#define vii vector<pair<int, int> >
#define MOD 1000000007
#define ODD(x) (x & 1)
#define ones(x) __builtin_popcount(x)
#define CLX(x, y) memset(x, y, sizeof(x))

#define MAXN 262144
#define MAXK 32
#define INF 0x3f3f3f3f

vector<int> adj[MAXN];
int DP[MAXN][MAXK];
int J =0;

int solving(int a, int b){
  if(DP[a][b] == -1){
    DP[a][b] = 0;
    for(int i=0; i<(int)adj[a].size(); i++){
      int next = adj[a][i];
      int tmp = INF;
      for(int j=1; j<MAXK; j++){
        if(j==b) continue;
        if(tmp > j+solving(next, j)) J = max(J, j);
        tmp = min(tmp, j+solving(next, j));
      }
      DP[a][b] += tmp;
    }
  }
  return DP[a][b];
}

int main(){
 int t, n, tmp;
 cin >> t;
  for(int i=1; i<=t; i++){
    cin >> n;
    for(int e=0; e<=n; e++) adj[e].clear();
    for(int j=1; j<=n; j++){
      cin >> tmp;
      adj[tmp].push_back(j);
    }
    memset(DP, -1, sizeof(DP));
    cout << "Case #" << i << ": " << solving(0, 0) << "\n";
  }
  return 0;
}
