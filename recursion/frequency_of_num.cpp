//frequency of occurence of number and indexs are.

#include<iostream>
using namespace std;

int arr1[20];
int frequency(int arr[],int start, int size, int key){
    static int temp=0,i = 0;
    if(start >= size)
        return temp;
    if(arr[start] == key){
        arr1[i] = start; 
        i++;
        temp++;
    }
    frequency(arr, start+1, size, key);
    return temp;

}
int main()
{
    int arr[]= {3, 5, 5, 8 ,3, 5}, size = 6,key =3;
    int temp =frequency(arr, 0, size, key);
    cout <<"frequency is "<< temp<<"\nindex's are ";
    for(int i = 0; i < temp; i++){
        cout << arr1[i]<<" ";
    }
}