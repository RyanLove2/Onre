
#include<allegro5/allegro.h>
#include"Window.h"

class Player{



};


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
}
