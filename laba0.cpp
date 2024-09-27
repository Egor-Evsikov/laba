#include <iostream>
#include <string>
#include <vector>
#include <locale.h>

int Sum(int a, int b) {
    if (a * b < 1000) return a * b;
    return a + b;
}

void PrintStr(std::string str) {
    for (int i = 0; i < str.length(); i += 2) std::cout<<str[i]<<" "; 
}

void CheckList() {
    int size;
    std::cout << "Введите размер списка ";
    std::cin >> size;
    std::vector<int> Spisok;
    std::cout <<"Введите список " << std::endl;
    for (int i = 0; i < size; i++) {
        int input;
        std::cin>>input;
        Spisok.push_back(input);
    }
    if (Spisok.back() == Spisok.front()) 
        std::cout<<"True";
    else
        std::cout<<"False";
}

void PrintTria() {
    int n;
    std::cout<< "Введите n ";
    std::cin>> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            std::cout<<j << " ";
        std::cout<<std::endl;
    }
}

void TwoLists() {
    std::vector<int> list1;
    std::vector<int> list2;
    std::cout<<"Введите размер первого списка ";
    int size1, size2;
    std::cin>>size1;
    std::cout<<"Введите список ";
    for (int i = 0; i < size1; i++) {
        int value;
        std::cin>>value;
        list1.push_back(value);
    }
    std::cout<<"Введите размер второго списка ";
    std::cin>>size2;
    std::cout<<"Введите список ";
    for (int i = 0; i < size2; i++) {
        int value;
        std::cin>>value;
        list2.push_back(value);
    }
    std::vector<int> list3;
    for(int i = 0; i < size1; i++) {
        if(list1[i] % 2 == 1) list3.push_back(list1[i]);
    }
    for(int i = 0; i < size2; i++) {
        if(list2[i] % 2 == 0) list3.push_back(list2[i]);
    }
    for(int i = 0; i < list3.size(); i++) {
        std::cout<<list3[i] << " ";
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    
    std::cout<< "Задание 1: "<< std::endl <<"Введите 2 числа ";
    int num1, num2;
    std::cin>> num1 >> num2;
    std:: cout << Sum(num1, num2);

    std::cout<< std::endl << "Задание 2:"<<std::endl<<"Введите строку ";
    std::string str;
    std::cin>>str;
    PrintStr(str);

    std::cout<< std::endl << "Задание 3:"<<std::endl;
    CheckList();

    std::cout<< std::endl << "Задание 4:"<<std::endl;
    PrintTria();
    
    std::cout<< std::endl << "Задание 5:"<<std::endl;
    TwoLists();
}