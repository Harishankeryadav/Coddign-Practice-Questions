#include <iostream>
#include <vector>
using namespace std;
#include <string.h>

string multiply(string num1, string num2)
{ // converting the string into number
    int i = 0;
    long long int temp1 = 0, temp2 = 0;
    string num;

    while (i < num1.size())
    {
        if (temp1 > INT_FAST32_MAX / 10)
        {
            cout << "MAX ";
            return num;
        }
        temp1 = temp1 * 10 + (num1[i] - '0');
        i++;
    }
    i = 0;
    while (i < num2.size())
    {
        if (temp2 > INT_FAST32_MAX / 10)
        {
            cout << "MAX ";
            return num;
        }
        temp2 = temp2 * 10 + (num2[i] - '0');
        i++;
    }
    cout << "temp1-> " << temp1 << endl;
    cout << "temp2-> " << temp2 << endl;
    int mul = temp1 * temp2;
    if (mul > INT_FAST32_MAX / 10)
    {
        cout << "MAX ";
        return num;
    }
    // reversing the multiplied number.
    int temp = 0;
    if(mul == 0){
         char d = mul + '0';
        num = num + d;
        return num;
    }
    while (mul > 0)
    {
        temp = temp*10 + mul % 10;
        mul /= 10; 
    }
    // converting the given number into string again
    i = 0;
    while (temp > 0)
    {
        char d = (temp % 10) + '0';
        num = num + d;
        temp /= 10;
        // i++;
    }
    cout << "num-> " << num;
    return num;
}

 string multiply2(std::string num1, std::string num2) {
    long long int temp1 = 0, temp2 = 0;
    
    // Convert num1 to integer
    for (char c : num1) {
        if (temp1 > std::numeric_limits<int>::max() / 10) {
            return "0"; // Overflow
        }
        temp1 = temp1 * 10 + (c - '0');
    }
    
    // Convert num2 to integer
    for (char c : num2) {
        if (temp2 > std::numeric_limits<int>::max() / 10) {
            return "0"; // Overflow
        }
        temp2 = temp2 * 10 + (c - '0');
    }
    
    long long int mul = temp1 * temp2;
    if (mul == 0) {
        return "0";}
    // } else if (mul > numeric_limits<int>::max() || mul < numeric_limits<int>::min()) {
    //     return "Overflow";
    // }

    return std::to_string(mul);
}

int main()
{
    // int n = 10, x = 2;
    // int sum = 1;
    //     while(n > 0){
    //             cout <<"x-> " <<x <<" n -> " << n <<" " << sum <<endl;
    //             sum = sum*x;
    //             n--;
    //         }
    //         cout << sum;
    string a = "0", b = "0";
    string x = multiply2(a, b);
    cout << x;
    return 0;
}