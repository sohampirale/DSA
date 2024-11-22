// definitions.cpp
#include "declarations.h"

// Variable definitions
bool reqRes, isImp;
int bt, memory, priority, n, k_resources_of_each, n_resources;
string PId, resource_name;
vector<int> k_needed, k_allocated;
vector<resource> all_resources;
vector<process> all_processes;
vector<process_using_resource> all_processes_using_resources;
vector<batch> all_batches;
vector<core> all_cores;
