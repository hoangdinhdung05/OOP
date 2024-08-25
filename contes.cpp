#include<bits/stdc++.h>

using namespace std;
using ll = long long;

//ma ten hang mau, tocdo, gia
//ma ten hang mau, maluc gia

//Bai 10: Ke thuc

class phuongtien{
    private:
        string ma, ten, hang, mau;
        int gia;
    public:
        phuongtien(string ma, string ten, string hang, string mau, int gia){
            this->ma = ma;
            this->ten = ten;
            this->hang = hang;
            this->mau = mau;
            this->gia = gia;
        }

        void in(){
            cout << ma << " " << ten << " " << hang << " " << mau << " ";
        }

        int getGia(){
            return gia;
        }

        string getTen(){
            return ten;
        }

};


class moto : public phuongtien{
    private:
        int tocdo;
    public:
        moto(string ma, string ten, string hang, string mau, int gia, int tocdo) : phuongtien(ma, ten, hang, mau, gia){
            this->tocdo = tocdo;
        }

        void in(){
            phuongtien::in();
            cout << tocdo << " " << phuongtien::getGia() << endl;
        }
};


class oto : public phuongtien{
    private:
        int maluc;
    public:
        oto(string ma, string ten, string hang, string mau, int gia, int maluc) : phuongtien(ma, ten, hang, mau, gia){
            this->maluc = maluc;
        }

        void in(){
            phuongtien::in();
            cout << maluc << " " << phuongtien::getGia() << endl;
        }
};

vector<moto> v1;
vector<oto> v2;

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        string ma;
        cin >> ma;
        cin.ignore();
        if(ma[0] == 'O'){
            string ten, hang, mau;
            getline(cin, ten);
            cin >> hang >> mau;
            int gia, maluc;
            cin >> gia >> maluc;
            oto a(ma, ten, hang, mau, gia, maluc);
            v2.push_back(a);
        }
        else{
            string ten, hang, mau;
            getline(cin, ten);
            cin >> hang >> mau;
            int gia, tocdo;
            cin >> gia >> tocdo;
            moto a(ma, ten, hang, mau, gia, tocdo);
            v1.push_back(a);
        }
    }

    cout << "Nhap ten can tim kiem: \n";
    cin.ignore();
    string ten; getline(cin, ten);
    cout << "Danh sach oto: \n";
    for(auto x : v2){
        if(x.getTen() == ten){
            x.in();
        }
    }
    cout << "Danh sach moto: \n";
    for(auto x : v1){
        if(x.getTen() == ten){
            x.in();
        }
    }
    return 0;
}


// 5
// OTO1
// HONDAT5
// HONDA
// Vang
// 186
// 850
// XM2
// HON112
// HONDA
// Xanh
// 200
// 40
// XM3
// HON112
// HONDA 
// Vang
// 180
// 100
// OTO4
// TOY555
// TOYOTA
// Vang
// 150
// 2400
// XM5
// EX
// YAMAHA
// Trang
// 220
// 28
// TOY555