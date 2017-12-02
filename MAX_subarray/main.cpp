//2017年12月3日00:29:02
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

//动态规划解决最大子数组问题
int dp_max_subarray(int *arr, int len){
    int currSum = 0;
    int finalSum = 0;
    int tmp = 0;
    int Start = 0;
    int End = 0;

    for(int i=0; i<len; i++){
        if(currSum < 0){
            currSum = 0;
            finalSum = 0;
            tmp = i;
        }

        else
            currSum += arr[i];
        if(currSum > finalSum){
            finalSum = currSum;
            Start = tmp;
            End = i;
        }
    }
    cout << Start << "->" << End << endl;
    return finalSum;
}

//分治解决最大子数组问题
int max_middle_subarray(int *arr, int low, int mid, int high) {
    int tmp_sum = 0;

    int left_sum = arr[mid];   //计算左侧最大值
    for(int i = mid; i >= low; i--){
        tmp_sum += arr[i];
        if(tmp_sum > left_sum)
            left_sum = tmp_sum;
    }

    int right_sum = arr[mid+1];
    for(int i = mid + 1; i<=high; i++){
        tmp_sum = arr[i];
        if(tmp_sum > right_sum)
            right_sum = tmp_sum;
    }

    return (left_sum + right_sum);
}

int max_side_subarray(int *arr, int low, int high) {
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int left_max = max_side_subarray(arr, low, mid);
    int right_max = max_side_subarray(arr, mid + 1, high);
    int cross_max = max_middle_subarray(arr, low, mid, high);

    if (left_max > right_max && left_max > cross_max)
        return left_max;
    else if (right_max > left_max && right_max > cross_max)
        return right_max;
    else
        return cross_max;
}


//最大子数组问题求解
int main(){
    int sample[7] = {-3,-2,14,20,-10,20,-20};
    double t_start,t_end;
    t_start = clock();
    //cout << find_max_subarray(sample,0,6) << endl;
    cout << dp_max_subarray(sample, sizeof(sample)/sizeof(sample[0])) << endl;
    t_end = clock();
    cout << ((double)(t_end - t_start)) / CLOCKS_PER_SEC << endl;
}

