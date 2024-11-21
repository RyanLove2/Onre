#include<iostream>
#include<string>
#include<allegro5/allegro.h>



class ChangeDir{

	private: // default Graphics  ,Land, Onre , Samuri, Kitsune
		ALLEGRO_PATH* custpath;
		char* name;

	public:
		void SetPath();
		char* SetFolderName(char* val);
		char* GetFolderName();
		ChangeDir();
		~ChangeDir();



};




