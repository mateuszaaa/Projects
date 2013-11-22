
#ifndef SCENE_HH
#define SCENE_HH
#include <iostream>
#include <vector>
class Object
{
public:
    Object(std::string _name,double _x,double _y, double _z): name(_name), x(_x), y(_y), z(_z){};
    std::string name;
    double x;
    double y;
    double z;
    void show(){
        std::cout<<name<<" ( "<<x<<" "<<y<<" "<<z<<" ) "<<std::endl; 
    };
};

class Scene
{
public:
    bool addObject(Object *obj);
    Object* getObject(std::string name);
    Object* getObject(double x,double y, double z);
    void show();
private:
    std::vector<Object*> objects;
};

#endif
