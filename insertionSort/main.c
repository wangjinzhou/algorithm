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
    
    int blank_pos;
    for(int i =1;i< ARR_LEN;i++){
        blank_pos = i;
        int insert_pos = i;
        //将前面的子序列视为已排序好的
        for(int j = 0;j < i;j++){
            if(arr[blank_pos] < arr[j]){        //第一次找到即可终止此次查询，因为前面的已排序好
                insert_pos = j;
                break;
            }
        }
        
        if(blank_pos != insert_pos){    //找到插入的位置  将插入位置之后 当前要插入元素前的元素后移
            int need_insert_val = arr[blank_pos];
            for(int k = blank_pos-1;k>= insert_pos;k--){
                arr[k+1] = arr[k];
            }
            arr[insert_pos] = need_insert_val;
        }

        printf("\n----------- i:%d -----------\n",i);
        PT(arr,ARR_LEN);
    }
}
