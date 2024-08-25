#include <bits/stdc++.h>

using namespace std;

//Bai 2:

// nhap da thuc a:
// nhap bac da thuc: 3
// nhap he so cua x^3: 2
// nhap he so cua x^2: 3
// nhap he so cua x^1: 1
// nhap he so cua x^0: 5

// nhap da thuc b:
// nhap bac da thuc: 3
// nhap he so cua x^3: 1
// nhap he so cua x^2: -3
// nhap he so cua x^1: 2
// nhap he so cua x^0: -1

// da thuc c = a + b: 3x^3 + 0x^2 + 3x + 4
// da thuc c = a - b: 1x^3 + 6x^2 - 1x + 6


class daThuc
{
private:
    int bacDaThuc;
    int heSo[100];

public:
    daThuc();
    daThuc(int bac);
    friend istream &operator>>(istream &in, daThuc &);
    friend ostream &operator<<(ostream &out, daThuc);
    daThuc operator+(daThuc);
    daThuc operator-(daThuc);
};
daThuc::daThuc()
{
    bacDaThuc = 0;
}
daThuc::daThuc(int bac)
{
    bacDaThuc = bac;
    for (int i = bacDaThuc; i >= 0; i--)
    {
        heSo[i] = 0;
    }
}
istream &operator>>(istream &in, daThuc &a)
{
    cout << "nhap bac da thuc: ";
    in >> a.bacDaThuc;
    for (int i = a.bacDaThuc; i >= 0; i--)
    {
        cout << "nhap he so cua x^" << i << ": ";
        in >> a.heSo[i];
    }
    return in;
}
ostream &operator<<(ostream &out, daThuc a)
{
    for (int i = a.bacDaThuc; i >= 0; i--)
    {
        if (i == a.bacDaThuc)
        {
            if (a.heSo[i] > 1)
            {
                out << a.heSo[i] << "x^" << i << " ";
            }
            else if (a.heSo[i] == 1)
            {
                out << "x^" << i << " ";
            }
            else if (a.heSo[i] < -1)
            {
                out << "- " << abs(a.heSo[i]) << "x^" << i << " ";
            }
            else if (a.heSo[i] == -1)
            {
                out << "- x^" << i << " ";
            }
            else
            {
                out << "";
            }
        }
        else if (i < a.bacDaThuc && i > 1)
        {
            if (a.heSo[i] > 1)
            {
                out << "+ " << a.heSo[i] << "x^" << i << " ";
            }
            else if (a.heSo[i] == 1)
            {
                out << "+ x^" << i << " ";
            }
            else if (a.heSo[i] < -1)
            {
                out << "- " << abs(a.heSo[i]) << "x^" << i << " ";
            }
            else if (a.heSo[i] == -1)
            {
                out << "- x^" << i << " ";
            }
            else
            {
                out << "";
            }
        }
        else if (i == 1)
        {
            if (a.heSo[i] > 0)
            {
                out << "+ " << a.heSo[i] << "x ";
            }
            else if (a.heSo[i] < 0)
            {
                out << "- " << abs(a.heSo[i]) << "x ";
            }
            else
            {
                out << "";
            }
        }
        else
        {
            if (a.heSo[i] > 0)
            {
                out << "+ " << a.heSo[i];
            }
            else if (a.heSo[i] < 0)
            {
                out << "- " << abs(a.heSo[i]);
            }
            else
            {
                out << "";
            }
        }
    }
    out << endl;
    return out;
}

daThuc daThuc::operator+(daThuc a)
{
    int maxBac = max(this->bacDaThuc, a.bacDaThuc);
    daThuc temp(maxBac);
    for (int i = 0; i <= this->bacDaThuc; i++)
    {
        temp.heSo[i] += heSo[i];
    }
    for (int i = 0; i <= a.bacDaThuc; i++)
    {
        temp.heSo[i] += a.heSo[i];
    }
    return temp;
}
daThuc daThuc::operator-(daThuc a)
{
    int maxBac = max(this->bacDaThuc, a.bacDaThuc);
    daThuc temp(maxBac);
    for (int i = 0; i <= this->bacDaThuc; i++)
    {
        temp.heSo[i] += heSo[i];
    }
    for (int i = 0; i <= a.bacDaThuc; i++)
    {
        temp.heSo[i] -= a.heSo[i];
    }
    return temp;
}
int main()
{
    daThuc a, b, c;
    cout << "nhap da thuc a: " << endl;
    cin >> a;
    cout << "nhap da thuc b: " << endl;
    cin >> b;
    c = a + b;
    cout << a << endl << b << endl;
    cout << "da thuc c = a + b: " << c;
    c = a - b;
    cout << "da thuc c = a - b: " << c;
    return 0;
}