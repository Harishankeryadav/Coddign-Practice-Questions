//multiplication of 2 number in addition of substraction manner
//for example: 3*5 --> 3+3+3+3+3 = 15
#include <iostream>
using namespace std;

int mul(int n, int m){
    static int data  = 0;
    if (m == 0)
        return data;
    if(m >= 1)
        data = data + n ;
    mul(n, m - 1);
    return data;
}
int main(){
    int n , m;
    cout << "Enter the number \n";
    cin >> n >> m;
    cout << mul(n,m);
}