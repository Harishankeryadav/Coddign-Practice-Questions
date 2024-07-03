#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool descendingComparator(int a, int b) {
    return a > b;
}

int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 5};
    std::sort(numbers.begin(), numbers.end(), descendingComparator);

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
