#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    float MRT = 0;
    float sum = 0;
    int n;
    
    cout << "Enter the number of tapes: ";
    cin >> n;
    int L[n];

    cout << "Enter the length of tapes: ";
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    sort(L, L + n);
    
    for (int j = 0; j < n; j++) {
        sum += L[j];
    }

    MRT = sum / n; // Calculate mean
    cout << "The Mean Retrieval time is: " << MRT;
    return 0;
}
