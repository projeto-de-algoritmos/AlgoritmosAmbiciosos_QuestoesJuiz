#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<long long> N(T);
    for (int i = 0; i < T; i++) {
        cin >> N[i];
    }
    
    for (int i = 0; i < T; i++) {
        long long cnta = 0; // counter for A's score
        bool isATurn = true; // flag to check whose turn is it
        
        while (N[i] > 0) {
            if (N[i] > 4 && N[i] % 4 == 0) {
                if (isATurn) {
                    cnta++;
                }
                N[i]--;
            } else {
                if (N[i] % 2 == 0) {
                    if (isATurn) {
                        cnta += N[i] / 2;
                    }
                    N[i] /= 2;
                } else {
                    if (isATurn) {
                        cnta++;
                    }
                    N[i]--;
                }
            }
            isATurn = !isATurn; // toggle the turn
        }
        cout << cnta << endl;
    }
    
    return 0;
}
