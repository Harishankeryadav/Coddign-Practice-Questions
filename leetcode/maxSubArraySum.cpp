#include <iostream> 
#include <vector>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int i = 0;
    double ans = 0.0;
    int j = 0;
    while (j < k)
    {
        ans += nums[j++];
    }
    // int y = j;
    double x = ans/k;
    double val = ans/k;
    while (i <= nums.size() - k)
    {
    // vector<int> x = {1, 12, -5, -6, 50, 3};
        if (x > val){
            // ans = x;
            val = x;
            }

        cout << i << " ni " << nums[i] << " ans " << ans << endl;
        ans -= nums[i];
        x = ans + nums[j];
        cout << j << " nj " << nums[j] << " x " << x << endl;
        x = x / k;
        cout << " x-> " << x << " x-> " << x << endl;
        cout << endl;
        j++;
        i++;
    }
    return val;
}
int main()
{
    vector<int> x = {5};
    int l = 43196;
    cout << "ans-> " << findMaxAverage(x, l);
}