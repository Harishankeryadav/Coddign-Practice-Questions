#include <iostream>
using namespace std;


int lenOfLongSubarr(int arr[], int N, int K) 
{
    int i = 0, j = 0, sum = 0, maxi = 0;
    while (j < N) 
    {
        sum += arr[j];  // Add the current element to the sum

        while (sum > K && i <= j)  // Adjust the window if sum exceeds K
        {
            sum -= arr[i];  // Subtract element from sum and move i
            i++;
        }

        if (sum == K)  // Check if the sum is equal to K
        {
            maxi = max(maxi, j - i + 1);  // Update the maximum length
        }

        j++;  // Move the window forward
    }
    return maxi;
}

int main()
{
    int arr[] = {-13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6};
    cout << "\nlen: " << lenOfLongSubarr(arr, 17, 15);
}

// 17 15
// -13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6
