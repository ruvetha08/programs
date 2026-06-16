
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int hashSize = 20011; 
    int* hashKey = (int*)calloc(hashSize, sizeof(int));
    int* hashVal = (int*)calloc(hashSize, sizeof(int));
    int* hashUsed = (int*)calloc(hashSize, sizeof(int));
    
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int compHash = complement % hashSize;
        if (compHash < 0) compHash += hashSize; 

        while (hashUsed[compHash]) {
            if (hashKey[compHash] == complement) {
                result[0] = hashVal[compHash];
                result[1] = i;
                free(hashKey); free(hashVal); free(hashUsed);
                return result;
            }
            compHash = (compHash + 1) % hashSize;
        }

        int currHash = nums[i] % hashSize;
        if (currHash < 0) currHash += hashSize;

        while (hashUsed[currHash]) {
            currHash = (currHash + 1) % hashSize;
        }
        hashKey[currHash] = nums[i];
        hashVal[currHash] = i;
        hashUsed[currHash] = 1;
    }

    free(hashKey); free(hashVal); free(hashUsed);
    *returnSize = 0;
    return NULL;
}
