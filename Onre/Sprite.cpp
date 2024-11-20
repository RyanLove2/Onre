
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include"Sprite.h"

 bool Sprite::Controls(Window* w){


 return true;
}


void Sprite::AnimationWalk(){


}

	Sprite::Sprite(){
	/*
		custpath = al_create_path("");
		al_append_path_component(custpath,"Onre");
		al_change_directory(al_path_cstr(custpath,ALLEGRO_NATIVE_PATH_SEP));
		std::cout<<al_get_current_directory();

		tmp = al_load_bitmap("Attack_1.png");
		attack1[0] = al_create_sub_bitmap(tmp, 0, 0, 128, 128);
		attack1[1] = al_create_sub_bitmap(tmp, 128, 0, 128, 128);
		attack1[2] = al_create_sub_bitmap(tmp, 256, 0, 128, 128);
		attack1[3] = al_create_sub_bitmap(tmp, 384, 0, 128, 128);
		attack1[4] = al_create_sub_bitmap(tmp, 512, 0, 128, 128);
		tmp = al_load_bitmap("Attack_2.png");
		*/


	}

Sprite::~Sprite(){
		delete this;

};

	void Sprite::DisplaySprite(){
		al_draw_bitmap(attack1[4], 100, 100, 0);
	}






/*
bool static Controls(Window *w){

	switch(w->GetEvent().keyboard.keycode){

		case ALLEGRO_KEY_ESCAPE:
			return false;
		break;

		case ALLEGRO_KEY_LEFT:
			std::cout<<"Move left";
		break;

		case ALLEGRO_KEY_RIGHT:

		break;

		case ALLEGRO_KEY_DOWN:

		break;

		case ALLEGRO_KEY_SPACE:

		break;

		}

	return true;
}*/
