// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : Nick Jose
// Date   : 2016-02-16

/********************************************************************************** 
* 
*
*Follow up for "Remove Duplicates":
*What if duplicates are allowed at most twice?
*
*For example,
*Given sorted array nums = [1,1,1,2,2,3],
*
*Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
*It doesn't matter what you leave beyond the new length. 
*
**********************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();

        int pos = 2;
        for( int i = 2; i<nums.size(); ++i){
            if(nums[i] != nums[pos-2]){
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};

