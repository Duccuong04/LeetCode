/*

Pseudocode:
// Input: Given an array of integers and a target value.
1. Initialize an empty hash table to store complement values.
 
// What DSA/Algorithm to use: Hash Table.
2. Loop over each element in the array.
    a. Calculate the complement value by subtracting the current element from the target.
    b. Check if the complement value exists in the hash table.
        i. If it exists, return the indices of the current element and its complement from the hash table.
        ii. If it doesn't exist, insert the current element into the hash table.
 
// Output: Return the indices of the two elements that sum up to the target.
3. Return an empty array (if no solution is found).

===================================================================================////////

Expanded pseudocode:
// Input: Given an array of integers and a target value.

// Step 1: Initialize an empty hash table to store complement values.
Create an empty hash table.

// What DSA/Algorithm to use: Hash Table.

// Step 2: Loop over each element in the array.
For each element at index i in the array:
    // Step 2a: Calculate the complement value by subtracting the current element from the target.
    Calculate the complement value as (target - nums[i]).

    // Step 2b: Check if the complement value exists in the hash table.
                If the complement value exists as a key in the hash table:
        // Step 2bi: If it exists, return the indices of the current element and its complement from the hash table.
        Return an array containing the indices stored in the hash table for the complement value and the current element.

        // Step 2bii: If it doesn't exist, insert the current element into the hash table.
    Insert the current element into the hash table with its index as the value.

// Output: Return the indices of the two elements that sum up to the target.

// Step 3: Return an empty array (if no solution is found).
Return an empty array since no solution is found.

===================================================================================////////
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Step 1: Input - Given an array of integers and a target value.
        unordered_map<int, int> hashTable;
 
        // What DSA/Algorithm to use: Hash Table.
        // key: value(nums[i]), value: indicator (i)
        
        // Step 2: Loop over each element in the array.
        for (int i = 0; i < nums.size(); ++i) {
            // Step 2a: Calculate the complement value by subtracting the current element from the target.
            int complement = target - nums[i];
 
            // Step 2b: Check if the complement value exists in the hash table.
            if (hashTable.count(complement)){
                // Step 2bi: If it exists, return the indices of the current element and its complement from the hash table.
                return {hashTable[complement], i};
            }
 
            // Step 2bii: If it doesn't exist, insert the current element into the hash table.
            hashTable[nums[i]] = i;
        }
 
        // Output: Return the indices of the two elements that sum up to the target.
 
        // Step 3: Return an empty array (if no solution is found).
        return {};
    }
};