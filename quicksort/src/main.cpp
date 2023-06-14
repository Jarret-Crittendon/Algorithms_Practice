#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

template <typename T>
void quicksort(std::vector<T> &vec);

int main() {
    std::vector<int> ivec {5, 9, 7, 1, 0, 8, 2, 4, 3, 6};
    std::vector<std::string> svec {
        "MINASE Iori",
        "TAKATSUKI Yayoi",
        "SHIJOU Takane",
        "SONODA Chiyoko",
        "TACHIBANA Arisu",
        "SASAKI Chie",
        "JOUGASAKI Rika",
        "SATOU Shin",
        "SUOU Momoko",
        "MORINO Rinze"
    };

    quicksort(ivec);
    for (const auto& i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    quicksort(svec);
    /*for (const auto& s : svec) {
        std::cout << s << "\n";
    }*/
    std::for_each(svec.begin(), svec.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << std::endl;

    return 0;
}


template <typename T>
void quicksort(std::vector<T> &vec) {
    const std::size_t SIZE = vec.size();
    
    // base case
    if (SIZE < 2 ) {
        return;
    }

    // Get random number for randomized pivot
    // Unless the random seed is changed every time the program is called,
    // I will keep getting the same number!
    srand(time(NULL));

    // Get randomized pivot 
    const auto pivot = vec.at(rand() % SIZE);

    // Make sub-arrays 
    std::vector<T> less;
    std::vector<T> greater;

    for (const auto& i : vec) {
        // sub-array for items smaller than pivot value
        if (i < pivot) {
            // items smaller than the pivot go to the less subarray
            less.push_back(i);
        } else if (i > pivot) {
            greater.push_back(i);
        } 
    }

    quicksort(less);
    quicksort(greater);

    // Wipe the array
    vec.clear();

    vec.insert(vec.end(), less.begin(), less.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), greater.begin(), greater.end());
}