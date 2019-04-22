// In this program, we want to find the nonempty, contiguous subarray of an array a whose values
// have the largest sum. We call this contigous subarray the maximum subarray.

//This solution uses Divide and Conquer 

/*
 * Divide-and-conquer suggests that we divide
 * the subarray into two subarrays of as equal size as possible. 
 * That is, we find the midpoint, say mid, of the subarray, and consider the subarrays A [low : : mid]
 *  and [mid+1 : : high]
 * of A[low : : high] must lie in exactly one of the following places:
 *  entirely in the subarray [low : : mid], so that low <= i <= j <=mid,    
 *  entirely in the subarray [mid + 1 : : high] so that mid < i < j <= high, or
 *  crossing the midpoint, so that low <= i <= mid < j <=high.
 * 
 */
 
#include <stdio.h>
#include <limits.h>

struct retValue
{
    int left;
    int right;
    int sum
};

typedef struct retValue retTuple;

retTuple findMaxCrossingSubArray(int arr[], int low, int mid, int high)
{
    int leftSum, rightSum;
    leftSum = INT_MIN;
    int sum = 0;
    int i , j;
    retTuple ret = {0, 0, 0};
    
    for(i = mid; i >= low; i--)
    {
        sum = sum + arr[i];
        if(sum > leftSum)
        {
            leftSum = sum;
            ret.left = i;            
        }
    }
    
    rightSum = INT_MIN;
    sum = 0;
    for(j = mid+1; j <= high;  j++)
    {
        sum = sum + arr[j];
        if(sum > rightSum)
        {
            rightSum = sum;
            ret.right = j;
        }
    }
    ret.sum = leftSum + rightSum;
    return ret;
}

retTuple findMaxSubArray(int arr[], int low, int high)
{
    int mid;
    retTuple retVal = {0, 0, 0};
    retTuple retValLeft;
    retTuple retValRight;
    retTuple retValCrossing;
    
    if(high == low)
    {
        retVal.left = low;
        retVal.right = high;
        retVal.sum = arr[low];
        return retVal;
    }
    else
    {
        mid = (low+high)/2;
        retValLeft = findMaxSubArray(arr, low, mid);
        retValRight = findMaxSubArray(arr, mid+1, high);
        retValCrossing = findMaxCrossingSubArray(arr, low, mid, high);
        
        if((retValLeft.sum >= retValRight.sum) &&(retValLeft.sum >= retValCrossing.sum))
            return retValLeft;
        else if((retValRight.sum >= retValLeft.sum) &&(retValRight.sum >= retValCrossing.sum))
            return retValRight;
        else
            return retValCrossing;
    }
    //We dont reach here
    printf("We are not supposed to reach here. Alert !!!\n");
    return retVal;
}
int main(int argc, char **argv)
{
    int arrA[20] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int arrB[20] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int arrSize = 16;
    int low, mid, high;
    retTuple ret;
  
    low = 0;
    mid = arrSize/2;
    high = arrSize;
    printf("Actual array low is %d, mid is %d and high is %d\n",low, mid, high);
    ret = findMaxCrossingSubArray(arrA, low, mid, high);
	printf("MaxCrossingSubArray left index is %d, right Index is  %d and Max sum is %d\n", ret.left, ret.right, ret.sum);
    
    ret = findMaxSubArray(arrB, low, high);
	printf("MaxSubArray left index is %d, right Index is  %d and Max sum is %d\n", ret.left, ret.right, ret.sum);
    return 0;
}
