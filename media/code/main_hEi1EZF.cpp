#include <iostream>
#include<string>

using namespace std;

struct SINHVIEN
{
    string Ten;
    string maSV;
    float diemTB;
};

void nhap1SV(SINHVIEN &);
void nhapDS(SINHVIEN [], int );
void xuat1SV(SINHVIEN);
void xuatDS(SINHVIEN [], int);
void svCoDtbCao(SINHVIEN [], int);
int svCoDtbLonHon5(SINHVIEN [] ,int);
int timKiem(SINHVIEN [], int, string );
int xoaSV(SINHVIEN [], int &, string);
void sapxepDS(SINHVIEN [], int);
void chenDS(SINHVIEN [], int &, SINHVIEN &, int &);


int main()
{
    int n;
    cout << "\n Nhap vao so luong sinh vien: ";
    cin >> n;
    SINHVIEN sv[100];

    nhapDS(sv, n);

    xuatDS(sv, n);

    svCoDtbCao(sv, n);

    if(svCoDtbLonHon5(sv, n) != 0)
        cout << "\n So sinh vien co diem trung binh lon hon hoac bang 5 la: " << svCoDtbLonHon5(sv, n);
    else
        cout << "\n Khong co";

    cin.ignore()
    string tenSV;
    cout << "\n Nhap ten sv: ";
    getline(cin, tenSV);
    if(timKiem(sv, n, tenSV) == -1)
        cout << "\n Khong co";
    else
        cout << "\n Co trong danh sach tai vi tri " << timKiem(sv, n, tenSV);

    cin.ignore();
    string Masv;
    cout << "\n Nhap vao ma sinh vien can xoa: ";
    getline(cin, Masv);
    if(xoaSV(sv, n, Masv) == -1)
        cout << "\n Khong tim thay ma sinh vien ";
    else{
        cout << "\n Danh sach sinh vien sau khi xoa la: ";
        xuatDS(sv, n);
    }


    SINHVIEN sv1;
    int vt;
    chenDS(sv, n, sv1, vt);
    cout << "\n Danh sach sau khi duoc chen la: ";
    xuatDS(sv, n);
    delete sv;
    return 0;
}

void nhap1SV(SINHVIEN &sv)
{
    cin.ignore();
    cout << "\n Nhap vao Ten sv: ";
    getline(cin, sv.Ten);
    cout << "\n Nhap vao ma sv: ";
    getline(cin, sv.maSV);
    cout << "\n Nhap vao diem TB: ";
    cin >> sv.diemTB;
}

void nhapDS(SINHVIEN sv[], int n)
{
    for(int i = 0; i < n; i++)
        nhap1SV(sv[i]);
}

void xuat1SV(SINHVIEN sv)
{
    cout << "\n Ten sv: " << sv.Ten;
    cout << "\n Ma sv: " << sv.maSV;
    cout << "\n Diem TB: " << sv.diemTB;
}

void xuatDS(SINHVIEN sv[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "\n\t\t Sinh vien thu " << i + 1 << ": " << endl;
        xuat1SV(sv[i]);
    }
}

void svCoDtbCao(SINHVIEN sv[], int n)
{
    float Max = sv[0].diemTB;

    for(int i = 0; i < n; i++)
        if(sv[i].diemTB > Max)
            Max = sv[i].diemTB;

    cout << "\n\n\t Nhung sv co diem trung binh cao nhat la: ";
    for(int i = 0; i < n; i++)
    {
        if(sv[i].diemTB == Max)
            cout << "\n Sinh vien thu " << i + 1 << ": " << endl;
            xuat1SV(sv[i]);
    }
}

int svCoDtbLonHon5(SINHVIEN sv[] ,int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
        if(sv[i].diemTB >= 5)
            count ++;
    return count;
}

int timKiem(SINHVIEN sv[], int n, string TenSV)
{
    for(int i = 0; i < n; i++)
        if(sv[i].Ten == TenSV)
            return i;
    return -1;
}


int xoaSV(SINHVIEN sv[], int &n, string maSV)
{
    /// Tìm mã sinh viên có trong mảng và trả về vị trí
    /// if không có trả về -1
    /// dịch phải mảng và trả về index
    int index = -1;
    for(int i = 0; i < n; i++){
        if(sv[i].maSV == maSV){
            index = i;
            break;
        }
    }
    if(index == -1)
        return index;

    for(int i = index; i < n - 1; i ++)
        sv[i] = sv[i + 1];
    n--;
    return index;
}

void chenDS(SINHVIEN sv[], int &n, SINHVIEN &sv1, int &vt)
{
    /// Kiem tra vi tri them
    /// neu hop le thi nhap du lieu sv va tien hanh dich trai

    cout << "\n Nhap vao vi tri can them ";
    cin >> vt;
    if(vt < 0 || vt >= n)
    {
        cout << "\n Vi tri khong hop le ";
        return;
    }

    nhap1SV(sv1);

    for(int i = n; i > vt; i)
        sv[i] = sv[i-1];

    n++;
    sv[vt] = sv1;
}
