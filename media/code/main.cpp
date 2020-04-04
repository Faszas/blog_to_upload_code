// Example program
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void nhapMang(int [], int &);
void xuatMang(int [], int);
void LietKeMaxVaMin(int [], int);
int demAm(int [], int);
int AmLonNhat(int [], int);
int DuongNhoNhat(int [], int);
bool kiemTraNT(int);
void LietKeNguyenTo(int [], int);
bool kiemTraCP(int);
void LietKeCp(int [], int);
bool kiemTraHT(int);
void LietKeHT(int [], int);
int demX(int [], int , int);
int xoaPhanTu(int [], int &, int &);


int main()
{
   int a[100], n;
   nhapMang(a, n);
   xuatMang(a, n);
   LietKeMaxVaMin(a, n);
   cout << "\n So luong so am co trong mang la : " << demAm(a, n);
   cout << "\n So am lon nhat co trong mang: " << AmLonNhat(a, n);
   cout << "\n So duong nho nhat: " << DuongNhoNhat(a, n);
   cout << "\n Cac so nguyen to co trong mang : ";
   LietKeNguyenTo(a, n);
   cout << "\n Cac so chinh phuong co trong mang la: ";
   LietKeCp(a, n);
   cout << "\n Cac so hoan thien co trong mang la : ";
   LietKeHT(a, n);
   cout << "\n Nhap vao X";
   int X;
   cin >> X;
   cout << "\n So luong so X co trong mang la : " << demX(a, n, X);
   int vt;
   if(xoaPhanTu(a, n, vt) == -1)
        cout << "\n vi tri khong hop le ";
   else{
        cout << "\n Mang sau khi duoc xoa la : ";
        xuatMang(a, n);
   }

   return 0;
}



void nhapMang(int a[], int &n){
    cin >> n;
    srand (time(NULL));
    for(int i = 0; i < n; i++)
        a[i] = rand()%200 - 100;
}

void xuatMang(int a[], int n){
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void LietKeMaxVaMin(int a[], int n){
    int Max = a[0];
    for(int i = 0; i < n; i++)
        if(a[i] > Max)
            Max = a[i];
    cout << "\nMax co trong mang la : ";
    for(int i = 0; i < n; i++)
         if(a[i] == Max)
            cout << a[i] << " ";

    int Min = a[0];
    cout << "\nMin co trong mang la : ";
    for(int i = 0; i < n; i++)
        if(a[i] < Min)
            Min = a[i];
    for(int i = 0; i < n; i++)
         if(a[i] == Min)
            cout << a[i] << " ";
}

int demAm(int a[], int n){
    int count = 0;
    for(int i = 0; i < n; i++)
        if(a[i] < 0)
            count ++;
    return count;
}

int AmLonNhat(int a[], int n){
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            temp = a[i];
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] < 0 && a[i] > temp)
            temp = a[i];
    }
    return temp;
}

int DuongNhoNhat(int a[], int n){
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            temp = a[i];
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] > 0 && a[i] < temp)
            temp = a[i];
    }
    return temp;
}

bool kiemTraNT(int n){
    for(int i = 2; i <= n/2; i++)
        if(n % i == 0)
            return false;
    return (n >= 2);
}

void LietKeNguyenTo(int a[], int n){
    for(int i = 0; i < n; i++)
        if(kiemTraNT(a[i]))
            cout << a[i] << " ";
}

bool kiemTraCP(int n){
    for(int i = 1; i <= n; i++){
        if(i*i == n)
            return true;
        else if(i*i > n)
            return false;
    }
    return false;
}
void LietKeCp(int a[], int n){
    for(int i = 0; i < n; i++)
        if(kiemTraCP(a[i]))
            cout << a[i];
}

bool kiemTraHT(int n){
    int sum = 0;
    for(int i = 1; i <= n/2; i++)
        if(n % i == 0)
            sum += i;
    return (sum == n);
}

void LietKeHT(int a[], int n){
    for(int i = 0; i < n; i++)
        if(kiemTraHT(a[i]))
            cout << a[i];
}

int demX(int a[], int n, int X){
    int count = 0;
    for(int i = 0; i < n; i++)
        if(a[i] == X)
            count ++;
    return count;
}

int xoaPhanTu(int a[], int &n, int &vt){
    cout << "\n nhap vao vi tri can xoa: ";
    cin >> vt;
    if(vt >= n || vt < 0)
        return -1;
    for(int i = vt; i < n - 1; i++)
        a[i] = a[i + 1];
    n --;
    return 1;
}
