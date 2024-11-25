
#include <bits/stdc++.h>
using namespace std;

// Comparator for sorting processes by minimum burst time
struct compMinBT {
    bool operator()(const process &a, const process &b) const {
        return a.burst_time > b.burst_time; // Min heap based on burst time
    }
};

// Comparator for resource allocation
struct compMinResReq {
    bool operator()(const process_using_resource &a, const process_using_resource &b) const {
        int totalA = accumulate(a.need.begin(), a.need.end(), 0);
        int totalB = accumulate(b.need.begin(), b.need.end(), 0);
        return totalA > totalB; // Min heap based on total resource needs
    }
};

class batch {
    string batch_name;
    vector<priority_queue<process, vector<process>, compMinBT>> schedulingQueues;
    vector<queue<process>> roundRobinQueues;
    vector<priority_queue<process_using_resource, vector<process_using_resource>, compMinResReq>> resourceQueues;

public:
    batch(string name, int type) : batch_name(name) {
        switch (type) {
            case 1: schedulingQueues.resize(6); break;  // For multi-level queues
            case 2: roundRobinQueues.resize(6); break; // For Round Robin
            case 3: schedulingQueues.resize(2); break; // For real-time processes
            case 4: resourceQueues.resize(2); break;   // For resource allocation
            default: throw invalid_argument("Invalid batch type!");
        }
    }

    void addProcess(const process &p, int type = 1) {
        if (type == 1 && !schedulingQueues.empty()) {
            schedulingQueues[0].push(p);
        } else if (type == 2 && !roundRobinQueues.empty()) {
            roundRobinQueues[0].push(p);
        } else {
            cout << "Invalid type or batch configuration!
";
        }
    }

    void assignProcess(core &receiver) {
        if (receiver.workingBatch != nullptr) {
            cout << "Core is already working on a batch.
";
            return;
        }

        // Simplified assignment logic for scheduling queues
        for (auto &queue : schedulingQueues) {
            if (!queue.empty()) {
                receiver.workingBatch = &queue.top();
                queue.pop();
                return;
            }
        }

        // Handle round-robin queues if applicable
        for (auto &queue : roundRobinQueues) {
            if (!queue.empty()) {
                receiver.workingBatch = &queue.front();
                queue.pop();
                return;
            }
        }

        cout << "No available processes to assign.
";
    }
};


// File handling for processes and resources
void loadProcessesFromFile(const string &fileName, vector<process> &processList) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Failed to open file: " << fileName << endl;
        return;
    }

    process temp;
    while (file >> temp.id >> temp.burst_time) {
        processList.push_back(temp);
    }
    file.close();
}

void loadResourcesFromFile(const string &fileName, vector<resource> &resourceList) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Failed to open file: " << fileName << endl;
        return;
    }

    resource temp;
    while (file >> temp.id >> temp.total >> temp.available) {
        resourceList.push_back(temp);
    }
    file.close();
}

// Main execution point for the batch system
int main() {
    // Example of creating a batch system
    batch multiLevelBatch("Multi-Level Batch", 1);
    vector<process> processList;
    vector<resource> resourceList;

    // Load data from files
    loadProcessesFromFile("processes.txt", processList);
    loadResourcesFromFile("resources.txt", resourceList);

    // Add processes to the batch
    for (const auto &p : processList) {
        multiLevelBatch.addProcess(p, 1);
    }

    // Simulate core assignments
    core cpuCore;
    multiLevelBatch.assignProcess(cpuCore);

    return 0;
}
