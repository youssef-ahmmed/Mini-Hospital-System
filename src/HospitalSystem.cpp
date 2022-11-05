
#include "HospitalSystem.hpp"

HospitalSystem::HospitalSystem() {
    queues = std::vector<HospitalQueue>(max_specialization);
    for (int i = 0; i < max_specialization; i++) {
        queues[i] = HospitalQueue(i);
    }
}

void HospitalSystem::run() {
    while (true) {
        int choice = menu();
        if (choice == 1)
            add_patient();
        else if (choice == 2)
            print_patients();
        else if (choice == 3)
            get_next_patient();
        else
            break;
    }
}

int HospitalSystem::menu() {
    int choice = -1;
    while (choice == -1) {
        std::cout << "\nEnter your choice:\n";
        std::cout << "1) Add new patient\n";
        std::cout << "2) Print all patients\n";
        std::cout << "3) Get next patient\n";
        std::cout << "4) Exit\n";
        std::cin >> choice;
        if (!(1 <= choice && choice <= 4)) {
            std::cout << "Invalid input. Try again\n";
            choice = -1;
        }
    }
    return choice;
}

void HospitalSystem::add_patient() {
    int spec, st;
    std::string name;
    std::cout << "Enter specialization, name, status: ";
    std::cin >> spec >> name >> st;
    bool status;
    if (st == 1)
        status = queues[spec].add_end(name, st);
    else
        status = queues[spec].add_front(name, st);
    if (status == false) {
        std::cout << "Sorry we can't add more patients for this specialization\n";
        return;
    }
}

void HospitalSystem::print_patients() {
    std::cout << "*******************************************************************\n";
    for (int i = 0; i < max_specialization; i++) {
        queues[i].print();
    }
}

void HospitalSystem::get_next_patient() {
    int spec;
    std::cout << "Enter specialization: ";
    std::cin >> spec;
    queues[spec].remove_front();
}
