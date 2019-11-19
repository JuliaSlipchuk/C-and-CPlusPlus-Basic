#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Engine
{
private:
    double volume;
public:
    double get_volume()
    {
        return this->volume;
    }
    void print()
    {
        cout << "Engine: " << this->get_volume();
    }
    Engine(double v)
    {
        this->volume = (v >= 0.5) ? v : 0.5;
    }
    Engine()
    {}
};
class Wheel
{
private:
    int diametr;
public:
    int get_diametr()
    {
        return  this->diametr;
    }
    void print()
    {
        cout << "Wheel: " << this->get_diametr() << " inches";
    }
    Wheel(int d)
    {
        this->diametr = (d >= 9) ? d : 9;
    }
    Wheel()
    {}
};
class Chassis
{
private:
    string type;
public:
    string get_type()
    {
        return  this->type;
    }
    void print()
    {
        cout << "Chassis: " << this->get_type();
    }
    Chassis(string t)
    {
        if (t == "Normal" || t == "Anormal")
            this->type = t;
        else
            this->type = "Normal";
    }
    Chassis()
    {}
};
class Light
{
private:
    int type;
public:
    int get_type()
    {
        return this->type;
    }
    void print()
    {
        cout << "Light: Type " << this->get_type();
    }
    Light(int t)
    {
        this->type = type;
    }
    Light()
    {}
};
class Body
{
private:
    string color;
public:
    string get_color()
    {
        return this->color;
    }
    void print()
    {
        cout << "Body: " << this->get_color();
    }
    Body(string c)
    {
        if (c == "Black" || c == "White" || c == "Red" || c == "Yellow" || c == "Green" || c == "Blue")
            this->color = c;
        else
            this->color = "Black";
    }
    Body()
    {}
};
class Car
{
private:
    Engine engine;
    Wheel* wheels;
    Chassis chassis;
    Light* lights;
    Body body;
public:
    Car(Engine eng, Wheel whs[4], Chassis ch, Light lghs[10], Body bd)
    {
        this->engine = eng;
        this->wheels = whs;
        this->chassis = ch;
        this->lights = lghs;
        this->body = bd;
    }
    void print()
    {
        this->engine.print();
        for (int i = 0; i < 4; i++)
        {
            this->wheels[i].print();
        }
        this->chassis.print();
        for (int i = 0; i < 10; i++)
        {
            this->lights[i].print();
        }
        this->body.print();
    }
};

int main()
{
    // second part
    Wheel whs[4] = {Wheel(16), Wheel(16), Wheel(16), Wheel(16)};
    Light lghs[10] = {Light(), Light(), Light(),
                      Light(), Light(), Light(),
                      Light(), Light(), Light(),
                      Light()};
    Car car(Engine(1.0), whs, Chassis("Normal"), lghs, Body("White"));
    car.print();

    return 0;
}
