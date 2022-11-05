
#pragma once

#include <vector>
#include "HospitalQueue.hpp"

const int max_specialization = 20;
const int max_queue = 5;

class HospitalSystem {

private:
    std::vector <HospitalQueue> queues;
public:
    HospitalSystem();
    void run();
    int menu();
    void add_patient();
    void print_patients();
    void get_next_patient();


};



