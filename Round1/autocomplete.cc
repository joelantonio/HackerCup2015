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

#define MAXN 1000004

int trie[MAXN][27];
int step[MAXN];
int deep_word[MAXN];
int top;

int add(string s){
  int x = 0;
  int deep = 1;
  int ans  = -1;
  for(int i=0; i<s.size(); i++){
    int nxt = trie[x][s[i]-'a'];
    if(nxt == -1){
      trie[x][s[i]-'a'] = top++;
    }
    x = trie[x][s[i]-'a'];
    step[x]++;
    deep_word[x] = deep++;
    if(ans == -1 && step[x] == 1)
      ans = deep_word[x];
  }
  if(ans == -1) ans = s.size();
  return ans;
}

int main(){
  int t, n, ans;
  string s;
  cin >> t;
  for(int i=1; i<=t; i++){
    top = 1;
    memset(trie, -1, sizeof(trie));
    memset(step, 0, sizeof(step));
    ans = 0;
    cin >> n;
    while(n--){
      cin >> s;
      ans += add(s);
    }
    cout << "Case #" << i << ": " << ans << "\n";
  }
  return 0;
}
