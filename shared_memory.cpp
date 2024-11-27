#include <iostream>
#include <fcntl.h>    // For O_CREAT, O_RDWR
#include <sys/mman.h> // For shm_open, mmap, PROT_READ, PROT_WRITE
#include <unistd.h>   // For ftruncate

int main() {
    const char* name = "/shared_memory_example"; // Shared memory name
    const int SIZE = 4096;                       // Size of shared memory

    // Create shared memory object
    int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        std::cerr << "Failed to create shared memory\n";
        return 1;
    }

    // Set size of shared memory
    ftruncate(shm_fd, SIZE);

    // Map shared memory to process's address space
    void* ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        std::cerr << "Failed to map shared memory\n";
        return 1;
    }

    // Write data to shared memory
    const char* message = "Hello from Program A!";
    sprintf(static_cast<char*>(ptr), "%s", message);

    std::cout << "Data written to shared memory: " << message << "\n";

    // Do not unlink here if another process needs to read this
    return 0;
}
