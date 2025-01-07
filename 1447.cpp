#include <iostream>

#define NULL        -1
#define INF         -2
#define MAX_SIZE    100

using namespace std;

void dijkstra(int graph[MAX_SIZE][MAX_SIZE], int source, int N){
  int dist[N];
  for(int i=1; i<=N; i++){
    int uv = graph[source][i];
    if(uv != NULL){
      dist[i] = uv; 
    }else{
      dist[i] = INF;
    }
    cout << "uv = " << dist[i] << endl;
  }
  dist[source] = 0;
  for (int i = 1; i <= N; i++) {
    cout << dist[i] << endl;
  }
}

void print(int graph[MAX_SIZE][MAX_SIZE], int N){
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      cout << " " << graph[i][j];
    }
    cout << endl;
  }
}

int main (int argc, char *argv[]) {
  int N, M;
  int k = 1;
  while(cin >> N >> M){
    cout << "Instancia " << k << endl;

    vector<bool> visited;
    int graph[MAX_SIZE][MAX_SIZE];

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        graph[i][j] = NULL;
      }
    }
    visited.assign(N + 1, false);

    for(int i=0; i<M; i++){
      int A, B, C;
      cin >> A >> B >> C;
      graph[A][B] = C;
      graph[B][A] = C;
    }
    int D, K;
    cin >> D >> K;
    if(K * M < D){
      cout << "impossivel" << endl;
    }else{
      int cost = 0;
      // cout << cost << endl;
    }
    // print(graph, N);
    dijkstra(graph, 1, N);
    k++;
    cout << endl;
  }
  return 0;
}
