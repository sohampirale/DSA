// declarations.h
#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Variable and vector declarations
extern bool reqRes, isImp;
extern int bt, memory, priority, n, k_resources_of_each, n_resources;
extern string PId, resource_name;
extern vector<int> k_needed, k_allocated;
extern vector<resource> all_resources;
extern vector<process> all_processes;
extern vector<process_using_resource> all_processes_using_resources;
extern vector<batch> all_batches;
extern vector<core> all_cores;

// Function declarations
void create_batches(vector<batch>& batches);
void create_cores(vector<core>& all_cores, vector<batch>& all_batches);
int start();
void load_manually(vector<int>& k_needed, vector<int>& k_allocated, vector<resource>& all_resources, vector<process>& all_processes, vector<process_using_resource>& all_processes_using_resources);
void load_from_file(vector<resource>& all_resources, vector<process>& all_processes, vector<process_using_resource>& all_processes_using_resources);
void store_processes(vector<process>& all_processes, vector<batch>& all_batches);
void store_processes_using_resources(vector<process_using_resource>& all_processes_using_resources, vector<batch>& all_batches);

#endif // DECLARATIONS_H
