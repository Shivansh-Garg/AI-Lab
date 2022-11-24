#include<bits/stdc++.h>
using namespace std;

void printa(vector<float> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

float mean(vector<float> arr){
    float sum = 0;
    int size_arr = arr.size();
    float mean_cal = -1;
    for(int i=0;i<size_arr;i++){
        sum += arr[i];
    }
    mean_cal = sum/size_arr;
    return mean_cal;
}

int main(){
    srand(time(0));
    vector<float> arr;
    int srange, erange;
    cout<<"Enter the starting range of numbers:"<<endl;
    cin>> srange;
    cout<<"Enter the ending range of numbers :"<<endl;
    cin>> erange;
    for(int i=0;i<100;i++){
        int m = (rand() % (erange-srange+1)) +srange;
        arr.push_back(m);
    }

    vector<float> g1,g2,g3,g4;

    /*for(int i=0;i<100;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/

    int arr2[4];
    for(int i=0;i<4;i++){
        cout<<"Enter seed "<<i+1<<endl;
        cin>>arr2[i];
    }

    g1.push_back(arr2[0]);
    g2.push_back(arr2[1]);
    g3.push_back(arr2[2]);
    g4.push_back(arr2[3]);

    for(int i=0;i<50;i++){
        vector<float> a1,a2,a3,a4;
        a1.clear();
        a2.clear();
        a3.clear();
        a4.clear();

        a1.push_back(g1[i]);
        a2.push_back(g2[i]);
        a3.push_back(g3[i]);
        a4.push_back(g4[i]);

        int min_so_far = INT_MAX;
        int index = -1;

        for(int j=0;j<100;j++){
            if(abs(arr[j] - a1[0]) < min_so_far){
                index = 1;
                min_so_far = abs(arr[j] - a1[0]);
            }
            if(abs(arr[j] - a2[0]) < min_so_far){
                index = 2;
                min_so_far = abs(arr[j] - a2[0]);
            }
            if(abs(arr[j] - a3[0]) < min_so_far){
                index = 3;
                min_so_far = abs(arr[j] - a3[0]);
            }
            if(abs(arr[j] - a4[0]) < min_so_far){
                index = 4;
                min_so_far = abs(arr[j] - a4[0]);
            }
            if(index == 1){
                a1.push_back(arr[j]);
                a1[0] = mean(a1);
            }
            if(index == 2){
                a2.push_back(arr[j]);
                a2[0] = mean(a2);
            }
            if(index == 3){
                a3.push_back(arr[j]);
                a3[0] = mean(a3);
            }
            if(index == 4){
                a4.push_back(arr[j]);
                a4[0] = mean(a4);
            }
            min_so_far = INT_MAX;
        }
        if( i == 49){
                cout<<endl;
                cout<<"A1 :"<<endl;
                printa(a1);
                cout<<endl;
                cout<<"A2 :"<<endl;
                printa(a2);
                cout<<endl;
                cout<<"A3 :"<<endl;
                printa(a3);
                cout<<endl;
                cout<<"A4 :"<<endl;
                printa(a4);
                cout<<endl;

            }
        g1.push_back(a1[0]);
        g2.push_back(a2[0]);
        g3.push_back(a3[0]);
        g4.push_back(a4[0]);

    }
    cout<<"G1 :"<<endl;
    for(int i=0;i<g1.size();i++){
        cout<<g1[i]<<" ";
    }
    cout<<endl;

    cout<<"G2 :"<<endl;
    for(int i=0;i<g2.size();i++){
        cout<<g2[i]<<" ";
    }
    cout<<endl;

    cout<<"G3 :"<<endl;
    for(int i=0;i<g3.size();i++){
        cout<<g3[i]<<" ";
    }
    cout<<endl;

    cout<<"G4 :"<<endl;
    for(int i=0;i<g4.size();i++){
        cout<<g4[i]<<" ";
    }
    cout<<endl;
    return 0;
}
