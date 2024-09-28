#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class hoSo
{
protected:
    string ma, hoDem, ten;

public:
    void nhap_HS();
    void hienThi_HS();
};
class Diem : public hoSo
{
protected:
    double dlt, dth;

public:
    void nhap_d();
    void hienThi_d();
};
class ketQua : public Diem
{
public:
    void hienThi_KQ();
};
void hoSo::nhap_HS()
{
    cout << "nhap MSV: ";
    cin >> ma;
    cout << "nhap ho dem: ";
    cin.ignore();
    getline(cin, hoDem);
    cout << "nhap ten: ";
    getline(cin, ten);
}
void hoSo::hienThi_HS()
{
    cout << left << setw(10) << ma << setw(20) << hoDem << setw(10) << ten;
}
void Diem::nhap_d()
{
    hoSo::nhap_HS();
    cout << "nhap diem ly thuyet: ";
    cin >> dlt;
    cout << "nhap diem thuc hanh: ";
    cin >> dth;
}
void Diem::hienThi_d()
{
    hoSo::hienThi_HS();
    cout << left << setw(10) << dlt << setw(10) << dth << endl;
}
void ketQua::hienThi_KQ()
{
    if (dlt >= 5 && dth >= 5)
    {
        Diem::hienThi_d();
    }
}
int main()
{
    int n;
    cout << "nhap so hoc sinh: ";
    cin >> n;
    ketQua a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].nhap_d();
    }
    cout << "nhung sinh vien dau: " << endl;
    cout << left << setw(10) << "MSV" << setw(20) << "Ho dem" << setw(10) << "ten" << setw(10) << "diem LT" << setw(10) << "diem TH" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].hienThi_KQ();
    }
}