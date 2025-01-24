#include <stdio.h>
#include <vector>
#include <iostream>
#include <climits>

using namespace std; 

inline int solver(vector<int> blocks, int N, int W){
  vector<int> opt(W + 1, 0);

  for(int w = 1; w <= W; w++){
    opt[w] = INT_MAX;
    for(int i = 1; i <= N; i++){
      if(w >= blocks[i - 1])
        opt[w] = min(opt[w], opt[w - blocks[i - 1]] + 1);
      }
  }
  return opt[W];
}

int main() {
  int t, n, m, c;
  cin >> t;
  while(t > 0){
    cin >> n >> m;
    // cout << "n=" << n << " m="<<m << endl;
    vector<int> Q(n);
    int x = 0;
    while(x < n){
      cin >> c;
      Q[x] = c;
      x++;
    }
    cout << solver(Q, n, m) << endl;
    t--;
  }
 return 0;
}
