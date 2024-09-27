#include <iostream>
#include <cmath>
#include <locale.h>

#define Pi 3.14





class Circle {
    private : 
        int radius;
    public:
        double PerimetreCircle() {
            return Pi * 2 * this->radius;
        };
        double SpaceCircle() {
            return  this->radius * this->radius * Pi;
        };

    Circle(int r) {this->radius = r;};
    Circle(Circle &circle) {this->radius = circle.radius;}
    
};





class Triangle{
    private:
        int len1, len2, len3;

    public:
        int PerimetreTria() {
            return this->len1 + this->len2 + this->len3;
        };
        double SpaceTria() {
            return sqrt( (this->len1 + this->len2 + this->len3) / 2 * ( (this->len1 + this->len2 + this->len3) / 2 - this->len1   ) * ( (this->len1 + this->len2 + this->len3) / 2 - this->len2   ) * ( (this->len1 + this->len2 + this->len3) / 2 - this->len3   ) );
        };

    
        Triangle(int l1, int l2, int l3) {
            this->len1 = l1;
            this->len2 = l2;
            this->len3 = l3;
        }
};






class Rectangle{
    private: 
        int lenght;
        int width;

    public:
        int PerimetreRect() {return (this->lenght + this->width) * 2;};

        int SpaceRect() {return this->lenght * this->width;};

        Rectangle(int l, int w) {
            this->lenght = l; this->width = w;
        }; 
};







 int main() {
    setlocale(LC_ALL, "rus");
    std::cout<<"Введите радиус ";
    int r;
    std::cin>>r;
    Circle* circle = new Circle(r);
    Circle c1 = Circle(*circle);
    std::cout<< "Длина окружности - " << c1.PerimetreCircle() << " Площадь окружности - " << c1.SpaceCircle();

    std::cout << std::endl <<"Введите длину и ширину "; 
    int l, w;
    std:: cin >> l >> w;    
    Rectangle rectangle = Rectangle(l, w);
    Rectangle r1 = Rectangle(rectangle);
    std::cout << "Периметр прямоугольника - " << r1.PerimetreRect() << " Площадь прямоугольника - " << r1.SpaceRect();



    std::cout<< std::endl << "Введите длины сторон треугольника ";
    int a, b, c;
    std::cin>>a>>b>>c;
    Triangle triangle = Triangle(a,b,c);
    std::cout<< "Периметр треугольника - " << triangle.PerimetreTria() << " Площадь треугольника - " << triangle.SpaceTria();

 }