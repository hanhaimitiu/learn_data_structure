#include <stdio.h>
//自定义的输出函数
void print(int a[], int n ,int i){
    printf("%d:",i);
    for(int j=0; j<6; j++){
        printf("%d",a[j]);
    }
    printf("\n");
}
//直接插入排序函数
void InsertSort(int a[], int n)
{
    for(int i= 1; i<n; i++){
        if(a[i] < a[i-1]){//若第 i 个元素大于 i-1 元素则直接插入；反之，需要找到适当的插入位置后在插入。
            int j= i-1;
            int x = a[i];
            while(j>-1 && x < a[j]){  //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = x;      //插入到正确位置
        }
        print(a,n,i);//打印每次排序后的结果
    }
}

void BInsertSort(int a[],int size){
    int i,j,low = 0,high = 0,mid;
    int temp = 0;
    for (i=1; i<size; i++) {
        low=0;
        high=i-1;
        temp=a[i];
        //采用折半查找法判断插入位置，最终变量 low 表示插入位置
        while (low<=high) {
            mid=(low+high)/2;
            if (a[mid]>temp) {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        //有序表中插入位置后的元素统一后移
        for (j=i; j>low; j--) {
            a[j]=a[j-1];
        }
        a[low]=temp;//插入元素
        print(a, 8, i);
    }

}

void road2_insert(int arr[], int temp[], int n)
{
    int i,first,final,k;
    first = final = 0;//分别记录temp数组中最大值和最小值的位置
    temp[0] = arr[0];
    for (i = 1; i < n; i ++){
        // 待插入元素比最小的元素小
        if (arr[i] < temp[first]){
            first = (first - 1 + n) % n;
            temp[first] = arr[i];
        }
        // 待插入元素比最大元素大
        else if (arr[i] > temp[final]){
            final = (final + 1 + n) % n;
            temp[final] = arr[i];
        }
        // 插入元素比最小大，比最大小
        else {
            k = (final + 1 + n) % n;
            //当插入值比当前值小时，需要移动当前值的位置
            while (temp[((k - 1) + n) % n] > arr[i]) {
                temp[(k + n) % n] =temp[(k - 1 + n) % n];
                k = (k - 1 + n) % n;
            }
            //插入该值
            temp[(k + n) % n] = arr[i];
            //因为最大值的位置改变，所以需要实时更新final的位置
            final = (final + 1 + n) % n;
        }
    }
    // 将排序记录复制到原来的顺序表里
    for (k = 0; k < n; k ++) {
        arr[k] = temp[(first + k) % n];
    }
}

void Shell_Sort(int arr[], int len){
    int gap, i, j;
        int temp;
        for (gap = len >> 1; gap > 0; gap >>= 1)
                for (i = gap; i < len; i++) {
                        temp = arr[i];
                        for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                                arr[j + gap] = arr[j];
                        arr[j + gap] = temp;
                }
    for(int i=0;i<len;++i)
        printf("%d\t",arr[i]);
}
int main(){
    int a[6] = {2,5,4,6,1,3};
    /*int temp[6];
    road2_insert(a,temp,6);
    for (int i = 0; i < 6; i ++){
        printf("%d ", a[i]);
    }*/
    //BInsertSort(a,6)
    //InsertSort(a,6);
    Shell_Sort(a,6);
    return 0;
}
