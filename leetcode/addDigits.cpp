#include <iostream>
#include <vector>
using namespace std;

int addDigits(int num)
{
    while (true)
    {
        int sum = 0;
        if (num < 10)
            return num;
        while (num > 0)
        {
            int d = num % 10;
            // if (sum > INT32_MAX / 10 || sum == INT32_MAX)
            //     return -1;

            sum = sum + d;
            num /= 10;
            // cout << num << " num " << d << " d" << endl;
        }
        // cout << sum << " sum " << endl;
        num = sum;
    }
}

 int addDigits1(int num) {
        if(num==0){
           return 0;
        }
        else if(num%9==0){
            return 9;
        }
        cout << num <<endl;
        return num%9;
    }

int main()
{
    int num = 144;
    cout << addDigits(num);
}