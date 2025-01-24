#include <stdio.h>
#include <iostream>

using namespace std; 

int calls;

int fibonacci(int n){
  if(n == 0)
    return 0;
  if(n == 1)
    return 1;

  calls+=2;
  return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
  int n, x;
  cin >> n;
  while(n > 0){
    cin >> x;
    calls = 0;
    int result = fibonacci(x);
    cout << "fib(" << x << ") = " << calls << " calls = " << result << endl;
    n--;
  }
  return 0;
}
