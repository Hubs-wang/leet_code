int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j, sum;
    int *result = malloc(2 * sizeof(int));
    for(i = 0; i < numsSize - 1; i++)
    {
        for(j = i+1; j < numsSize; j++)
        {
            sum = nums[i] + nums[j];
            if(target == sum)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
            continue;   
        }
    }
        free(result);  
        *returnSize = 0;
        return NULL;   
}