#include <iostream>
using namespace std;

// Ham in trang thai luu tru cua mang
void intrangthailuutru(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// hàm vun đôgns tạo max heap
void hamvundong(int arr[], int n, int i) {
    int max = i;         // gốc là lon nhất
    int left = 2 * i + 1;   
    int right = 2 * i + 2;   

	// lan luot ktra xem con trai va con phai co lon hon cha hien tai hay khong
    if (left < n && arr[left] > arr[max]) 
    {
        max = left;
    }

    if (right < n && arr[right] > arr[max]) 
    {
        max = right;
    }

    // doi cho
    if (max != i) {
        swap(arr[i], arr[max]); 
        hamvundong(arr, n, max);
    }
}
int main() {
    // voi dau vao ở trên bảng
    int arr[] = { 11, 54, 32, 105, 38, 78, 203, 16, 84, 17, 39, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "- TRANG THAI LUU TRU BAN DAU CUA MANG: " << endl;
    intrangthailuutru(arr, n);

    return 0;
}