#include <iostream>
using namespace std;

int fibb(int num){
    int data;
    if (num <= 1)
        return num;
    else 
        data = fibb(num - 1) + fibb(num - 2);
    return data;
}
int main(){
    int num;
    cout <<"Enter the number\n";
    cin >> num;
    cout << fibb(num);

}