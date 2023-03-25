#include <iostream>
#include <time.h>
using namespace std;

void random(int arr[], int num)
{
    srand(time(0));
    for (int i = 0; i < num; i++)
    {
        int random = rand() % 100;
        arr[i] = random;
    }
}
void print(int arr[], int num)
{
    cout << "random array is\n";
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
}
void randnum(int arr[], int n)
{
    int s = rand() % n;
    cout << "\nrandom number is from array is: " << arr[s];
}
int main()
{
    std::cout << "Hello world!\n";
    int arr[10], num;
    cout << "Enter the size of array \n";
    cin >> num;
    random(arr, num);
    print(arr, num);
    randnum(arr, num);
    return 0;
}