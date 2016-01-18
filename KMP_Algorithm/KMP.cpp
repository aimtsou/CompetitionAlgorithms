#include <iostream>
#include <cstdlib>
#include <string>
 
using namespace std;
 
int *compute_prefix(string Pattern) {
  int i, k = 0;
  int N = Pattern.size();
  int * pi;
  
  pi = new int [N];

  for(i = 0; i < N; i++)
      pi[i] = 0;

  for(i = 1; i < N; i++) {
    while (k > 0 && Pattern[k] != Pattern[i])
        k = pi[k-1];

    if (Pattern[k] == Pattern[i])
        k = k+1;

    pi[i] = k;
  }
  return pi;
}
 
void kmp(string Target, string Pattern) {
  int i, k = 0;
  int M = Pattern.size(), N = Target.size();
  int *pi = compute_prefix(Pattern);

  for(i = 0; i < N; i++) {
    while (k > 0 && Pattern[k] != Target[i])
      k = pi[k-1];

    if (Pattern[k] == Target[i])
      k++;

    if (k == M) {
      cout << "Pattern found at index : " << i - M + 1 << endl;
      k = pi[k-1];
    }
  }
  free(pi);
}
 
int main() {
  string Target = "ABABDABACDABABCABAB";
  string Pattern = "ABABCABAB";
  kmp(Target, Pattern);

  return 0;
}