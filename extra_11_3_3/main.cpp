//the program equals the elements of array to a target value 
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;
 
int minOperation (int array[], int num){
    unordered_map<int, int> hash;
    for (int i = 0; i < num; i++){
        hash[array[i]]++;
    }
    int max= 0;
    for (auto i : hash){
        if (max < i.second){
            max = i.second;
        }
    }
    return (num - max);
}
 
int main()
{
    int array[] = {2,5,4,2,3,6,1};
    int num = sizeof(array) / sizeof(array[0]);
    cout << minOperation(array, num);
    return 0;
}