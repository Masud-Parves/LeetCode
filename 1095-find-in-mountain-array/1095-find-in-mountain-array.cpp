/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int binarySearch(MountainArray &mountainArr, int target, int start, int end, bool increasing){
        while(start<=end){
            int mid = start + (end - start)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            } else if(mountainArr.get(mid) < target) {
                if(increasing){
                    start = mid+1;
                } else {
                    end = mid -1;
                }
            } else {
                if(increasing){
                    end = mid -1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int retIdx = -1;
        
        int L = 0, R = mountainArr.length()-1;
        while(L<R){
            int mid = L + (R - L)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                L = mid+1;
            } else {
                R = mid;
            }
        }
        //cout << L << endl;
        retIdx = binarySearch(mountainArr, target, 0, L, true);
        //cout << retIdx << endl;
        if(retIdx != -1) return retIdx;
        retIdx = binarySearch(mountainArr, target, L, mountainArr.length()-1, false);
        //cout << retIdx << endl;
        return retIdx;
    }
};