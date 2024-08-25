#include<bits/stdc++.h>

using namespace std;
//Bai 5:
// Input:
// 4
// Nguyen Van F
// 2002-06-06
// SV006 4.0
// Tran Thi G
// 2003-07-07
// SV007 3.2
// Le Van H
// 2001-08-08
// SV008 3.8
// Pham Thi I
// 1999-09-09
// SV009 2.5

// Output:
// Nguyen Van F 2002-06-06 SV006 4.0
// Le Van H 2001-08-08 SV008 3.8
// Tran Thi G 2003-07-07 SV007 3.2
// Pham Thi I 1999-09-09 SV009 2.5

class Nguoi{
    private:
        string ten, date;
    public:
        Nguoi(){
            ten = date = "";
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
        double getGpa(){
            return gpa;
        }
        void in();
        void out();
};

void Nguoi::in(){
    cin.ignore();
    getline(cin, ten);
    cin >> date;
}

void Nguoi::out(){
    cout << ten << " " << date << " ";
}

void Sv::in(){
    Nguoi::in();
    cin >> msv >> gpa;
}

void Sv::out(){
    Nguoi::out();
    cout << msv << " " << gpa << endl;
}

bool cmp(Sv a, Sv b){
    return a.getGpa() > b.getGpa();
}

int main(){
    int n; cin >> n;
    Sv a[n];
    for(int i = 0; i < n; i++){
        a[i].in();
    }
    sort(a, a+n, cmp);
    for(int i = 0; i < n; i++){
        a[i].out();
    }
    return 0;
}