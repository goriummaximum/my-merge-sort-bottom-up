#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int start, int mid, int end) {
    //merge 2 parts: [start, mid], [mid + 1, end]
    vector<int> buf;
    int idx1 = start;
    int idx2 = mid + 1;

    while (idx1 <= mid && idx2 <= end) {
        if (arr[idx1] <= arr[idx2]) {
            buf.push_back(arr[idx1]);
            idx1++;
        }

        else {
            buf.push_back(arr[idx2]);
            idx2++;
        }
    }

    while (idx1 <= mid) {
        buf.push_back(arr[idx1]);
        idx1++;
    }

    while (idx2 <= end) {
        buf.push_back(arr[idx2]);
        idx2++;
    }

    for (int i = 0; i < buf.size(); i++) {
        arr[start + i] = buf[i];
    }
}

void merge_sort_bottom_up(vector<int> &arr) {
    for (int k = 2; k / 2 < arr.size(); k = k * 2) {
        for (int i = 0; i * k < arr.size(); i++) {
            int start = i * k;
            int end = i * k + k - 1; //ideal end used to compute mid
            int mid = (start + end) / 2;
            if (mid >= arr.size()) continue; //mid over arr size, so there is no need to sort anymore, continue
            end = (end < arr.size()) ? end : arr.size() - 1; //real end
            merge(arr, start, mid, end); //merge 2 halves
        }
    }
}

void print_arr(vector<int> &arr) {
    for (int &ele : arr) {
        cout << ele << "  ";
    }
    cout << endl;
}


int main() {
    vector<int> test = {38,27,43,3,9,82,10};
    
    merge_sort_bottom_up(test);
    print_arr(test);

    return 0;
}