#include <iostream>
#include <vector>
#include <algorithm>

int factorial(int n) {
    if (n == 1) {
        return 1;
    }

    return n * factorial(n-1);
}

int sum(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end) {
    // base case, also exit case if it were a loop
    if (beg == end) {
        return 0;
    }

    // get current value 
    int curr = *beg;
    // advance to the next item in the list,
    // add the current value to *result of the resursive function*
    return sum(++beg , end) + curr;
}

int count_items(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end) {
    // base case, also exit case if it were a loop
    if (beg == end) {
        return 0;
    }
    
    constexpr int COUNT = 1;
    
    // get current count (one at a time)
    // and add current value to *result of the resursive function*
    return count_items(++beg, end) + COUNT;   
}

int b_search(std::vector<int>::const_iterator low, std::vector<int>::const_iterator high, int target) {
    // Implementing binary search as a recursive, divide and conquer algoithm.

    // Exit cases
    if (low == high) {
        return -1;
    }

    const auto mid_index = ((high - low) / 2);
    auto mid = low + mid_index;

    if (*mid < target) {
        return b_search(mid+1, high, target);
    } else if ( *mid > target) {
        return b_search(low, mid-1, target);
    } 

    return *mid;
}

int main() {
    // 3! = 6;
    std::cout << "3! -> " << factorial(3) << std::endl;
    // 5! = 125
    std::cout << "5! -> " << factorial(5) << std::endl;
    // 7! = 5040
    std::cout << "7! -> " << factorial(7) << std::endl;

    std::vector<int> iv {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vec {5, 3, 7, 8, 4};

    // Count

    auto bgv = iv.begin();
    auto edv = iv.end();
    int count = 0;
    // exit case
    while (bgv != edv) {
        // get current count (one at a time)
        // and add current value to *what is keeping track of the total count*
        count++;
        // advance to the next item in the list
        bgv++;
    }


    std::cout << std::endl << "First count of items: " << count
              << std::endl;

    std::cout << std::endl << "2nd count of items: " << count_items(iv.begin(), iv.end())
              << std::endl;

    // Sum
    auto beg = vec.begin();
    auto end = vec.end();
    int sums = 0;
    // exit case
    while (beg != end) {
        // get current value
        // AND add the current value to *what is keeping track of the total sum*
        sums += *beg;
        // advance to the next item in the list
        beg++;
    }
    std::cout << "Sum loop: " << sums << std::endl;

    std::cout << "Sum recursion: " << sum(vec.begin(), vec.end()) << std::endl;

    // Binary search
    //std::sort(vec.begin(), vec.end());
    auto found = b_search(iv.begin(), iv.end(), 3);
    std::cout << found << " found!\n";

    return 0;
}


// In a loop, state is preserved by an object declared outside the loop that is changed
// each iteration.

// In resursion, the resursive function itself seems to replace the action of preserving state.
// Rather, it is the call stack that preserves the current state of the function,
// similar to an object declared outside of a loop's scope.