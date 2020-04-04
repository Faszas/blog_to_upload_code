#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void nhapMang(int **, int);
void xuatMang(int **, int);
void lietKeDuong(int **, int);
int timPhanTuMax(int **, int);
int timPhanTuMin(int **, int);
bool isPrime(int);
void LietKeNguyenTo(int **, int);

int main()
{
    cout << "\n Nhap vao kich thuoc cua ma tran: ";
    int M;
    cin >> M;


    int **a = new int*[M];
    for(int i = 0; i< M; i++)
        a[i] = new int[M];


    nhapMang(a, M);
    xuatMang(a, M);

    lietKeDuong(a, M);
    cout << "\n Phan tu max tren duong cheo chinh la : " << timPhanTuMax(a, M);
    cout << "\n Phan tu min tren duong cheo chinh la : " << timPhanTuMin(a, M);
    LietKeNguyenTo(a, M);

    for(int i = 0; i < M; i++)
    {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}


void nhapMang(int **a, int M)
{

    srand(time(NULL));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            a[i][j] = rand()%100 + 1;
}

void xuatMang(int **a, int M)
{
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void lietKeDuong(int **a, int M)
{
    cout << "\n Cac phan tu co gia tri duong co trong mang la : ";
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            if(a[i][j] > 0)
                cout << a[i][j] << " ";
}

int timPhanTuMax(int **a, int M)
{
    int Max = a[0][0];
    for(int i = 0; i < M; i++)
        if(a[i][i] > Max)
            Max = a[i][i];
    return Max;
}


int timPhanTuMin(int **a, int M)
{
    int Min = a[0][0];
    for(int i = 0; i < M; i++)
        if(a[i][i] < Min)
            Min = a[i][i];
    return Min;
}

bool isPrime(int n)
{
    for(int i = 2; i <= n / 2; i++)
        if(n % i == 0)
            return false;
    return (n >= 2);
}


void LietKeNguyenTo(int **a, int M)
{
    cout << "\n Nhung so nguyen to co tren duong treo phu la : ";
    for(int i = 0; i < M; i++)
        if(isPrime(a[i][M - i - 1]) == true)
            cout << a[i][M - i - 1] << " ";
}
