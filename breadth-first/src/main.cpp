// 2023 June 16
// Author: Jarret Crittendon
// Implementing a breadth-first graph algorithm

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <deque>
#include <string>

// In graph algorithms, hash maps can be used
// to map a node (the key) to its neighbors (the value)

// breadth-first
// Keep a queue of thing to check
// dequeue thing
// check if thing is the target/goal
// if not, add thing's values/neighbors to the queue
// loop until end is reached or goal is reached
// Keep track of duplicate values with set

void name_entries(std::map<std::string, std::vector<std::string>> &);

int main() {
    std::map<std::string, std::vector<std::string>> idols;
    name_entries(idols);
    
    std::cout << "Enter starting person: ";
    std::string start;
    std::getline(std::cin, start);
    std::cout << "Enter desired connection: ";
    std::string destination;
    std::getline(std::cin, destination);
    
    // Keep a queue of thing to check
    // Add initial neighbors to the queue
    std::deque<std::string> queue;
    const auto& v = idols[start];
    for ( const auto& i : v) {
        queue.push_back(i);
    }

    int name_count = 0;
    // Keep track of duplicate values with set
    std::set<std::string> checked;
    checked.insert(start);
    while (!queue.empty()) {
        
        const auto person = queue.front();
        queue.pop_front();
        
        if (checked.find(person) == checked.end()) {
            name_count++;
            std::cout << person << " -> ";
            if (person == destination) {
                std::cout << "\nConnection reached after meeting "
                          << name_count << " people!\n";
                return 0;
            }

            checked.insert(person);
            const auto& tmp = idols[person];
            for ( const auto& s : tmp) {
                queue.push_back(s);
            }
        }
    }

    std::cout << "Destination not found..." << std::endl;

}

void name_entries(std::map<std::string, std::vector<std::string>> &names) {
    names["Nao"] = { "Chie", "Momoka", "Arisu" };
    names["Chie"] = { "Mika", "Nao"};
    names["Arisu"] = { "Haru", "Shin", "Nao" };
    names["Momoka"] = { "Hikaru", "Yayoi", "Nao" };
    names["Mika"] = { "Hayate", "Nagi", "Anna", "Chie" };
    names["Haru"] = { "Ranko", "Arisu" };
    names["Shin"] = { "Reika", "Arisu" };
    names["Yayoi"] = { "Nagi", "Momoka" };
    names["Hikaru"] = { "Reika", "Momoka" };
    names["Reika"] = { "Hikaru", "Shin" };
    names["Ranko"] = { "Haru", "Anna" };
    names["Anna"] = { "Ranko", "Mika" };
    names["Hayate"] = { "Nagi", "Mika" };
    names["Nagi"] = { "Hayate", "Mika", "Yayoi", "Ranko" };
}