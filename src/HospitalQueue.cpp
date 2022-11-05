
#include "HospitalQueue.hpp"

HospitalQueue::HospitalQueue() {
    spec = -1;
}

HospitalQueue::HospitalQueue(int _spec) {
    spec = _spec;
}

bool HospitalQueue::add_end(std::string name, int st) {
    que.push_back({ name,st });
    return true;
}

bool HospitalQueue::add_front(std::string name, int st) {
    que.push_front({ name,st });
    return true;
}

void HospitalQueue::remove_front() {
    if (que.size() == 0) {
        std::cout << "No patient at the moment. Have a rest, Dr\n";
        return;
    }
    std::cout << que.front().first << " please go with the doctor\n";
    que.pop_front();
}

void HospitalQueue::print() {
    if (que.size() == 0)
        return;
    std::cout << "There are " << que.size() << " patients in specialization " << spec << "\n";
    for (auto item : que) {
        std::cout << item.first << " ";
        if (item.second)
            std::cout << "urgent\n";
        else
            std::cout << "regular\n";
    }
    std::cout << std::endl;
}
