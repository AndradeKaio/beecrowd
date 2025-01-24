#include <stdio.h>
#include <iostream>
#include <vector>
 
using namespace std;
 
inline void pprint(vector<vector<int> > &vec, int N, int W){
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= W; j++) {
      cout << vec[i][j] << " ";
    }  
    cout << endl;
  }
  cout << endl << endl;
}

inline int knapsack(vector<int> &weights, vector<int> &score, int W){
  int N = weights.size();
  vector<std::vector<int> > opt(N + 1, std::vector<int>(W + 1, 0)); 

  for(int i=1; i<=N; i++){
    for(int w=1; w<=W; w++){
      //item i weights more than capacity
      if(weights[i-1] > w)
        //i weights more than current capacity
        //so use the items from last solution
        opt[i][w] = opt[i-1][w];
      else {
        int a = opt[i-1][w]; 
        //including i is better than preserving the
        //capacity for the other i-1 items?
        int b = score[i-1] + opt[i-1][w - weights[i-1]];
        opt[i][w] = a >= b ? a : b;
      }
    }
    pprint(opt, N, W);
  }
  return opt[N][W];
  // int sum = 0, w = W, i = N;
  // for(int i = N; i > 0; --i){
  //   if (opt[i][w] != opt[i - 1][w]){
  //       sum += score[i - 1];
  //       w -= weights[i - 1];
  //   }
  // }
  // return sum;
}

int main() {
  int N, p, size, time;

  while(cin >> N && N != 0){
    //number of pizzas
    cin >> p;
    vector<int> weight(N, 0);
    vector<int> score(N, 0);
    for (int i = 0; i < N; i++) {
      cin >> time >> size;
      weight[i] = size;
      score[i] = time;
    }
    cout << knapsack(weight, score, p) << " min." << endl;
  }
  return 0;
}
