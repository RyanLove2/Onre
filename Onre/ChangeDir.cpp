#include"ChangeDir.h"



ChangeDir::ChangeDir(){


}


ChangeDir::~ChangeDir(){



};


char* ChangeDir::SetFolderName(char* val){
	this->name = val;

}

char* ChangeDir::GetFolderName(){

	return this->name;
}

void ChangeDir::SetPath(){

				//char * mypath = al_get_current_directory();
		custpath = al_create_path("");
		al_append_path_component(custpath,GetFolderName());
		al_change_directory(al_path_cstr(custpath,ALLEGRO_NATIVE_PATH_SEP));
		std::cout<<"\n";
		std::cout<<"\n";
		std::cout<<"DONE";
		std::cout<<al_get_current_directory();

}
