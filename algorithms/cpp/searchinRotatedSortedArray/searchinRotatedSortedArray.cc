// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author : Nick Jose
// Date   : 2016-02-16

/********************************************************************************** 
* 
*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*
*(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*
*You are given a target value to search. If found in the array return its index, otherwise return -1.
*
*You may assume no duplicate exists in the array.
*
**********************************************************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;

        int start = 0, end = nums.size()-1;
        while(start <= end){
            const int mid = (start + end)/2;
            if(nums[mid]==target){
                return mid;
            }

            //针对mid和start的相对位置进行讨论, 也可以针对mid和end的相对位置进行讨论
            //mid小于等于start
            if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target < nums[mid]){
                //假如target在start和mid的区间内,因为这是个严格递增的区间, 所以容易判断
                    end = mid - 1;
                }else{
                //否则target就在mid和end的区间内
                    start = mid + 1; 
                }
            }else{
                if(nums[mid] < target && target <= nums[end]){
                //假如target在mid和end的区间内，因为这个也是严格递增区间，所以容易判断
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return -1; 
    }
};
