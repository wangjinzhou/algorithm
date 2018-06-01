#include<stdio.h>
#include<stdlib.h>
#define ARR_LEN 10
#define PT(arr,len) for(int i=0;i<len;i++){\
      printf("%d,",arr[i]);                 \
}

void
main()
{
    int arr[ARR_LEN] = {10,9,12,15,18,2,7,9,31,20};
    printf("------------原数组------------------\n");
    PT(arr,ARR_LEN);
    int remain_start;
    for(int i = 0;i<ARR_LEN -1;i++){
        remain_start = i;
        int max = arr[remain_start],max_index = remain_start;
        for(int j = i+1;j < ARR_LEN;j++){
            if(max < arr[j]){
                max = arr[j];
                max_index = j;
            }
        }

        if(remain_start != max_index){
            arr[max_index] = arr[remain_start];
            arr[remain_start] = max;
        }
        printf("\n---------i:%d - ----------\n",i);
        PT(arr,ARR_LEN);
    }
}
