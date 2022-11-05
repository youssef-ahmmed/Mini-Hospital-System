#pragma once


#include <iostream>
#include <string>
#include <deque>


class HospitalQueue {

private:
    std::deque<std::pair<std::string, int>> que;
    int spec;

public:
    HospitalQueue();
    HospitalQueue(int _spec);
    bool add_end(std::string name, int st);
    bool add_front(std::string name, int st);
    void remove_front();
    void print();

};



