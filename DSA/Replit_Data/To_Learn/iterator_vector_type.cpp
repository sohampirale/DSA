//aso whywe needto use :: sign everytime


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int n;
// int ox, oy;
// int ex, ey;
// int sx, sy;

// int test_x(int sx, int sy, vector<int>& x, vector<int>& y) {
//     // Correctly specify the iterator type
//     vector<int>::iterator p;
//     p = find(x.begin(), x.end(), sx);

//     if (p != x.end()) {
//         // Element found
//         int index = distance(x.begin(), p);
//         // Do something with the index or the element
//         cout << "Element " << sx << " found at position " << index << endl;
//         return index; // Example return value, change as needed
//     } else {
//         // Element not found
//         cout << "Element " << sx << " not found in vector x." << endl;
//         return -1; // Example return value indicating not found
//     }
// }

// int test_y(int sx, int sy, vector<int>& x, vector<int>& y) {
//     // Implement the test_y function as needed
//     return 0;
// }

// int backtracking(int sx, int sy, vector<int>& x, vector<int>& y) {
//     // Add your backtracking logic here. For now, this is a placeholder.
//     int cnt = 0;
//     cnt += backtracking(sx - 1, sy, x, y);
//     cnt += backtracking(sx, sy - 1, x, y);
//     return cnt;
// }

// int main() {
//     cout << "Enter the destination x & y co-ordinates : ";
//     cin >> ex >> ey;
//     cout << "Enter the starting x & y co-ordinates : ";
//     cin >> sx >> sy;
//     cout << "Enter how many obstacles you have : ";
//     cin >> n;
//     vector<int> x(n);
//     vector<int> y(n);
//     for (int i = 0; i < n; ++i) {
//         cout << "Enter x & y co-ordinates of obstacle-" << i + 1 << " : ";    
//         cin >> x[i];
//         cin >> y[i];
//     }

//     // Further implementation...
//     // For example, you might call test_x or test_y functions here to check something.

//     return 0;
// }
