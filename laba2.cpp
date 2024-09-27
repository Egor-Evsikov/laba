#include <iostream>
#include <locale.h>
#include <fstream>
#include <limits>
#include <cmath>



class Money{
    private: 
        long rubles;
        unsigned char kopeck;
    public :
//�������
        long GetRubles (){
            return this->rubles;
        }
        unsigned char GetKopeck() {
            return this->kopeck;
        }
//�������        
        void ResetMoney(){
            this->rubles = 0;
            this->kopeck = 0;
        }

        void SetMoney() {
            std::cout << "������� ����� �� ���� ";
            int a;
            while (2 + 2 != 5) {
                std::cin>> rubles ;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std:: numeric_limits<std::streamsize>::max(), '\n');  
                    std::cout<<"������������ ����";
                } else break;
            }

            std::cin >> a;
            while (std::cin.fail() || a < 0 || a > 99) {
                std::cin.clear();
                std::cin.ignore(std:: numeric_limits<std::streamsize>::max(), '\n');  
                std::cout<<"������������ ����";
                std::cin >> a;
            }
        
            kopeck = static_cast<unsigned char>(a);


        }

//������������
    Money(int r, unsigned char k) :  rubles(r), kopeck(k) {}    
    Money(int r) : rubles(r), kopeck(0) {}
    Money(unsigned char k) : kopeck(k), rubles(0) {}
    Money() : rubles(0), kopeck(0) {}

    Money (Money &money) {
        this->rubles = money.rubles;
        this->kopeck = money.kopeck;
    }

    ~Money() {
        std::cout<< "������ ������!" << std::endl; 
        std::fstream file("laba2.txt", std::ios::app| std::ios::in);
        if (file.is_open()) {
            file << "�� ����� " << this->rubles << "," << static_cast<int>(kopeck) << "������" << std::endl;
            file.close();
        } else {
            std::cerr << "�� ������� ������� ����";
        }
    
    }

//������� ������ �������
    void IncRub( ) {
        rubles++;
    }
    void PrintMoney(){
            std::cout<<"����� �� ����� - "<<this->rubles<<","<<static_cast<int>(kopeck) << std::endl;
    }
    void PrintMoney (Money &m) {
        if (m.rubles > this->rubles && m.kopeck > this->kopeck) std::cout<<"��� ��� ����� ��������� ������" << std::endl; else std::cout<<"�� �������-�� ������� ����� ��������� ���������"<< std::endl;
    }
};


int main() {
    setlocale(LC_ALL, "rus");
    Money bill;
    bill.SetMoney();
    bill.PrintMoney();
    int r; int k;
    
    {
        std::cout<< std::endl <<"������� ����� ������� ";
        std::cin>> r >> k;
        Money credit = Money(r, static_cast<unsigned char>(k) );
        credit.PrintMoney();
        bill.PrintMoney(credit);
    }

    std :: cout << "�������� ����, �������������� ��� ������� ��������� � ������, ��������� ����������� ����������� � ���������� �������� ������ PrintMoney:" << std :: endl;

    bill.ResetMoney();
    bill.IncRub();
    bill.PrintMoney();


    Money credit2(bill);
    bill.PrintMoney(credit2);

    r = bill.GetRubles();
    k = bill.GetKopeck();
    std:: cout << "���������� ��������: ����� - " << r << " ������� - " << static_cast<int>(k);
    bill.IncRub();

}