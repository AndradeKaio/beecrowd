#include <string>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

inline int reverseNumber2(int n) {
    std::string s = std::to_string(n);
    std::reverse(s.begin(), s.end());
    return std::stoi(s);
}

inline int reverseNumber(int n) {
    int reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int getDistance(int start, int end){
  vector<bool> visited;
  visited.assign(10000, false);
  queue<pair<int, int> > queue; 
  int d = 0;
  if(start == end)
    return d;

  queue.push(make_pair(start, 0));

  while(!queue.empty()){
    pair<int, int> p = queue.front(); 
    queue.pop();
    int cur = p.first;
    int d = p.second;
    // cout << "current " << cur << endl;
    if(visited[cur])
      continue;

    int next = cur + 1;
    int rev = reverseNumber2(cur);

    visited[cur] = true;

    // visited[cur] = visited[next] = visited[rev] = true;
    d += 1;
    // cout << next <<" " << rev << endl;
    if(next == end || rev == end)
      return d;

    if(!visited[next] && next < 10000)
      queue.push(make_pair(next, d));

    if(!visited[rev] && rev < 10000)
      queue.push(make_pair(rev, d));
  }
  return d;
}

int main (int argc, char *argv[]) {
  int T;
  cin >> T;
  while(T > 0) {
    int A, B;
    cin >> A >> B;
    cout << getDistance(A, B) << endl;
    T--;
  }

  return 0;
}
