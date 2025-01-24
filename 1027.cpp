#include <vector>
#include <iostream>

#define UP -1
#define DOWN 1

using namespace std;

typedef struct Point{
  int x, y;
} Point;

bool compare(const Point &a, const Point &b) {
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

inline void pprint(vector<vector<int> > &vec, const int N, const int W){
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < W; j++) {
      if(vec[i][j] < 0)
        cout << 0 << " ";
      else
        cout << vec[i][j] << " ";
    }  
    cout << endl;
  }
  cout << endl << endl;
}


inline int solver(vector<Point> &points, int N){
  int count = 1;
  // vector<vector<int> > opt(N, vector<int>(2, 0));
  int opt[1000][2];

  opt[0][0] = 1;
  opt[0][1] = 1;
  for(int i=1; i<N; i++){
    opt[i][0] = 1;
    opt[i][1] = 1;

    Point current = points[i];

    for(int j=0; j<i; j++){

      int grad = current.y - points[j].y;

      if(current.x == points[j].x || abs(grad) != 2)
        break;

      if(grad > 0)
        opt[i][0] = max(opt[i][0], opt[j][1] + 1);
      else
        opt[i][1] = max(opt[i][1], opt[j][0] + 1);
    }
    count = max(count, max(opt[i][0], opt[i][1]));
  }
  return count;
}

int main() {
  int N;
  while(cin >> N){
    vector<Point> points(N);
    int x, y;
    for(int i = 0; i < N; i++){
      cin >> points[i].x;
      cin >> points[i].y;
    }
    sort(points.begin(), points.end(), compare);
    cout << solver(points, N) << endl;
  }
  return 0;
}

