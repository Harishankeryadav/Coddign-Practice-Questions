//adition of array by using recursion.
#include <iostream>
using namespace std;

int sum(int arr[], int size){
    static int sum1= 0;
    if (size == 0)
        return sum1;
    sum1 = sum1 + arr[0];
    sum(arr + 1, size - 1);
    return sum1;
}

int main(){
    int arr[5];
    cout << "Enter the array\n";
    for(int i = 0; i < 5; i++)
    cin >> arr[i];
    cout << sum(arr, 5);
    return 0;
}