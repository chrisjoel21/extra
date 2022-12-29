//the program evaluates the subarray sum of 0 using array (hashing)
#include <iostream>
using namespace std;

void printArray(int arr[], int i){
    for (int m = 0; m < i; m++) {
        int sum = 0;
        for (int n = m; n < i; n++) {
            sum += arr[n];
            if (sum == 0) {
                cout << "Subarray [" << m << "…" << n << "]\n";
            }
        }
    }
}
 
int main() {
    int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    int num = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, num);
 
    return 0;
}