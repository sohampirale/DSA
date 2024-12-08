#include <iostream>
#include <fcntl.h>    // For O_RDONLY
#include <sys/mman.h> // For shm_open, mmap, PROT_READ
#include <unistd.h>   // For close

int main() {
    const char* name = "/shared_memory_example"; // Shared memory name
    const int SIZE = 4096;                       // Size of shared memory

    // Open the existing shared memory object
    int shm_fd = shm_open(name, O_RDONLY, 0666);
    if (shm_fd == -1) {
        std::cerr << "Failed to open shared memory\n";
        return 1;
    }

    // Map shared memory to process's address space
    void* ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        std::cerr << "Failed to map shared memory\n";
        return 1;
    }

    // Read data from shared memory
    std::cout << "Data read from shared memory: " << static_cast<char*>(ptr) << "\n";

    // Clean up
    munmap(ptr, SIZE);
    close(shm_fd);

    // Optionally unlink the shared memory object (if no longer needed)
    shm_unlink(name);

    return 0;
}
