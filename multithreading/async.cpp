#include <iostream>
#include<vector>
#include <future>
using namespace std;

vector<int> calculateSquare(int x) {
    // this_thread::sleep_for(chrono::seconds(10)); // Simulate delay
    vector<int>test;
    for(int i=0;i<1000000000;i++)test.push_back(i);
    return test;
}

int main() {
    // Start task asynchronously
    future<vector<int>> result = async(calculateSquare, 5);

    cout << "Doing other work while the calculation is happening...\n";
    // vector<int>test=result.get();
    // Wait for result and print it
    // cout << "Siz eof vector received is: " << test.size() << endl;
    // cout<<result.get()[0];
    cout<<"hey"<<endl;
    return 0;
}
