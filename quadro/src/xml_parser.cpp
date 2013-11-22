#include "xml_parser.hh"

XML_Parser::XML_Parser(char* file_name){

   std::ifstream file("scene.xml");
   std::stringstream buffer;
   buffer << file.rdbuf();
   file.close();
   std::string content(buffer.str());
   doc.parse<0>(&content[0]);

}
bool XML_Parser::startParse(Scene & scene){
    bool x_read = false;
    bool y_read = false;
    bool z_read = false;
    double x_val;
    double y_val;
    double z_val;
    xml_attribute<> *name ; 
    xml_attribute<> *value ; 
    xml_node<> *Objects;
    xml_node<> *Params;


   pRoot = doc.first_node();
   if(!pRoot){ return false; }

   Objects = pRoot->first_node("Object");
   for(Objects = pRoot->first_node("Object");Objects;Objects = Objects->next_sibling("Object")){

        x_read = y_read = z_read = false;
       for(Params = Objects->first_node("Parameter");Params;Params = Params->next_sibling("Parameter")){
           name = Params->first_attribute("Name");
           if(!name) {return false;}

           if (name->value() == std::string("Coordinate_x") ){
               value = name->next_attribute("Value");
               if(!value) {return false;}
               x_val = atoi(value->value());
               x_read = true;
           }

           if (name->value() == std::string("Coordinate_y") ){
               value = name->next_attribute("Value");
               if(!value) {return false;}
               y_val = atoi(value->value());
               y_read = true;
           }

           if (name->value() == std::string("Coordinate_z") ){
               value = name->next_attribute("Value");
               if(!value) {return false;}
               z_val = atoi(value->value());
               z_read = true;
           }

       }
       if (x_read && y_read && z_read ){
            name = Objects->first_attribute("Name");
            if(!name) {return false;}
            std::cout<<name->value()<<std::endl;
            Object *obj =  new Object(name->value(),x_val,y_val,z_val) ;
            scene.addObject( obj );

       }
   }
   return true;
}



