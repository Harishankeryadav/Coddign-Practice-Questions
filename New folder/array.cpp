// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// bool comparator(int a, int b)
// {
//     return a > b;
// }

// int main()
// {
//     vector<int> arr = {1, 7, 3, 8, 9, 3, 4, 0};
//     arr.resize(5);
//     arr.erase(arr.begin()+1);
//     sort(arr.begin(), arr.end(), comparator);
//     for (auto it : arr)
//         cout << it << " ";
// }

// Online C++ compiler to run C++ program online
// #include <iostream>
// #include<vector>
// using namespace std;

// int main() {
// vector<vector<int>> v = {{5, 5, 5},{3, 2, 4},{1, 4, 1 },{2, 1, 3},{3, 2, 4},{3 , 3, 4 }};

//     for(int i = 0; i < v.size(); i++){
//         for(int j = 0; j < 3; j++){
//             if(i != j && j < v.size()){
//                 cout << v[i][j] << "  ";
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <utility> // For std::pair

// Function to create pairs of all elements in a 2D vector
std::vector<std::pair<int, int>> createPairs(const std::vector<std::vector<int>>& v) {
    std::vector<std::pair<int, int>> pairs;
    for (const auto& row : v) {
        for (int value : row) {
            pairs.push_back(std::make_pair(value, value));
        }
    }
    return pairs;
}

int main() {
    // Create a 2D vector
    std::vector<std::vector<int>> v = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Create pairs of all elements
    std::vector<std::pair<int, int>> pairs = createPairs(v);

    // Print the pairs
    for (const auto& pair : pairs) {
        std::cout << "Element: " << pair.first << " Value: " << pair.second << "\n";
    }

    return 0;
}
