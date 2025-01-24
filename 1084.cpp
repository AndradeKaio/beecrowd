#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

inline void printq(vector<short> v){
    for (short i: v)
      std::cout << i;
    cout <<endl;
}

int main() {
  int n, d;
  string number;
  int x;
  while(cin >> n >> d && n != 0 && d != 0){
    std::vector<short> Q;
    cin >> number;
    int count = 1;
    d = n - d;

    for(char& c: number){
      x = c - '0';
      if(Q.empty())
        Q.push_back(x);
      else { 
        while(x > Q.back() && n - count >= (d - Q.size() + 1 ) && !Q.empty()){
          Q.pop_back();
        }
        if(Q.size() < d){
          Q.push_back(x);
          count++;
        }
      }
    }
    printq(Q);
  }
  return 0;
}
