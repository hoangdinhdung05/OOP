#include<bits/stdc++.h>

using namespace std;

class Nguoi{
    private:
        string ten, ns;
    public:
        Nguoi(){
            ten = ns = "";
        }
        void in();
        void out();
};

class Sv : public Nguoi{
    private:
        string msv;
        double gpa;
    public:
        Sv(){
            msv = "";
            gpa = 0;
        }
        string getMsv(){
            return msv;
        }
        void in();
        void out();
};

void Nguoi::in(){
    cin.ignore();
    cout << "Nhap ten SV: ";
    getline(cin, ten);
    cout << "Nhap ngay sinh SV: ";
    cin >> ns;
}

void Nguoi::out(){
    cout << ten << " " << ns << " ";
}

void Sv::in(){
    cout << "Nhap msv: ";
    cin >> msv;
    Nguoi::in();
    cout << "Nhap GPA SV: ";
    cin >> gpa;
}

void Sv::out(){
    cout << msv << " ";
    Nguoi::out();
    cout << gpa << endl;
}

void timkiem(Sv a[], int n){
    cout << "Nhap MSV: ";
    string x;
    cin >> x;
    bool check = false;
    for(int i = 0; i < n; i++){
        if(x == a[i].getMsv()){
            a[i].out();
            check = true;
            break;
        }
    }
    if(!check){
        cout << "Not FOUND\n";
    }
}

int main(){
    int n; cin >> n;
    Sv a[n];
    for(int i = 0; i < n; i++){
        a[i].in();
    }
    cout << "Danh sach SV\n";
    for(int i = 0; i < n; i++){
        a[i].out();
    }
    timkiem(a, n);
    return 0;
}