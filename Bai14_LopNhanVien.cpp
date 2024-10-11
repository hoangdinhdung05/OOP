#include<bits/stdc++.h>

using namespace std;

class nhanvien{
    private:
        string ten, chucvu, gioitinh, namsinh, diachi;
    public:
        nhanvien(){
            ten = chucvu = gioitinh = namsinh = diachi = "";
        }

        nhanvien(string ten, string chucvu, string gioitinh, string namsinh, string diachi){
            this->ten = ten;
            this->chucvu = chucvu;
            this->gioitinh = gioitinh;
            this->namsinh = namsinh;
            this->diachi = diachi;
        }

        friend istream& operator >> (istream& in, nhanvien&);

        friend ostream& operator << (ostream& out, nhanvien);

        string getGioitinh(){
            return gioitinh;
        }

        string getNamsinh(){
            return namsinh;
        }

        bool checkNam(nhanvien a){
            if(2024 - stoi(a.namsinh) >= 20){
                return true;
            }   
            return false;
        }

       
};

istream& operator >> (istream& in, nhanvien& a){
    getline(in, a.ten);
    getline(in, a.chucvu);
    getline(in, a.gioitinh);
    getline(in, a.namsinh);
    getline(in, a.diachi);
    return in;
}

ostream& operator << (ostream& out, nhanvien a){
    out << a.ten << " " << a.chucvu << " " << a.gioitinh << " " << a.namsinh << " " << a.diachi << endl;
    return out;
}

int main(){
    int n; cin >> n;
    vector<nhanvien> v(n);
    for(auto &x : v){
        cin.ignore();
        cin >> x;
    }
    cout << "Danh sach nhan vien: \n";
    for(auto x : v){
        cout << x;
    }
    cout << endl;
    cout << "Danh sach nhan vien nghi huu: \n";
    for(auto x : v){
        if(x.getGioitinh() == "Nam" && (2024 - stoi(x.getNamsinh()) >= 60)){
            cout << x;
        }
        if(x.getGioitinh() == "Nu" && (2024 - stoi(x.getNamsinh()) >= 55)){
            cout << x;
        }

    }
    cout << endl;
    cout << "Danh sach nhan vien lam tren 20 nam: \n";
    for(auto x : v){
        if(x.checkNam(x)){
            cout << x;
        }
    }
    return 0;
}