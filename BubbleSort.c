#include <stdio.h>
#include <stdlib.h>


void func2(){
int a[]={7,1,12,2,85,-5,5,9,11};
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8-i;j++)
        {   int temp;
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<9;++i){
        printf("%d\t",a[i]);
    }}

void func3(){
    int a[]={7,1,12,2,85,-5,5,9,11};
    for(int i=0;i<8;++i)
    {
          int temp;
        if(a[i]>a[i+1]){
            temp = a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            }

    }
    for(int i=0;i<9;++i){
        printf("%d\t",a[i]);
    }
}
int main()
{
    //func1();
    //func2();
    func2());

    return 0;
}
