//
//  main.cpp
//  Insertion sort on small arrays in merge sort
//
//  Created by 张越 on 2018/3/5.
//  Copyright © 2018年 Yue Zhang. All rights reserved.
//

#include<iostream>
#include <cmath>
#include <time.h>

using namespace std;

void merge(int *a,int p,int q,int r)
{
    int Ln=q-p+1;
    int Rn=r-q;
    
    int *La=new int[Ln+1];
    int *Ra=new int[Rn+1];
    for(int i=0;i<Ln;++i){
        La[i]=a[i+p];
    }
    La[Ln]=numeric_limits<int>::max();
    
    for(int j=0;j<Rn;++j){
        Ra[j]=a[q+j+1];
    }
    Ra[Rn]=numeric_limits<int>::max();
    
    int k=0,m=0;
    
    for(int n=p;n<=r;++n){
        if(La[k]<Ra[m]){
            a[n]=La[k];
            ++k;
        }else{
            a[n]=Ra[m];
            m++;
        }
    }
    delete [] La;
    delete [] Ra;
}

void insert_sort(int *a ,int n)
{
    int key,j;
    for(int i=1;i<n;++i){
        key=a[i];
        j=i-1;
        while(j>=0 && key<a[j]){
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=key;
    }
}

void merge_insertion_sort(int *a,int p,int r,int k)
{
    if(p<r){
        if((r-p+1)>k){
            int mid=(p+r)>>1;
            merge_insertion_sort(a,p,mid,k);
            merge_insertion_sort(a,mid+1,r,k);
            merge(a,p,mid,r);
        }else{
            insert_sort(a+p,r-p+1);
        }
    }
}

void merge_sort(int *a,int p,int r)
{
    if(p<r){
            int mid=(p+r)>>1;
            merge_sort(a,p,mid);
            merge_sort(a,mid+1,r);
            merge(a,p,mid,r);
    }
}

int main()
{

    for(int i = 0;i<=30;i++)
    {
        int n;
        n=pow(10, 7);
        int * a=new int[n];
//        clock_t start0,finish0;
//        start0 = clock();
            for(int j=0;j<n;j++){          //random permutation array；
                a[j]=rand()%n;
            }
//        finish0 = clock();
//        long time0 = 1000 * (finish0 - start0)/CLOCKS_PER_SEC;
//        cout<<time0;
//                    for(int j=0;j<n;j++){        //already sorted Array；
//                        a[j]=j;
//                    }
//        for(int j=n-1;j>=0;j--){     //reversely sorted Array；
//            a[j]=j;
//        }

        
        
        //int k = pow(2, i);
        clock_t start,finish; //Program counter;
        start = clock();      //Start time;
        merge_insertion_sort(a,0,n-1,i);
        //insert_sort(a, n);
        //merge_sort(a, 0, n-1);
        finish = clock();     //termination
        long time = 1000*(finish - start)/CLOCKS_PER_SEC;
        cout<<"time: "<<time<<"ms   "<<"when k = "<<i<<endl;
        delete [] a;
    }


}
