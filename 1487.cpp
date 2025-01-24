#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std; 

inline int solver(vector<int> &weights, vector<int> &scores, int W){
  int N = weights.size();
  vector<int> opt(W + 1, 0);
  for(int w = 1; w <= W; w++){
    for(int i = 1; i <= N; i++){
      if(w >= weights[i - 1])
        opt[w] = max(opt[w], scores[i - 1] + opt[w - weights[i - 1]]);
    } 
  }
  return opt[W];
}

int main() {
  int n, t, d, p, h;
  h = 1;
  while(cin >> n >> t && n !=0 && t !=0){
    vector<int> weight(n, 0);
    vector<int> scores(n, 0);
    int x = 0;
    while(x < n){
      cin >> d >> p;
      weight[x] = d;
      scores[x] = p;
      x++;
    }
    cout << "Instancia " << h << endl;
    cout << solver(weight, scores, t) << endl << endl;
    h++;
  }
  return 0;
}
