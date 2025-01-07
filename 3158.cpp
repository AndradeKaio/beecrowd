#include <vector>
#include <stack>
#include <iostream>

typedef std::vector<std::vector<int> > lgraph;

using namespace std;

vector<bool> visited;
lgraph graph;

void dfsCount(int u){
  visited[u] = true;
  for(int adj: graph[u]){
    if(!visited[adj]){
      dfsCount(adj);
    }
  }
}

int countComponents(){
  int components = 0;
  for(int i=1; i<graph.size(); i++){
    if(!visited[i]){
      components++;
      dfsCount(i);
    }
  }
  return components;
}

void printGraph(lgraph &graph) {
  for(int i = 1; i<graph.size(); i++){
    cout << "\n";
    cout << i << " =";
    for(int adj: graph[i]){
      cout << " " << adj;
    }
  }
    cout << "\n";
}

int main (int argc, char *argv[]) {
  int n, m, t, b, e;
  cin >> t;
  int x, y;

  while(t > 0) {
    cin >> n; cin >> m; cin >> b; cin >> e;
    // cout << "n=" << n << " m=" << m << " b=" << b << " e=" << e << endl;
    if (b <= e) {
      // cout << "entrando aqui n "<< n << " b " << b <<endl;
      cout << static_cast<long long>(b) * n << endl;
      int i = m, d, f;
      while(i>0){i--; cin >> d; cin >> f;}

    } else {
      int i = m;
      graph.assign(n + 1, vector<int>());
      visited.assign(n + 1, false);
      //reading
      while(i > 0) {
        cin >> x; cin >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        i--;
      }
      //count components
      int k = countComponents();
      // cout << "n=" << n << "m=" << m << "b=" << b << "e=" << e <<endl;
      // cout << "components found " << k << endl;
      // cout << k * b + (n - k) * e << endl;
      cout << static_cast<long long>(k) * b + static_cast<long long>(n - k) * e << endl;
    }
    t--;
  }
  return 0;
}
