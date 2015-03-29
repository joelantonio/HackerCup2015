#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

#define all(x) x.begin(), x.end()
#define f(i, a, b) for(int i = (a); i <= (b); i++)
#define fd(i, a, b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define SZ(x) ((int)x.size())
#define vii vector<pair<int, int> >
#define ODD(x) (x & 1)
#define ones(x) __builtin_popcount(x)
#define CLX(x, y) memset(x, y, sizeof(x))

#define faster_io() ios_base::sync_with_stdio(false)
#define MAXN 2004
#define MOD 1000000007

int dp1[MAXN][MAXN], dp2[MAXN][MAXN];
int A, B;

int stress_free(int a, int b){
  if(a <= b) return 0;
  if(a > A || b > B) return 0;
  if(a == A && b == B) return 1;

  int &r = dp1[a][b];
  if(r == -1){
    r = stress_free(a+1, b) + stress_free(a, b+1);
    r %= MOD;
  }

  return r;
}

int stress_full(int a, int b){
  if(a > b) return 0;
  if(a > A || b > B) return 0;
  if(b == B) return 1;

  int &r = dp2[a][b];

  if(r == -1){
    r = stress_full(a+1,b) + stress_full(a, b+1);
    r %= MOD;
  }

  return r;
}


int main(){
  faster_io();
  int t;
  char c;
  cin >> t;
  for(int i=1; i<=t; i++){
    cin >> A >> c >> B;
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    cout << "Case #" << i << ": " << stress_free(1, 0) << " ";
    cout << stress_full(0, 0) << "\n";
 }
  return 0;
}
