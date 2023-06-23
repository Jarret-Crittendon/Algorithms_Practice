# Algorithms_Practice
Practicing algorithms for my own understanding

Recursion -  In a loop, state is preserved by an object declared outside the loop that is changed each iteration. 
In resursion, the resursive function itself seems to replace the action of preserving state.
Rather, it is the call stack that preserves the current state of the function, similar to an object declared outside of a loop's scope.

Quicksort - Determining a pivot value that is used to compare to other values in the array. Create two subarrays to hold those less-than and greater-than values. Perform quicksort recursively on those subarrays.  After, combine the values (lesser subarray + pivot + greater subarray). In my C implementation, I used dynamically created subarrays. In C++, I just used vectors. I created a variable to track the number of values equal to the pivot, then added the pivot to the sorted array based on that tracker.  Without that, an error occurs if there are other values equal to the pivot, or more pivot values are added than desired.

Idolreach - Practice of Djikstra's algorithm using hash tables. One hash table to map the entire graph, the second to map the node cost from the starting node, and the third to track the parent of each node. I used the following to help me with the algorithm:
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
