#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 1000002
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define mod 7477777
#define PI 3.1415926535897932384626433832795


int main() {
    int queries;
    cin >> queries;
    long long int heap[queries];
    int qType;
    int curr_size = -1;
    long long int num;
    for (int i = 0; i < queries; i++) {
        cin >> qType;
        if (qType == 1) {
            cin >> num;
            curr_size++;
            int temp = curr_size;
            heap[temp] = num;
            int parent = (temp-1)/2;
            while (parent >= 0 && heap[parent] > heap[temp]) {
                swap(heap[parent], heap[temp]);
                temp = parent;
                parent = (temp - 1)/2;
            }
        }
        else if (qType == 2) {
            cin >> num;
            DeleteElement(heap, curr_size, num);
        }
        else if (qType == 3)
            cout << heap[0] << endl;
    }
    return 0;
}

void DeleteElement(long long int* heap, int& curr_size, int val) {
    int index = -1;
    for (int i = 0; i <= curr_size; i++) {
        if (heap[i] == val) {
            index = i;
            break;
        }
    }
    swap(heap[curr_size], heap[index]);
    curr_size--;
    MinHeapify(heap, curr_size, index);
    return;
}

void MinHeapify(long long int* heap, int curr_size, int index) {
    if (index >= curr_size)
        return;
    int temp = index;
    int left = 2*temp+1;
    int right = 2*temp+2;
    if (left <= curr_size && heap[left] < heap[temp])
        temp = left;
    if (right <= curr_size && heap[right] < heap[temp])
        temp = right;
    if (temp == index)
        return;
    swap(heap[temp], heap[index]);
    MinHeapify(heap, curr_size, temp);
    return;
}
