#include<iostream>
using namespace std;
class shape{
public:
        virtual int area() const = 0;
};

class square : public shape{
private:
    int width;
public:
    square(int w) : width(w) {}
    int area() const override{
        return width*width;
    }
};

class rectangle : public shape{
private:
    int width;
    int height;
public:
    rectangle(int w, int h) : width(w), height(h) {}
    int area() const override{
        return width * height;
    }
};

int main(){
    square s1(40);
    rectangle r1(30,40);
    cout<<s1.area()<<endl;
    cout<<r1.area()<<endl;
}