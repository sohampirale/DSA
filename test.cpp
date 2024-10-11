#include <iostream>
#include <vector>

class BankersAlgorithm {
private:
    int numProcesses;
    int numResources;
    std::vector<std::vector<int>> maxResources;
    std::vector<std::vector<int>> allocation;
    std::vector<int> available;
    std::vector<std::vector<int>> need;

public:
    BankersAlgorithm(int p, int r) : numProcesses(p), numResources(r) {
        maxResources.resize(numProcesses, std::vector<int>(numResources));
        allocation.resize(numProcesses, std::vector<int>(numResources));
        need.resize(numProcesses, std::vector<int>(numResources));
        available.resize(numResources);
    }

    void inputData() {
        std::cout << "Enter the maximum resource matrix:\n";
        for (int i = 0; i < numProcesses; ++i) {
            std::cout << "Process " << i << " Max: ";
            for (int j = 0; j < numResources; ++j) {
                std::cin >> maxResources[i][j];
            }
        }

        std::cout << "Enter the allocation matrix:\n";
        for (int i = 0; i < numProcesses; ++i) {
            std::cout << "Process " << i << " Allocation: ";
            for (int j = 0; j < numResources; ++j) {
                std::cin >> allocation[i][j];
            }
        }

        std::cout << "Enter the available resources:\n";
        std::cout << "Available Resources: ";
        for (int j = 0; j < numResources; ++j) {
            std::cin >> available[j];
        }

        for (int i = 0; i < numProcesses; ++i) {
            for (int j = 0; j < numResources; ++j) {
                need[i][j] = maxResources[i][j] - allocation[i][j];
            }
        }
    }

    bool isSafe() {
        std::vector<int> work = available;
        std::vector<bool> finish(numProcesses, false);
        std::vector<int> safeSequence;

        while (safeSequence.size() < numProcesses) {
            bool found = false;

            for (int p = 0; p < numProcesses; ++p) {
                if (!finish[p]) {
                    bool canAllocate = true;
                    for (int j = 0; j < numResources; ++j) {
                        if (need[p][j] > work[j]) {
                            canAllocate = false;
                            break;
                        }
                    }

                    if (canAllocate) {
                        for (int j = 0; j < numResources; ++j) {
                            work[j] += allocation[p][j];
                        }
                        finish[p] = true;
                        safeSequence.push_back(p);
                        found = true;
                    }
                }
            }

            if (!found) {
                std::cout << "System is not in a safe state!\n";
                return false;
            }
        }

        std::cout << "System is in a safe state.\nSafe sequence: ";
        for (int p : safeSequence) {
            std::cout << "P" << p << " ";
        }
        std::cout << "\n";
        return true;
    }
};

int main() {
    int numProcesses, numResources;

    std::cout << "Enter number of processes: ";
    std::cin >> numProcesses;
    std::cout << "Enter number of resources: ";
    std::cin >> numResources;

    BankersAlgorithm banker(numProcesses, numResources);
    banker.inputData();
    banker.isSafe();

    return 0;
}
