#include<bits/stdc++.h>

using namespace std;
//Bai 9:
// 3
// Nguyen Van A
// Giam Doc
// Nam
// 2000-05-15
// 123 Nguyen Trai
// 22
// Tran Thi B
// Nhan Vien
// Nu
// 2005-08-22
// 456 Le Lai
// 15
// Le Van C
// Truong Phong
// Nam
// 1999-12-01
// 789 Hai Ba Trung
// 25

class NV{
    private:
        string ten, chucvu, gioitinh, ns, dc;
        int nvl;
    public:
        NV(){};
        
        friend istream& operator >> (istream& in, NV&);
        friend ostream& operator << (ostream& out, NV);

        int getNvl(){
            return nvl;
        }
};

istream& operator >> (istream& in, NV& x){
    // cin.ignore();
    getline(in, x.ten);
    getline(in, x.chucvu);
    getline(in, x.gioitinh);
    getline(in, x.ns);
    getline(in, x.dc);
    cin >> x.nvl;
    return in;
}

ostream& operator << (ostream& out, NV x){
    out << x.ten << " " << x.chucvu << " " << x.gioitinh << " " << x.ns << " " << x.dc << " " << x.nvl << endl;
    return out;
}

int main(){
    int n; cin >> n;
    NV a[n];
    for(int i = 0; i < n; i++){
        cin.ignore();
        cin >> a[i];
    }
    cout << "Danh Sach NV\n";
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    cout << "Danh Sach NV Lau Nam\n";
    for(int i = 0; i < n; i++){
        if(2024 - a[i].getNvl() >= 20){
            cout << a[i];
        }
    }
    return 0;
}