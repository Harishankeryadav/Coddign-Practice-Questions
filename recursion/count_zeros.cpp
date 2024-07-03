//counting zeros in the given array
#include<iostream>
using namespace std;

int count(int arr[], int num){
    static int data = 0;
    if(num == 0)
        return data;
    if(arr[0] == 0)
        data++;
    count(arr + 1, num - 1);
    return data;
}

int main(){
    int arr[20], num;
    cout  << "Enter the size of array and then array \n";
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    cout << count(arr, num); 
}