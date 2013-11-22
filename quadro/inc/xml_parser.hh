#ifndef XML_PARSER_HH
#define XML_PARSER_HH
#include <sstream>
#include <iostream>
#include "rapidxml_print.hpp"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "scene.hh"

using namespace rapidxml;

class XML_Parser {
    public:
        XML_Parser (char* file_name);
        bool startParse(Scene & scene);



    private:
    xml_document<> doc;
    xml_node<> *pRoot;
};

#endif
