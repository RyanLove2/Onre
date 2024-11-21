#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_opengl.h>
#include<allegro5/allegro_physfs.h>
#include<allegro5/allegro_primitives.h>


#include"GameObject.h"


using namespace std;




void StartUpLibraries(){
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_native_dialog_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();
	al_install_joystick();
	al_install_audio();



}

void LevelOneCreate(){



}

int main(int argc, char* argv[]){
	StartUpLibraries();
	bool run = true;


	if(!al_init()){
		//cout<<"ALLEGRO5 failed to start"<<endl;
		return -1;
	}
	if(!al_init_image_addon()){
	//	cout<<"al_init faild to be loaded";
		return -1;
	}



	Window *window = new Window();
	window->Win_handlePath();
	Onre *player = new Onre();
	GameObject* land = new GameObject(0);


	while(run == true){
		al_wait_for_event(window->GetEventQue(),&window->GetEvent());
		switch(window->GetEvent().type){
			case ALLEGRO_EVENT_TIMER:
				window->render = true;




				case ALLEGRO_EVENT_KEY_DOWN:// later move this to player code

					run = player->Controls(window);
				break;



				case ALLEGRO_EVENT_KEY_UP:
					player->ControlsUp(window);
				break;

				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					run = false;
				break;

			break;

		}

		if(window->render == true && al_is_event_queue_empty(window->GetEventQue())){

			al_clear_to_color(al_map_rgb(0,140,0));
			//al_draw_filled_rectangle(150, 452, 750, 500, al_map_rgb(120,40,200));
			land->DrawObject(150,450,451,0);//150 451
			//void al_draw_filled_rectangle(float x1, float y1, float x2, float y2,ALLEGRO_COLOR color)
			player->DisplaySprite(window);


			al_flip_display();
			window->render = false;

		}

	}


	//delete window;
	//delete player;

	return 0;
}
