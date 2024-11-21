#include"GameObject.h"


GameObject::GameObject(int land){

	al_init_primitives_addon();
	ChangeDir* dir = new ChangeDir();

	dir->SetFolderName("../Land");
	dir->SetPath();



	// create a method that create objects based on strings values
		switch( land){
			case 0:
				platforms = al_load_bitmap("stone_platform.png");


			break;

			case 1:

			break;


			case 2:

			break;


		}

		//win.SetFolderName("Graphics");
		//win.SetPath();
		delete dir;
}


GameObject::~GameObject(){



};

void GameObject::SetHitBox(float f_top, float f_bottom ){



}


bool GameObject::DrawHitBox(){


	return true;
}

void GameObject::DrawObject(float x, float y,float f_top, int face ){
	left = x;
	right = x + 50;
	top = f_top;
	bottom = f_top +50;
	if(platforms != 0){
		al_draw_bitmap(platforms,x,y,face);
		al_draw_filled_rectangle(left,top,right,y,al_map_rgb(250,0,0));
		//al_draw_filled_rectangle(150,451,200,500,al_map_rgb(250,0,0));
		//al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0,0,200));
	}
	else{
	//	std::cout<<"faild to load bmp :(";
	}
}

void GameObject::HitBox(){

	al_draw_filled_rectangle(50,100,100,50,al_map_rgb(250,0,0));


}
