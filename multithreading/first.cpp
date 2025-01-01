#include <iostream>
#include <thread>
using namespace std;

// Function for thread
void task1() {
    for (int i = 0; i < 5; ++i) {
        cout << "Task 1 is running\n";
        this_thread::sleep_for(chrono::milliseconds(500)); // Simulate some work
    }
}

void task2() {
    for (int i = 0; i < 5; ++i) {
        cout << "Task 2 is running\n";
        this_thread::sleep_for(chrono::milliseconds(500)); // Simulate some work
    }
}

int main() {
    thread t1(task1); // Start thread 1
    thread t2(task2); // Start thread 2

    t1.join(); // Wait for thread 1 to complete
    t2.join(); // Wait for thread 2 to complete

    cout << "Both tasks are finished\n";
    return 0;
}
