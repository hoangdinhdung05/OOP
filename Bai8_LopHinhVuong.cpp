#include <bits/stdc++.h>

using namespace std;

class HinhVuong{
    protected:
        int c1;
    public:
        HinhVuong() {
            c1 = 0;
        }

        HinhVuong(int c){
            c1 = c;
        }
        int getC1(){
            return c1;
        }

        void nhap(){
            cin >> c1;
        }

        void xuat(){
            cout << c1;
        }
};

class HinhChuNhat : public HinhVuong{
    private:
        int c2;
    public:
        HinhChuNhat() : HinhVuong() {
            c2 = 0;
        }

        HinhChuNhat(int c, int d) : HinhVuong(c){
            c2 = d;
        }

        int getC2(){
            return c2;
        }

        void nhap(){
            HinhVuong::nhap();
            cin >> c2;
        }

        void xuat(){
            HinhVuong::xuat();
            cout << " " << c2;
        }

        int getDienTich(){
            return c1 * c2;
        }

        int getChuVi(){
            return 2 * (c1 + c2);
        }

        friend bool cmp(HinhChuNhat, HinhChuNhat);
};

bool cmp(HinhChuNhat a, HinhChuNhat b){
    return a.getChuVi() < b.getChuVi();
}

int main(){
    int n;
    cout << "Nhap so luong hinh chu nhat: ";
    cin >> n;
    HinhChuNhat a[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap canh cho hinh chu nhat thu " << i + 1 << ": ";
        a[i].nhap();
    }
    sort(a, a + n, cmp);
    cout << "\nDanh sach hinh chu nhat sau khi sap xep theo chu vi:\n";
    for(int i = 0; i < n; i++){
        cout << "Hinh chu nhat " << i + 1 << ": ";
        a[i].xuat();
        cout << " - Chu vi: " << a[i].getChuVi() << ", Dien tich: " << a[i].getDienTich() << endl;
    }
    return 0;
}
