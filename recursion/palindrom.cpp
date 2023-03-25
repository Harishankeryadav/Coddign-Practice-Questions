// checking if the given array if plindrom or not by using recursion.
#include <iostream>
using namespace std;

// // bool check_palindrom(int arr[],int s, int size)
// // {
// //     if(size==0)
// //     return true;
// //     if (s == size)
// //     return true;
// //     if (arr [s] != arr[size])
// //         return false;
// //     if(s < size + 1)
// //         return  check_palindrom(arr,s+1,size - 1);
// //     return true;
// // }

// void check_palindrom(int arr[], int size){
//     int i, start = 0;
//     for(i = 1; i <= size; i++ ){
//         if(arr[i] = arr[size]){
//         size--;
//         cout<< true;}
//         else
//             cout<< false;
//     }
// }

// int main()
// {
//     int arr[20] = {1, 2, 1}, size = 3;
//     //cout << "Enter the  size of array and then arrray\n";
//     // cin >> size;
//     // for (int i = 0; i < size; i++)
//     // {
//     //     cin >> arr[i];
//     // }
//     check_palindrom(arr, size);
// }

int main()
{
    int arr[] = {1, 2, 3}, size = 3, arr1[20];
    int num = size;
    for (int i = 1; i < size; i++)
    {
        arr1[i] = arr[size];
        size--;
    }
    for (int i = 0; i < num; i++)
    {
        if (arr[i] == arr1[i])
            cout << true;
        else
            cout << false;
    }
}