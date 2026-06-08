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
// Ham sap xep vun dong
void heapSort(int arr[], int n) {
    // xay dung dong lon nhat
    cout << "\n-QUA TRINH VUN DONG BAN DAU-" << endl;
    for (int i = n / 2 - 1; i >= 0; i--) {
        hamvundong(arr, n, i);
        cout << "Buoc vun dong nut tai vi tri " << i << " (Gia tri " << arr[i] << "): ";
        intrangthailuutru(arr, n);
    }

    //sap xep
    cout << "\n-QUA TRINH SAP XEP-" << endl;
    for (int i = n - 1; i > 0; i--) {
        // Dua phan tu lon nhat xuong cuoi mang chua duoc sap xep
        swap(arr[0], arr[i]);

        // Goi vun dong lai phan con lai cua mang
        hamvundong(arr, i, 0);
        cout << "Trang thai sau khi dua " << arr[i] << " ve cuoi mang: ";
        intrangthailuutru(arr, n);
    }
}

int main() {
    // voi dau vao ở trên bảng
    int arr[] = { 11, 54, 32, 105, 38, 78, 203, 16, 84, 17, 39, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);


    cout << "- TRANG THAI LUU TRU BAN DAU CUA MANG: " << endl;
    intrangthailuutru(arr, n);

     // Thuc hien thuat toan
    heapSort(arr, n);
        cout << "\n" << endl;
        cout << "MANG SAU KHI SAP XEP TANG DAN: ";
        intrangthailuutru(arr, n);

    return 0;
}