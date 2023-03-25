// A boy climbs the stairs and he can climb 1, 2 or 3 stairs at a time. find the number of ways he can climb n stairs.
#include <bits/stdc++.h>
using namespace std;

int stairecase(int n)
{
    if (n == 0)
        return 1;
    if (n == 1 || n == 2)
        return n;
    int stairs = stairecase(n - 1) + stairecase(n - 2) + stairecase(n - 3);
    return stairs;
}

int main()
{
    cout << stairecase(5);
}