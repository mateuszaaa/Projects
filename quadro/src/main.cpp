#include <iostream>
#include <list>
#include <sstream>
#include "xml_parser.hh"
#include "scene.hh"

using namespace std;



int main (int argc, char* args[]) 
{
    Scene scn;
    XML_Parser parser("scene.xml");
    if ( parser.startParse(scn) ){
        std::cout<<"Parsing correct"<<std::endl;
        scn.show();
    }else{
        std::cout<<"Parsing failed"<<std::endl;
    }

//   xml_node<> *pRoot = doc.first_node();
//   xml_attribute<> *pAttr = pRoot->first_attribute("attribute");
//   std::cout<<pAttr->value()<<std::endl;
//
//   cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
//
//   for(xml_node<> *pNode=pRoot->first_node("Object"); pNode; pNode=pNode->next_sibling())
//   {
//        xml_attribute<> *pAttr = pNode->first_attribute("attribute");
//        std::cout<<pAttr->value()<<std::endl;
       // This loop will walk you through two nodes:
       // Do something here


}
