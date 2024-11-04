#pragma once

void load_manually(vector<int>&k_needed,vector<int>&k_allocated,vector<resource>&all_resources,vector<process>&all_processes,vector<process_using_resource>&all_processes_using_resources);
void load_from_file(vector<resource>&all_resources,vector<process>&all_processes,vector<process_using_resource>&all_processes_using_resources);
void load_processes_from_file(vector<resource>&all_resources,vector<process>&all_procesees,vector<process_using_resource>&all_process_using_resources);
void load_processes_using_resources_from_file(vector<resource>&all_resources,vector<process>&all_procesees,vector<process_using_resource>&all_process_using_resources);
void load_normal_processes_from_file(vector<process>&all_procesees);
void load_resources_from_file(vector<resource>&all_resources);
