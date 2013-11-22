#include "menu.hh"
Menu::Menu(CommandsParser & parser, CommandsList & list, RobotPose & robot): \
_parser(parser) , _list(list), _robot(robot), _output_file_name("output.dat"){

}

/**
* @brief starts menu
*/
void Menu::menu(){
    char character = '?';
    while( (character != 'q') and decision(character)  ){
        cout<<">>";
        cin>>character;
    }
    system("killall gnuplot");
   
}

/**
* @brief choose decision
*
* @param option
*
* @return 1 if everything is ok 
*/
bool Menu::decision(char option){
   if ( option == '?' ){
       help();
       return 1;
   }

   if ( option == 'r' ){
       readCommands();
       return 1;
   }

   if ( option == 's' ){
       showCommands();
       return 1;
   }

   if ( option == 'e' ){
       execCommands();
       return 1;
   }

   cout<<"nie rozpoznano opcji "<<option<<" "<<endl;
   help();  
   return 1;

}

/**
* @brief  reads commands from file_name defined in class filed
*/
void Menu::readCommands(){
#ifndef FAST
    std::string name;
    cout<<"input file name : ";
    cin>>name; 
    setInputFile(name);
#endif
    ifstream file( _input_file_name.c_str() );
    _parser.ReadCmdsList(file ,_list);
    if (_list.size() == 0 ){
        setInputFile("");
        std::cout<<"no commands in provided file, choose another one"<<std::endl;
    }
}

/**
* @brief exec commands
*/
void Menu::execCommands(){
    if (_input_file_name != ""){
        system("gnuplot ./realtime.cfg &");
        ofstream file( _output_file_name.c_str() );
        _parser.execCmdsList(file,_robot,_list);
        //system("killall gnuplot");
    }else{
        std::cout<<"no input file specified - choose r option first!"<<std::endl;
    }
} 

/**
* @brief sets input file
*
* @param file_name
*/
void Menu::setInputFile(std::string file_name){
    _input_file_name =   file_name ;

}

/**
* @brief sets output file
*
* @param file_name
*/
void Menu::setOutputFile(std::string file_name){
    _output_file_name =  file_name ;
}

/**
* @brief shows commands
*/
void Menu::showCommands(){
    cout<<"INSTRUKCJE : " <<endl;
    _parser.showCmdsList(_list);
}


/**
* @brief shows help
*/
void Menu::help(){
    cout<<"r - read commands from file"<<endl;
    cout<<"s - show commands list"<<endl;
    cout<<"e - execute commands"<<endl;
    cout<<"q - quit app "<<endl;
    cout<<"? - wyswietl ponownie menu"<<endl;
}

