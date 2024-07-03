#include <iostream>
#include <vector>
using namespace std;

// vector<int> v;
int fibb(int num)
{
    // int data;
    if (num <= 1)
    {
        // v.push_back(num);
        return num;
    }
    else
        return fibb(num - 1) + fibb(num - 2) + 1;           

    // v.push_back(data);
}

// int sum(int n){
//     int x=0;
//     for(int i=0;i<n;i++){
//        x+=fibb(i);

//     }
//     return x;
// }

int main()
{
    cout << fibb(4);
    return 0;
}