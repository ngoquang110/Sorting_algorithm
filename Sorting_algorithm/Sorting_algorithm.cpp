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
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int pos = i - 1;
        while (pos >= 0 && x < a[pos]) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

// Merge sort
// Hàm trộn 2 dãy tăng thành một dãy tăng
/*void mixarr_incre(int a[], int b[], int c[], int m, int k, int& p) {
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
*/

/*void merge(int a[], int l, int mid, int r) {
    vector<int> x(a + l, a + mid + 1);
    vector<int> y(a + mid + 1, a + r + 1);
    int i = 0;
    int j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] < y[j]) {
            a[l] = x[i];
            l++;
            i++;
        }
        if (y[j] < x[i]) {
            a[l] = y[j];
            l++;
            j++;
        }
    }
    while (i < x.size()) {
        a[l] = x[i];
        l++;
        i++;
    }
    while (j < y.size()) {
        a[l] = y[j];
        l++;
        j++;
    }
}*/

void merge(int a[], int l, int mid, int r) {
    int* b = new int[mid - l + 1];
    int p = 0;
    int* c = new int[r - mid];
    int e = 0;
    for (int i = l; i <= mid; i++) {
        b[p++] = a[i];
    }
    for (int i = mid + 1; i <= r; i++) {
        c[e++] = a[i];
    }
    int i = 0;
    int j = 0;
    while (i < p && j < e) {
        if (b[i] < c[j]) {
            a[l] = b[i];
            ++l;
            ++i;
        }
        else {
            a[l] = c[j];
            ++l;
            ++j;
        }
    }
    while (i < p) {
        a[l] = b[i];
        ++l;
        ++i;
    }
    while (j < e) {
        a[l] = c[j];
        ++l;
        ++j;
    }
    delete[]b;
    delete[]c;
}

void merge_sort(int a[], int l, int r) {
    if (l >= r) return;
    else { // Đoạn cần sắp xếp phải nhỏ hơn một phần tử chứ nó l=r thì chỉ có 1 phần tử, thế thì không cần sắp xếp
        int mid = (l + r) / 2;
        merge_sort(a, l, mid); // Sắp xếp bên trái 
        merge_sort(a, mid + 1, r); // Sắp xếp bên phải
        merge(a, l, mid, r);
    }
}
// Bubble sort
void bubble_sort(int a[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
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
            i++;
            j--;
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
/*
void insert_incre(int a[], int& n, int x) {
    for (int i = 0; i < n; i++) {
        if (x < a[i]) {
            for (int j = n; j > i; j--) {
                a[j] = a[j - 1];
            }
            a[i] = x;
            break;
        }
    }
    n++;
}
*/

void insert_incre(int a[], int& n, int x) {
    int pos = n - 1;
    while (pos >= 0 && x < a[pos]) {
        a[pos + 1] = a[pos];
        pos--;
    }
    a[pos + 1] = x;
    n++;
}

//Interchange sort
void interchange_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

// Heap sort
// Xếp heap max
void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[largest] < a[l]) {
        largest = l;
    }
    if (r < n && a[largest] < a[r]) {
        largest = r;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n) {
    // Tìm hàm heap max
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    // Hoán đổi giá trị ở node gốc với phần tử ở cuối mảng rồi i-- nghĩa là không xét phần tử ở cuối mảng nữa
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// Shaker sort
void shaker_sort(int a[], int n) { // Đây là kiểu nâng cao của bubble sort khi mà nó xếp luôn cmn cả 2 chiều mà không cần phải quay đầu như bbs
    int l = 0;
    int r = n - 1;
    int k = 0;
    while (l < r) {
        for (int i = l; i < r; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        r = k;
        for (int i = r; i > l; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        l = k;
   }
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    random_in(a, n);
    shaker_sort(a, n);
    in_screen(a, n);
    cout << endl;
    int b;
    cin >> b;
    insert_incre(a, n, b);
    in_screen(a, n);


    return 0;
}
