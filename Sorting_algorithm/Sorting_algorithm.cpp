#include <iostream>
#include <random>
#include <fstream>
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
// Bubble sort
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
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
    
    
    return 0;
}
