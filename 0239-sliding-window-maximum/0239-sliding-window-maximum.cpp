/*
LeetCode 239 - Sliding Window Maximum

Problem:
Given an array nums and an integer k, return the maximum element
for every sliding window of size k.

Example:
nums = [1,3,-1,-3,5,3,6,7], k = 3

Windows:
[1,3,-1] -> 3
[3,-1,-3] -> 3
[-1,-3,5] -> 5
[-3,5,3] -> 5
[5,3,6] -> 6
[3,6,7] -> 7

Output:
[3,3,5,5,6,7]

---------------------------------------------------
OPTIMAL APPROACH: MONOTONIC DEQUE
---------------------------------------------------

Idea:
1. Use a deque to store indices of useful elements.
2. The deque will always store indices in decreasing order
   of their values.
3. Front of deque always contains the index of the maximum
   element of the current window.

Why store indices instead of values?
Because we need to know whether an element goes out
of the current window.

Time Complexity: O(n)
Each element is inserted and removed at most once.

Space Complexity: O(k)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // Stores answer
        vector<int> result;

        // Deque will store indices
        deque<int> dq;

        // Traverse all elements
        for (int i = 0; i < nums.size(); i++) {

            /*
            STEP 1:
            Remove indices that are outside
            the current window.

            Current window range:
            [i-k+1 ... i]

            If front index <= i-k,
            it is no longer part of window.
            */
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            /*
            STEP 2:
            Maintain decreasing order in deque.

            Remove all smaller elements from back
            because they can never become maximum
            while current larger element exists.
            */
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            /*
            STEP 3:
            Insert current index.

            After insertion, deque remains in
            decreasing order of values.
            */
            dq.push_back(i);

            /*
            STEP 4:
            Start recording answers once the
            first complete window is formed.

            First complete window appears when
            i >= k - 1.
            */
            if (i >= k - 1) {

                /*
                Front of deque always contains
                index of maximum element
                in current window.
                */
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};