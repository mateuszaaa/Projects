#include "scene.hh"
bool Scene::addObject(Object *obj){
    objects.push_back(obj);
}

Object* Scene::getObject(std::string _name ){

   std::vector<Object*>::iterator it;
   for( it = objects.begin() ; it != objects.end(); it++ ){
        if ( (*it)->name == _name )
            return (*it); 
   }
   return NULL;
}


void Scene::show(){
   std::vector<Object*>::iterator it;
   for( it = objects.begin() ; it != objects.end(); it++ ){
        (*it)->show(); 
   }

}
