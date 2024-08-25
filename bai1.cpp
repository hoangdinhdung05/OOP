#include<bits/stdc++.h>

using namespace std;

//Bai 1

class Sinhvien{
    private:
        string msv, ten;
        float toan, li, hoa;
    public:
        Sinhvien(){
            msv = ten = "";
            toan = li = hoa = 0;
        }
        Sinhvien(string msv, string ten, float toan, float li, float hoa){
            this->msv = msv;
            this->ten = ten;
            this->toan = toan;
            this->li = li;
            this->hoa = hoa;
        }

        float getDiem(); // tra ve tong diem
        string getTen(){
            return ten;
        }
        string getMsv(){
            return msv;
        }
        friend istream& operator >> (istream& in, Sinhvien&);
        friend ostream& operator << (ostream& out, Sinhvien); 
        // friend bool cmp(const Sinhvien&, const Sinhvien&);
};

istream& operator >> (istream& in, Sinhvien& x){
    in >> x.msv;
    cin.ignore();
    getline(in, x.ten);
    in >> x.toan >> x.li >> x.hoa;
    return in;
}

float Sinhvien::getDiem(){
    return (toan + li + hoa);
}

ostream& operator << (ostream& out, Sinhvien x){
    out << x.msv << " " << x.ten << " " << x.getDiem() << endl;
    return out;
}

void maxdiem(Sinhvien a[], int n){
    float max = 0;
    for(int i = 0; i < n; i++){
        if(a[i].getDiem() > max){
            max = a[i].getDiem();
        }
    }
    for(int i = 0; i < n; i++){
        if(max == a[i].getDiem()){
            cout << a[i] << endl;
        }
    }
}

bool cmp(Sinhvien a, Sinhvien b){
    if(a.getTen() != b.getTen()) return a.getTen() < b.getTen();
    else return a.getMsv() > b.getMsv();
}

int main(){
    int n; cin >> n;
    Sinhvien *sv;
    sv = new Sinhvien[n];
    for(int i = 0; i < n; i++){
        cin.ignore();
        cin >> sv[i];
    }
    cout << "Danh sach SV\n";
    for(int i = 0; i < n; i++){
        cout << sv[i];
    }
    cout << "Sinh vien co diem cao nhat: \n";
    maxdiem(sv, n);
    sort(sv, sv + n, cmp);
    cout << "Danh sach SV sau khi sap xep\n";
    for(int i = 0; i < n; i++){
        cout << sv[i];
    }
    delete[] sv;

    return 0;
}