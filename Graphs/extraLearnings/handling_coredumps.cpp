#include <csignal>
#include <iostream>
#include <cstdlib>
using namespace std;

// Custom cleanup function
void cleanup() {
    cout << "Cleaning up before exit..." << endl;
    // Add your cleanup logic here (e.g., freeing graph memory)
}

// Signal handler for segmentation faults
void signalHandler(int signum) {
    cout << "Caught signal " << signum << ". Cleaning up resources..." << endl;
    cleanup();
    exit(signum);
}

int main() {
    signal(SIGSEGV, signalHandler); // Catch segmentation faults

    // Example graph code causing segmentation fault
    int* ptr = nullptr;
    cout << *ptr << endl; // This will cause a SIGSEGV

    return 0;
}
