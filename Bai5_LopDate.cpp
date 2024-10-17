#include<bits/stdc++.h>

using namespace std;

class Date{
    private:
        int ngay, thang, nam;
    public:
        Date(){
            ngay = thang = nam = 0;
        }

        void nhap();
        void xuat();

        friend bool check(Date);
        
        Date& operator++();
        Date& operator--();
};

void Date::nhap(){
    cin >> ngay >> thang >> nam;
}

void Date::xuat(){
    cout << ngay << "/" << thang << "/" << nam << endl;
}

bool checkNam(int n){
    if(n % 4 == 0 && (n % 100 != 0 || n % 400 == 0)) return true;
    return false;
}

bool check(Date a){
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(a.thang > 12 || a.thang < 1) return false;
    int maxDay = months[a.thang - 1];
    if(a.thang == 2 && checkNam(a.nam)) maxDay = 29;
    if(a.ngay > maxDay || a.ngay < 1) return false;
    return true;
}

Date& Date::operator++(){
    ngay++;
    if(!check(*this)){
        ngay = 1;
        thang++;
        if(thang > 12){
            thang = 1;
            nam++;
        }
    }
    return *this;
}

Date& Date::operator--(){
    ngay--;
    if(ngay < 1){
        thang--;
        if(thang < 1){
            thang = 12;
            nam--;
        }
        int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(thang == 2 && checkNam(nam)) months[1] = 29;
        else ngay = months[thang - 1];
    }
}

int main(){
    Date d;
    d.nhap();
    d.xuat();
    ++d;
    d.xuat();
    --d;
    d.xuat();
    return 0;
}