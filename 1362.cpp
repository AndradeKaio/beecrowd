#include <climits>
#include <queue>
#include <map>
#include <iostream>
#include <cstring>


#define MAX 50

using namespace std;
map< string, int> names; 

bool bfs(int source, int dest, int residual[MAX][MAX], int parent[]){
  int visited[MAX];
  memset(visited, 0, sizeof(visited));

  queue< int> Q;
  Q.push(source);
  visited[source] = 1;

  while(!Q.empty()){
    int u = Q.front();
    Q.pop();

    for (int v = 0; v < MAX; v++) {
      if(visited[v] != 1 && residual[u][v] > 0){
        Q.push(v);
        visited[v] = 1;
        parent[v] = u;
        if(v == dest)
          return true;
      } 
    }
  }
  return false;
}

int fordFulkerson(int graph[MAX][MAX], int source, int dest){
  int result = 0;
  int residual[MAX][MAX];
  memset(residual, 0, sizeof(residual));

  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      residual[i][j] = graph[i][j];


  int parent[MAX];
  while(bfs(source, dest, residual, parent)){
    int u;
    int min = INT_MAX;
    int k = dest;
    while(k != source){
      u = parent[k];
      if(residual[u][k] < min){
        min = residual[u][k];
      }
      k = u;
    } 

    k = dest;
    while(k != source){
      u = parent[k];
      residual[u][k] -= min;
      residual[k][u] += min;
      k = u;
    } 
    result += min;
  }
  return result;
}

void test(){
  int graph[MAX][MAX];
  memset(graph, 0, sizeof(graph));
  graph[0][1] = 1;
  graph[0][2] = 1;
  graph[0][3] = 1;
  graph[0][4] = 1;
  graph[0][5] = 1;

  graph[1][6] = 1;
  graph[1][7] = 1;

  graph[2][7] = 1;
  graph[2][8] = 1;

  graph[3][8] = 1;
  graph[3][9] = 1;

  graph[4][9] = 1;
  graph[4][10] = 1;

  graph[5][10] = 1;

  graph[6][11] = 1;
  graph[7][11] = 1;
  graph[8][11] = 1;
  graph[9][11] = 1;
  graph[10][11] = 1;

  cout << fordFulkerson(graph,0, 11) << endl;
}
int main (int argc, char *argv[]) {
  test();
  int t, N, M;
  cin >> t;

  names["source"] = 0;
  names["sink"] = 1;

  names["XXL"] = 2;
  names["XL"] = 3;
  names["L"] = 4;
  names["M"] = 5;
  names["S"] = 6;
  names["XS"] = 7;

  while(t--){
    cin >> N >> M;
    int graph[MAX][MAX];
    memset(graph, 0, sizeof(graph));


    graph[names["source"]][names["XXL"]] = N/6;
    graph[names["source"]][names["XL"]]  = N/6;
    graph[names["source"]][names["L"]]   = N/6;
    graph[names["source"]][names["M"]]   = N/6;
    graph[names["source"]][names["S"]]   = N/6;
    graph[names["source"]][names["XS"]]  = N/6;

    int i = 0;
    while(i < M){
      string op1, op2;
      cin >> op1 >> op2;

      graph[names[op1]][i + names.size()] = 1;
      graph[names[op2]][i + names.size()] = 1;
      graph[i + names.size()][names["sink"]] = 1;
      i++;
    }
    if(fordFulkerson(graph, names["source"], names["sink"]) == M)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
