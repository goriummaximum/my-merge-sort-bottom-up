# An implementation of merge sort from bottom-up

## What?
An implementation of merge sort from bottom-up iteratively, using C++. Aiming to reduce the overhead of recursive call and divide stage of top-down approach.

## When?
May, 2022. In my freetime solving Leetcode, met a problem which need sorting array.  

## Where?
My house, in front of my computer.  

## Why?
To practice algorithm, C++ programming.  
Curious about bottom-up approach of merge sort.  

## How?
C++ programming, using standard STL library.  

## Algorithm explaination
For every ```k = k * 2 (k >= 2)``` representing the ideal length of subarrays that need to be merge, for every ```i```, we compute ```start```, ```mid```, ```end``` as formula in the code then merge 2 subarrays [start, mid] and [mid + 1, end]. Note that the 2 subarrays are already sorted from previous ```k```, so we solve the problem of merging 2 sorted array normally. However, watch out the 2 edge cases: there is only 1 subarray need to be merged at the end of the original array resulting in mid >= array size, or there are 2 subarrays needed to be merged but the length of last latter subarray is smaller than ideal length.  

Proof: imagine we have 2 subarrays [A...B] and [C..D] are already sorted, do the merging of 2 sorted arrays resulting in [A, D] is sorted, therfore merging with another array [E...F] sorted, we have [A...F] sorted. But how do we know the smallest subarray is sorted? Smallest subarray contain only 1 elements [A], [B], [C], [D],..., therefore it already sorted, so when we merge [A], [B], we get [A, B] sorted, and so on.

Time: ```O(nlogn)```, space: ```O(n)``` because there is additional vector created when merging.  

## An example
<img src="https://github.com/goriummaximum/my-merge-sort-bottom-up/blob/main/merge-sort-example.png" width="1000">  
