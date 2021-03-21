#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    int ramdom_select(int l, int r) {
        return rand() % (r - l + 1) + l;
    }

    int partition(vector<int>& arr, int l, int r) {
        int num = l-1;
        int pivot = arr[r];
        for (int i = l; i < r; i++) {
            if (arr[i] <= pivot) {
                num++;
                swap(arr[num], arr[i]);
            }
        }
        num++;
        swap(arr[num], arr[r]);
        return num;
    }

    void quick_move(vector<int>& arr, int l, int r, int k) {
        if (l > r) return;
        int pivot_pos = ramdom_select(l, r);
        swap(arr[pivot_pos], arr[r]);
        pivot_pos = partition(arr, l, r);
        if (pivot_pos == k) {
            return;
        }
        if (pivot_pos < k) {
            quick_move(arr, pivot_pos+1, r, k);
            return;
        }
        if (pivot_pos > k) {
            quick_move(arr, l, pivot_pos-1, k);
            return;
        }
    }

    vector<int> smallestK(vector<int>& arr, int k) {
        quick_move(arr, 0, arr.size()-1, k-1);
        return vector<int>(arr.begin(), arr.begin()+k);
    }
};