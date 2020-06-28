#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int index1 = m - 1, index2 = n - 1;
    int indexMerge = m + n - 1;
    int a,b,cout;
    while (index1 >= 0 || index2 >= 0) {
        printf("index1:%d\n",index1);
        if (index1 < 0) {
            printf("nums1[%d]=%d\n",indexMerge,nums1[indexMerge]);
            printf("nums2[%d]=%d\n",index2,nums1[index2]);
            nums1[indexMerge--] = nums2[index2--];
        } else if (index2 < 0) {
            printf("index2 < 0 \n");
            printf("nums1[%d]=%d\n",indexMerge,nums1[indexMerge]);
            printf("nums2[%d]=%d\n",index1,nums1[index1]);
            nums1[indexMerge--] = nums1[index1--];
        } else if (nums1[index1] > nums2[index2]) {
            nums1[indexMerge--] = nums1[index1--];
        } else {
            nums1[indexMerge--] = nums2[index2--];
        }
        printf("----------------%d-----------------\n",cout);
        cout++;
        for(a=0;a<nums1Size;a++)
            printf("%d ",nums1[a]);
        puts("");
        
        for(b=0;b<nums2Size;b++)
            printf("%d ",nums2[b]);
        puts("");
    
    }
}


int main()
{
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2,5,6};

    merge(nums1,6,3,nums2,3,3);
    
    return 0;
}
