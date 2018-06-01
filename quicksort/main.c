#include<stdio.h>
#include<stdlib.h>
#define ARR_LEN 10
#define PT(arr,len) for(int i=0;i<len;i++){\
    printf("%d,",arr[i]); \
}


//子序列 前向查找
int compareFromEnd(int *p,int base,int start,int end)
{
    while(start < end){
        if(p[end] < p[base]){
            int temp = p[end];
            p[end] = p[base];
            p[base] = temp;
            base = end;
            break;
        }
        end--;
    } 
    return base;
}


//子序列 后向查找
int compareFromStart(int *p,int base,int start,int end)
{
    while(start < end){
        if(p[start] > p[base]){
            int temp = p[start];
            p[start] = p[base];
            p[base] = temp;
            base = start;
            break;
        }
        start++;
    }
    return base;
}


int arr[ARR_LEN] = {10,15,8,30,21,9,7,6,3,4};


//使用 首元素分割数组 返回分割中间值
int split_arr(int *p,int start_split,int end_split)
{
    int base = start_split;
    while(start_split < end_split){
        base = compareFromEnd(p,base,start_split,end_split);
        end_split = base;
        printf("\n----------前向查找------------\n");
        PT(arr,ARR_LEN);
        base = compareFromStart(p,base,start_split,end_split);
        start_split = base;
        printf("\n----------后向查找------------\n");
        PT(arr,ARR_LEN);
    }
    return base;
}

void quicksort(int start,int end,int left)
{
    printf("\n------start:%d-------end:%d------left:%d\n",start,end,left);
    int middle = split_arr(arr,start,end);
    //分割的中间值不需要再参与排序 只需分别排其左边和右边的子序列
    if(start < middle-1){
        quicksort(start,middle-1,1);
    }
    if(middle+1 < end){
        quicksort(middle+1,end,0);
    }
}

void
main()
{
    printf("----------原序列------------\n");
    PT(arr,ARR_LEN);
    
    int start = 0,end = ARR_LEN - 1;
    quicksort(start,end,1);
}
