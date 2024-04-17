#include <iostream>
#include <random>
#include <fstream>
#include <vector>
using namespace std;

// Phát sinh số nhẫu nhiên
void random_in(int a[], int n) {
    int x;
    int y;
    cout << "MIN: ";
    cin >> x;
    cout << "MAX: ";
    cin >> y;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> uni(x, y);

    for (int i = 0; i < n; i++) {
        a[i] = uni(gen);
    }
}
// Hàm nhập mảng thủ công
void hand_in(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
// Nhập dữ liệu từ file
void file_in(int a[], int n) {
    fstream file;
    file.open("input.txt", ios::in);
    for (int i = 0; i < n; i++) {
        file >> a[i];
    }
}
// Hàm xuất mảng
void in_screen(int a[], int n) {
    cout << "Your array is: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
// Hàm swap
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


// Các thuật toán sắp xếp 
// Selection sort
void selection_sort(int a[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
    }
}
// Insertion sort
void insertion_sort(int a[], int n) {

}

// Merge sort
// Hàm trộn 2 dãy tăng thành một dãy tăng
void mixarr_incre(int a[], int b[], int c[], int m, int k, int& p) {
    int i = 0;
    int j = 0;
    p = m + k;
    for (int v = 0; v < p; v++) {
        if (i < m && j < k) {
            if (a[i] < b[j]) {
                c[p] = a[i];
                i++;
            }
            if (a[i] > b[j]) {
                c[p] = b[j];
                j++;
            }
        }
        else if (i < m) {
            c[p] = a[i];
            i++;
        }
        else if (j < k) {
            c[p] = b[j];
            j++;
        }
    }
}

void merge(int a[], int l, int mid, int r) {
    int* b = new int[mid - l + 1];
    int k;
    int* c = new int[r - mid];
    int m;
    int* temp = new int[r - l + 1];
    int u;
    k = 0;
    for (int i = l; i <= mid; i++) {
        b[k++] = a[i];
    }
    m = 0;
    for (int i = mid + 1; i <= r; i++) {
        c[m++] = a[i];
    }

    mixarr_incre(b, c, temp, k, m, u);
    for (int i = 0; i < u; i++) {
        a[l + i] = temp[i];
    }

    delete []b;
    delete []c;
    delete[]temp;
}

void merge_sort(int a[], int l, int r) {
    if (l < r) { // Đoạn cần sắp xếp phải nhỏ hơn một phần tử chứ nó l=r thì chỉ có 1 phần tử, thế thì không cần sắp xếp
        int mid = (l + r) / 2;
        merge_sort(a, l, mid); // Sắp xếp bên trái 
        merge_sort(a, mid + 1, r); // Sắp xếp bên phải
        merge(a, l, mid, r);
    }
}
// Bubble sort
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

// Quick sort
void quick_sort(int a[], int l, int r) {
    int pivot = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i < j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
        }
        if (i < r) {
            quick_sort(a, i, r);
        }
        if (j > l) {
            quick_sort(a, l, j);
        }
    }
    
}

// Menu của các thuật toán sắp xếp
void menu_sorting(int a[], int n) {
    
}

void run() {
    int a[100];
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "------------------ Select method create your array -------------------" << endl;
    cout << "1. Random create" << endl;
    cout << "2. Handing create" << endl;
    cout << "3. Use file text to fill data" << endl;
    cout << "4. Exit" << endl;

    int select;
    cin >> select;

    switch (select)
    {
    case 1:
        random_in(a, n);
        in_screen(a, n);
        break;
    case 2:
        hand_in(a, n);
        in_screen(a, n);
        break;
    case 3:
        file_in(a, n);
        in_screen(a, n);
        break;
    default:

        break;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    hand_in(a, n);
    merge_sort(a, 0, n - 1);
    in_screen(a, n);
    
    return 0;
}
