// #include <iostream>
// #include <vector>
// #include <algorithm>

// int main() {
//     std::vector<std::vector<int>> vec = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     int target = 4;

//     // Use std::find_if to find the row where the first element is the target
//     auto it = std::find_if(vec.begin(), vec.end(), [target](const std::vector<int>& row) {
//         return !row.empty() && row[0] == target;
//     });

//     if (it != vec.end()) {
//         std::cout << "Element " << target << " found in the first column of some row." << std::endl;
//     } else {
//         std::cout << "Element " << target << " not found in the first column of any row." << std::endl;
//     }

//     return 0;
// }
