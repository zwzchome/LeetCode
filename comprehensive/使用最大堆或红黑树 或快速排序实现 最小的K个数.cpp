//最大堆求最大的k个数
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <priority_quque>
using namespace std;
int main()
{
    
}

//使用堆排序
vector<int> getLeastMaxNumHeap(vector<int>& arr, int k)
{
    priority_quque<int> pq;
    vector<int> res;
    if (k == 0)
        return res;
    //先建堆
    for (int i = 0; i<k; i++)
    {
        pq.push(arr[i]);
    }

    //继续加元素维持之前的最大堆
    for (int i = k; i<arr.size(); i++)
    {
        if (arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //将堆中的元素出来，就可以返回维持的最大的k个数
    for(int j = 0; j<k; j++)
    {
        res.push(pq.top());
        pq.pop();
    }

    return res;
}

void getLeastMaxNumFastSort(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> res;
    //使用快速排序，将arr中的k个数进行返回
    if (n < k || k==0 || n==0)
    {
        return res;
    }

    if (arr.size() == k)
        return arr;
    
    int index = fastSort(arr,0,arr.size());//找到第index个数，将arr数组左右两边进行分开
    while (index != k-1)
    {
        if (index < k-1)
        {
            left = index+1;
        }

        if (index > k-1)
        {
            right = index-1;
        }
        index = fastSort(arr,left,right);
    }
    return vector<int>(arr.begin(),arr.begin()+k);
}

int fastSort(vector<int> &arr,int left,int right)
{
    int sentry = arr[left];
    while (left < right)
    {
        while (left < right && arr[right] >= sentry)//要注意时刻保持left<right 的这个条件
            right--;
        arr[left] = arr[right];

        while (left < right && arr[left] <= sentry)
            left++;
        arr[right] = arr[left];
    }

    arr[left] = sentry;
    return left;
}
