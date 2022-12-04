#include<bits/stdc++.h>
using namespace std;


float cal_mean(int arr[] , int ei){
    float sum =0;
    for(int i=0;i<=ei;i++){
        sum += arr[i];
    }
    return sum/ei+1;
}

int main(){
int data[] = {0,2,1,22 ,2 ,1 ,3 ,5 ,9 ,15 ,8 ,10 ,10 ,11 ,10 ,14 ,20 ,25 ,27 ,58 ,78 ,69 ,94 ,74 ,86 ,73 ,153 ,136 ,120 ,187 ,309 ,424 ,486 ,560 ,579 ,609,
    484,573 ,565 ,813 ,871 ,854 ,758 ,1243 ,1031 ,886 ,1061 ,922 ,1371 ,1580 ,1239 ,1537 ,1292 ,1667 ,1408 ,1835 ,1607 ,1568 ,1902 ,1705 ,1801,2391};

    //average
    float average = 0;
    float sum = 0;
    int n = sizeof(data)/sizeof(data[0]);
    for(int i=0;i<n;i++){
        sum += data[i];
    }
    average = sum / n;
    cout<<"average of the data is : "<<average<<endl;
    cout<<endl;

    //variance
    float variance = 0.0;
    float sum2 = 0;
    for(int i=0;i<n;i++){
        sum2 += (average - data[i])*(average - data[i]);
    }
    variance = sum2/n;
    cout<<"variance of the data is : "<<variance<<endl;
    cout<<endl;

    //std deviation
    float std_deviation;
    std_deviation = pow(variance,0.5);
    cout<<"standard deviation of the data is : "<<std_deviation<<endl;
    cout<<endl;

    vector<int> arr_gradient;

    for(int i=0;i<n-1;i++){
        arr_gradient.push_back(data[i+1] - data[i]);
    }
    cout<<"gradient of the data is as follow: "<<endl;
    for(int i=0;i<arr_gradient.size();i++){
        cout<<arr_gradient[i]<<"  ";
    }
    cout<<endl;
    cout<<endl;

    vector<int> laplacian;
    for(int i=0;i<arr_gradient.size()-1;i++){
        laplacian.push_back(arr_gradient[i+1] - arr_gradient[i]);
    }
    cout<<"laplacian of the data is as follow: "<<endl;
    for(int i=0;i<laplacian.size();i++){
        cout<<laplacian[i]<<"  ";
    }
    cout<<endl;
    cout<<endl;

    vector<int> new_data;
    for(int i=2;i<n-2;i++){
        int temp_sum = 0;
        for(int j=i-2;j<i+2;j++){
            temp_sum += data[j];
        }
        new_data.push_back(temp_sum/5);
    }
    cout<<"data after applying filter is : "<< endl;
    for(int i=0;i<new_data.size();i++){
        cout<<new_data[i]<<"  ";
    }
    cout<<endl;
    cout<<endl;

    float beta = 0.9;
    vector<int> mov_mean;
    mov_mean.push_back(0);
    for(int i=1;i<n;i++){
        float temp = beta*data[i] + (1-beta)*mov_mean[i-1];
        mov_mean.push_back(temp);
    }
    cout<<"data after mov_mean is : "<< endl;
    for(int i=0;i<mov_mean.size();i++){
        cout<<mov_mean[i]<<"  ";
    }
    cout<<endl;
    cout<<endl;

    //mean normalization
    int min_ele = 999999;
    int max_ele = -1;
    for(int i=0;i<n;i++){
        if(min_ele > data[i]){
            min_ele = data[i];
        }
        if(max_ele < data[i]){
            max_ele = data[i];
        }
    }
    float range = (float)max_ele - (float)min_ele;
    vector<float> normalized_arr;
    cout<<endl;
    cout<<"data after normalization is as follows: "<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        float temp = (abs)(data[i] - average)/range;
        normalized_arr.push_back(temp);
        cout<<temp<<"  ";
    }
    cout<<endl;

    //adam optimization
    float alpha = 1;
    float epsilon = 1;
    float val;
    vector<float>adamOpt;
    cout<<endl;
    cout<<"adam optimization of the above data is as follows: "<<endl;
    for(int i =1; i<laplacian.size(); i++)
    {
        val = (data[i] - alpha * arr_gradient[i-1])/(sqrt((laplacian[i]*laplacian[i]) + epsilon));
        adamOpt.push_back(val);
        cout<<val<<" ";
    }
    cout<<endl;

return 0;
}
