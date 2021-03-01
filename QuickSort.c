#include <stdio.h>
#include <stdlib.h>


int Partition(int arrays[],int low,int high){

    int flag=arrays[low];
    while(low<high){
        while(low<high && arrays[high]>=flag){
            --high;
        }
        arrays[low] = arrays[high];

        while(low<high && arrays[low]<=flag){
            ++low;
        }

        arrays[high] = arrays[low];

    }
    arrays[low]=flag;
    return low;
    }


void QuickSort(int arrays[],int low,int high){
if(low<high){
    int flag=Partition(arrays,low,high);
    QuickSort(arrays,low,flag-1);
    QuickSort(arrays,flag+1,high);

}
}



int main()
{
    int arrays[]={49,38,65,97,76,13,27,49};

    for(int i=0;i<8;++i)
        printf("%d\t",arrays[i]);
    QuickSort(arrays,0,7);
    printf("\n");
    for(int i=0;i<8;++i)
        printf("%d\t",arrays[i]);

    return 0;
}
