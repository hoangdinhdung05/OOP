#include<bits/stdc++.h>

using namespace std;

class People{
    private:
        string name, birthday, address;
    public:
        People(){
            name = birthday = address = "";
        }

        People(string name, string birthday, string address){
            this->name = name;
            this->birthday = birthday;
            this->address = address;
        }

        void nhap(){
            cout << "Nhap ten: ";
            getline(cin, name);

            cout << "Nhap ngay sinh: ";
            getline(cin, birthday);

            cout << "Nhap dia chi: ";
            getline(cin, address);
        }

        void xuat(){
            cout << "Ten: " << name << "|" << "Ngay sinh: " << birthday << "|" << "Dia chi: " << address << " ";
        }
};

class Teacher : public People{
    private:
        double luong, thuong, phat;
    public:
        Teacher(){
            luong = thuong = phat = 0.0;
        }
        Teacher(string name, string birthday, string address, double luong, double thuong, double phat) : People(name, birthday, address){
            this->luong = luong;
            this->thuong = thuong;
            this->phat = phat;
            // this->thuclinh = thuclinh;
        }

        void nhap(){
            People::nhap();
            cout << "Nhap luong: ";
            cin >> luong;
            cout << "Nhap thuong: ";
            cin >> thuong;
            cout << "Nhap phat: ";
            cin >> phat;
        }

        void xuat(){
            People::xuat();
            cout << "Luong: " << luong << "|" << "Thuong: " << thuong << "|" << "Phat: " << phat << "|" << "Thuclinh: " << (thuong + luong - phat) << " ";
        }

        // double thuclinh(){
        //     return luong + thuong - phat;
        // }
};

int main(){
    cout << "Nhap so luong giang vien: ";
    int n;
    cin >> n;

    Teacher a[n];
    for(int i = 0; i < n; i++){
        cin.ignore();
        a[i].nhap();
    }
    cout << "Danh sach giang vien: " << endl;
    for(int i = 0; i < n; i++){
        a[i].xuat(); cout << endl;
    }
    return 0;
}