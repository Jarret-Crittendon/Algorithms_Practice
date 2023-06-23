#include <iostream>
#include <map>
#include <set>
#include <limits>
#include <deque>

std::string lowest_cost_node(std::map<std::string, int>, const std::set<std::string> &);
void print_path(const std::map<std::string, std::string> &);

int main() {
    std::map<std::string, std::map<std::string, int>> graph;
    graph["Arisu"]["Rika"] = 6;
    graph["Arisu"]["Chie"] = 6;
    graph["Rika"]["Anna"] = 5;
    graph["Rika"]["Reina"] = 2;
    graph["Chie"]["Sana"] = 9;
    graph["Chie"]["Hikaru"] = 8;
    graph["Reina"]["Sana"] = 1;
    graph["Reina"]["Hikaru"] = 2;
    graph["Sana"]["Anna"] = 4;
    graph["Hikaru"]["Kaori"] = 1;
    graph["Anna"]["Kaori"] = 2;
    graph["Kaori"];

    // Displays the costs of reaching each node from the starting node
    // In this case the starting node is Arisu
    std::map<std::string, int> costs;
    using max_val = std::numeric_limits<decltype(costs)::mapped_type>;
    costs["Rika"] = 6;
    costs["Chie"] = 3;
    costs["Anna"] = max_val::max();
    costs["Sana"] = max_val::max();
    costs["Reina"] = max_val::max();
    costs["Hikaru"] = max_val::max();
    costs["Kaori"] = max_val::max();

    std::map<std::string, std::string> parents;
    parents["Rika"] = "Arisu";
    parents["Chie"] = "Arisu";
    parents["Anna"] = "Sana";
    parents["Sana"] = "Chie";
    parents["Reina"] = "Rika";
    parents["Hikaru"] = "Reina";
    parents["Kaori"] = "Anna";

    std::set<std::string> processed;

    // find the lowest cost node that hasn't been processed
    // get the cost of that node
    // get the neighbors of that node (the hashmap of the node's neighbors)
    // go through all neighbors of this node
    // Get cost to get to this node from start
    // if it's cheaper to get to this neighbor by going through this node...
    // update the cost for this neighbor node
    // current node becomes the new parent for this neighbor
    // mark current node as processed after all neighbor nodes are checked
    // find the next lowest code node to process, then loop

    auto node = lowest_cost_node(costs, processed);
    while (!node.empty()) {
        auto cost = costs[node];
        auto neighbors = graph[node];
        for (const auto& neighbor : neighbors) {
            auto new_cost = cost + neighbor.second;
            if (new_cost < costs[neighbor.first]) {
                costs[neighbor.first] = new_cost;
                parents[neighbor.first] = node;
            }
        }
        processed.insert(node);
        node = lowest_cost_node(costs, processed);
    }

    print_path(parents);
    std::cout << std::endl;
    for (const auto &i : costs) {
        std::cout << i.first << "\t" << i.second << std::endl;
    }
}

std::string
lowest_cost_node(std::map<std::string, int> hashmap, const std::set<std::string> &checked) {
    decltype(hashmap)::key_type lowest_cost_node;
    decltype(hashmap)::mapped_type lowest_cost;
    lowest_cost = std::numeric_limits<decltype(hashmap)::mapped_type>::max();
    for (const auto &node : hashmap) {
        auto cost = hashmap[node.first];
        if (checked.find(node.first) == checked.end()) {
            if (cost < lowest_cost) {
                lowest_cost_node = node.first;
                lowest_cost = cost;
            }
        }
    }

    return lowest_cost_node;
}

void print_path(const std::map<std::string, std::string> &parent_map) {
    std::string node("Kaori");
    std::deque<std::string> path;
    path.push_front(node);
    while (parent_map.find(node) != parent_map.end()) {
        path.push_front(parent_map.at(node));
        node = parent_map.at(node);
    }

    for (auto beg = path.begin(); beg != path.end(); ++beg) {
        if (beg == path.end()-1) {
            std::cout << *beg;
            break;
        }
        std::cout << *beg << " -> ";
    }
    std::cout << "\nDestination Reached" <<  std::endl;
}