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
#define MAXN 10000007
#define ODD(x) (x & 1)
#define ones(x) __builtin_popcount(x)
#define CLX(x, y) memset(x, y, sizeof(x))

ll arr[MAXN];

void R(){
  CLX(arr, 0);
  for(ll i=2; i<=MAXN; i++){
    if(arr[i]==0){
      for(ll j=i; j<=MAXN; j+=i) 
        arr[j]++;
    }
  }
}

int main(){
  int t;
  ll i, ans, a, b, c, j;
  R();
  cin >> t;
  f(i, 1, t){
    ans = 0;
    cin >> a >> b >> c;
    f(j, a, b){
      if(arr[j]==c) ans++;
    }
    cout << "Case #" << t << ": " << ans << "\n";
  }
  return 0;
}
