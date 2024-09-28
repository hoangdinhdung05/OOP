#include<bits/stdc++.h>

using namespace std;

class nguoi{
    private:
        string ten, ns;
    public:
        nguoi(){
            ten = ns = "";
        }
        nguoi(string ten, string ns){
            this->ten = ten;
            this->ns = ns;
        }

        void nhap();
        void xuat();
};

void nguoi::nhap(){
    getline(cin, ten);
    cin >> ns;
}

void nguoi::xuat(){
    cout << ten << " " << ns << " ";
}


class sinhvien : public nguoi{
    private:
        string msv;
        double gpa;
    public:
        sinhvien(){
            msv = "";
            gpa = 0.0;
        }
        sinhvien(string msv, double gpa){
            this->msv = msv;
            this->gpa = gpa;
        }

        void nhap();
        void xuat();

        double getGpa(){
            return gpa;
        }

        string getMsv(){
            return msv;
        }

};

void sinhvien::nhap(){
    cin >> msv;
    cin.ignore();
    nguoi::nhap();
    cin >> gpa;
}

void sinhvien::xuat(){
    cout << msv << " ";
    nguoi::xuat();
    cout << gpa << endl;
}



void sort(sinhvien a[], int n){
    for(int i = 0; i < n - 1; i++){
        int max = i;
        for(int j = i + 1; j < n; j++){
            if(a[j].getGpa() > a[max].getGpa()){
                max = j;
            }
        }
        // swap(a[i], a[max]);
        sinhvien doi = a[i];
        a[i] = a[max];
        a[max] = doi;
    }
}

void timkiem(sinhvien a[], int n, string x){
    bool check = false;
    for(int i = 0; i < n; i++){
        if(a[i].getMsv() == x){
            a[i].xuat();
            check = true;
        }
    }
    if(!check) cout << "NOT FOUND\n";
}

int main(){
    int n; cin >> n;
    sinhvien a[n];
    for(int i = 0; i < n; i++){
        cin.ignore();
        a[i].nhap();
    }
    for(auto x : a){
        x.xuat();
    }
    cout << "Danh sach sau khi sap xep:\n";
    sort(a, n);
    for(auto x : a) x.xuat();
    cin.ignore();
    string x; cin >> x;
    timkiem(a, n, x);
    return 0;
}