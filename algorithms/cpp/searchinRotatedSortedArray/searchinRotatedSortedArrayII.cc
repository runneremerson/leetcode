// Source : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author : Nick Jose
// Date   : 2016-02-17

/********************************************************************************** 
* 
*
*Follow up for "Search in Rotated Sorted Array":
*What if duplicates are allowed?
*
*Would this affect the run-time complexity? How and why?
*
*Write a function to determine if a given target is in the array.
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
                return true;
            }

            //针对mid和start的相对位置进行讨论, 也可以针对mid和end的相对位置进行讨论
            //mid小于等于start
            if(nums[start] < nums[mid]){
                if(nums[start] <= target && target < nums[mid]){
                //假如target在start和mid的区间内,因为这是个严格递增的区间, 所以容易判断
                    end = mid - 1;
                }else{
                //否则target就在mid和end的区间内
                    start = mid + 1; 
                }
            }else if(nums[start] > nums[mid]){
                if(nums[mid] < target && target <= nums[end]){
                //假如target在mid和end的区间内，因为这个也是严格递增区间，所以容易判断
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }else{
                //极端情况下[2,2,2,2,2,2,1], target == 1的时候，需要比较n次才能找到target，所以时间复杂度是O(n)
                start += 1;
            } 
        }
        return false; 
    }
};
