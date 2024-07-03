#include <bits/stdc++.h>
using namespace std;

 int nthUglyNumber(int n) {
        int arr[n];
        arr[0] = 1;
        int mul_2 = 2, mul_3 = 3, mul_5 = 5;
        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; i++) {
            int nxtU = min(mul_2, min(mul_3, mul_5));
            arr[i] = nxtU;
            if (nxtU == mul_2) {
                i2++;
                mul_2 = arr[i2] * 2;
            }
            if (nxtU == mul_3) {
                i3++;
                mul_3 = arr[i3] * 3;
            }
            if (nxtU == mul_5) {
                i5++;
                mul_5 = arr[i5] * 5;
            }
        }
        return arr[n-1];
    }

int main()
{
    int x = nthUglyNumber(11);
    cout << "\nans-> " << x;
}