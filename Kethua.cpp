#include<bits/stdc++.h>

using namespace std;

//Tinh chat 2: Ke thua - giup ta su dung lai code tranh viec du thua.Vi cac class se co cac tinh chat chung cac thuoc tinh nhu ten ngay sinh...=>tao ra class chung 

//Bass class: Class cha - Co nhiem vu dinh nghia khai bao cac phuong thuc chung
//Derived class: class con

//Khi 2 class ke thua nhau no co quan he is-a: VD: xe la mot phuong tien => xe ke thua tu phuong tien

//Class con khong the truy cap truc tiep vao private cua Class Cha=> dung toan tu pham vi

//Khai niem ghi de: Neu 1 ham duoc viet o ca lop con va lop cha thi no se chay lan luot tu cha xuong con

//3 cach ket noi
//1. Public: ke thua tat ca cua lop cha
//2. Private: tat cac thuoc tinh, phuong thuc cua class cha thi o class con se tro thanh private (public lop cha => private class con)
//3. Protected: thi public cua class cha se tro thanh protected cua class con


//Cac kieu ke thua:
//1. Ke thua nhieu lop
//2. Ke thua theo cap bac
//3. Mot lop co the ke thua tu 2 class tro len

class Person{
    private:
        string name, address;
    public:
        string getName(){
            return name;
        }
        string getAddress(){
            return address;
        }
        void setName(string name){
            this->name = name;
        }
        void setAddress(string address){
            this->address = address;
        }
        void nhap(){
            cout << "Nhap ten: ";
            getline(cin, name);
            cout << "Nhap dia chi: ";
            cin >> address;
        }
        void in(){
            cout << name << " " << address << " ";
        }

};

class Student : public Person{
    private:
        double gpa;
    public:
        double getGpa(){
            return gpa;
        }
        void setGpa(double gpa){
            this->gpa = gpa;
        }
        void nhap(){
            Person::nhap();
            cout << "Nhap GPA: ";
            cin >> gpa;

        }
        void in(){
            cout << getName() << " " << getAddress() << " " << gpa << endl;
        }
};


int main(){
    Student s;
    s.nhap();
    s.in();
    return 0;
}
