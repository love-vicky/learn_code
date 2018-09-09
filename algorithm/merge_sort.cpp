#include <iostream>

using namespace std;

int a[10] = {23,1,2,32,43,5,6,45,90,10}; 
int tmp[10] = {0};
void merge(int *a, int l, int mid, int r, int *tmp) {
    int i = l;
    int k = l;
    int j = mid + 1;
    cout << "merger: " << l << "," << mid << "," << r << endl;
    for (int h = 0; h < 10; h++) {
        cout << a[h];
        if (h < 9) {
            cout << ",";
        }
    }
    cout << endl;
    cout << "merger: i=" << i << " k=" << k << " j=" << j << endl;
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            tmp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        tmp[k++] = a[i++];
    }

    while (j <= r) {
        tmp[k++] = a[j++];
    }

    for (int idx = 0; idx < 10; idx++) {
        cout << tmp[idx];
        if (idx < 9) {
            cout << ",";
        }
    }

    for (int u = l; u < r; u++) {
        a[u] = tmp[u];
    }
    cout << endl;
}

void merge_sort(int *a, int l, int r, int *tmp) {
    
    int mid = 0;

    if (l < r) {
        mid = (l + r) / 2; 
        merge_sort(a, l, mid, tmp);
        merge_sort(a, mid + 1, r, tmp);
        merge(a, l, mid, r, tmp);
    }
}
int main(int argc, char const *argv[])
{
    merge_sort(a, 1, 10, tmp);
    cout << "[" ;
    for (int o = 0; o < 10; o++) {
        cout << a[o];
        if ( o < 9) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}