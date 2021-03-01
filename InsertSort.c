#include <stdio.h>
//�Զ�����������
void print(int a[], int n ,int i){
    printf("%d:",i);
    for(int j=0; j<6; j++){
        printf("%d",a[j]);
    }
    printf("\n");
}
//ֱ�Ӳ���������
void InsertSort(int a[], int n)
{
    for(int i= 1; i<n; i++){
        if(a[i] < a[i-1]){//���� i ��Ԫ�ش��� i-1 Ԫ����ֱ�Ӳ��룻��֮����Ҫ�ҵ��ʵ��Ĳ���λ�ú��ڲ��롣
            int j= i-1;
            int x = a[i];
            while(j>-1 && x < a[j]){  //����˳����ҷ�ʽ�ҵ������λ�ã��ڲ��ҵ�ͬʱ���������е�Ԫ�ؽ��к��Ʋ�����������Ԫ���ڳ��ռ�
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = x;      //���뵽��ȷλ��
        }
        print(a,n,i);//��ӡÿ�������Ľ��
    }
}

void BInsertSort(int a[],int size){
    int i,j,low = 0,high = 0,mid;
    int temp = 0;
    for (i=1; i<size; i++) {
        low=0;
        high=i-1;
        temp=a[i];
        //�����۰���ҷ��жϲ���λ�ã����ձ��� low ��ʾ����λ��
        while (low<=high) {
            mid=(low+high)/2;
            if (a[mid]>temp) {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        //������в���λ�ú��Ԫ��ͳһ����
        for (j=i; j>low; j--) {
            a[j]=a[j-1];
        }
        a[low]=temp;//����Ԫ��
        print(a, 8, i);
    }

}

void road2_insert(int arr[], int temp[], int n)
{
    int i,first,final,k;
    first = final = 0;//�ֱ��¼temp���������ֵ����Сֵ��λ��
    temp[0] = arr[0];
    for (i = 1; i < n; i ++){
        // ������Ԫ�ر���С��Ԫ��С
        if (arr[i] < temp[first]){
            first = (first - 1 + n) % n;
            temp[first] = arr[i];
        }
        // ������Ԫ�ر����Ԫ�ش�
        else if (arr[i] > temp[final]){
            final = (final + 1 + n) % n;
            temp[final] = arr[i];
        }
        // ����Ԫ�ر���С�󣬱����С
        else {
            k = (final + 1 + n) % n;
            //������ֵ�ȵ�ǰֵСʱ����Ҫ�ƶ���ǰֵ��λ��
            while (temp[((k - 1) + n) % n] > arr[i]) {
                temp[(k + n) % n] =temp[(k - 1 + n) % n];
                k = (k - 1 + n) % n;
            }
            //�����ֵ
            temp[(k + n) % n] = arr[i];
            //��Ϊ���ֵ��λ�øı䣬������Ҫʵʱ����final��λ��
            final = (final + 1 + n) % n;
        }
    }
    // �������¼���Ƶ�ԭ����˳�����
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
