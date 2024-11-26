#include<stdio.h>
#include<stdlib.h>
int a[50],k=-1;
void swap(int l,int b) {
    int temp=a[l];
    a[l]=a[b];
    a[b]=temp;
}
void insert(int c,int root) {
    if(a[c]>a[root])
        swap(c,root);
    if(root>0)
        insert(root,(root-1)/2);
}
void delete(int l,int root) {
    if(a[l]>a[root])
        swap(l,root);
    if(a[l*2+1]!=0)
        delete(l*2+1,l);
    if(a[l*2+2]!=0)
        delete(l*2+2,l);
}
void main() {
    int op,n;
    while(1){
        printf("1.Insert,2.delete,3.Traverse,4.exit");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("Enter an element to insert:");
                    scanf("%d",&n);
                    a[++k]=n;
                    insert(k,(k+1)/2);
                    break;
            case 2:a[0] =a[k];
                    k--;
                    delete(0,0);
                    printf("Deleted");
                    break;
            case 3:if(k==-1)
                    printf("Heap is empty");
                    else
                    for(int j=0;j<k;j++)
                    printf("%d",a[j]);
                    break;
            case 4:exit(0);
            
        }
    }
}
