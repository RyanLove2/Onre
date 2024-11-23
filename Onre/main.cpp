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

#include"Collision.h"



using namespace std;

vector<GameObject*> plat;



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
	float x = 150;
	float y =  450;
	float m = 451;
	//GameObject* l;
	for(int i = 0; i < 10; ++i){
		GameObject* l = new GameObject();
		l->CreatePlatforms(0);
		l->SetDrawObject(x=x+50,y,m,0);
		//plat.push_back(l);
	}
	//return l;
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


	window->SetFolderName("../Land");
	window->SetPath();
	/*
	GameObject* land = new GameObject();
	GameObject* land1 = new GameObject();
	GameObject* land2 = new GameObject();
	GameObject* land3 = new GameObject();
	GameObject* land4 = new GameObject();
	*/

	GameObject* land = new GameObject();
	GameObject* land1 = new GameObject();
	GameObject* land2 = new GameObject();
	GameObject* land3 = new GameObject();
	GameObject* land4 = new GameObject();
	GameObject* land5 = new GameObject();
	GameObject* land6 = new GameObject();
	GameObject* land7 = new GameObject();

	land->CreatePlatforms(0);
	land1->CreatePlatforms(0);
	land2->CreatePlatforms(0);
	land3->CreatePlatforms(0);
	land4->CreatePlatforms(0);
	land5->CreatePlatforms(0);
	land6->CreatePlatforms(0);
	land7->CreatePlatforms(0);

	land->SetDrawObject(200,450,451,0);
	land1->SetDrawObject(250,450,451,0);
	land2->SetDrawObject(300,450,451,0);
	land3->SetDrawObject(350,450,451,0);
	land4->SetDrawObject(400,450,451,0);
	land5->SetDrawObject(450,450,451,0);
	land6->SetDrawObject(500,450,451,0);
	land7->SetDrawObject(550,450,451,0);

	vector<GameObject*>::iterator it;
	plat = {land,land1,land2,land3,land4,land5,land6,land7};
	//cout<<plat.size();


	//LevelOneCreate();
	//plat.push_back(LevelOneCreate());
	//GameObject* land2 = new GameObject();
	Collision* BoxCollision = new Collision();






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

			//for(auto item: plat){

			//land->DrawObject(200,450,451,0);

			//


			BoxCollision->CollideForGround(player , plat);
			/*
		for(it = plat.begin(); it != plat.end(); ++it ){
				(*it)->DrawObject();
				cout<<1<<endl;
			}
			*/

			player->DisplaySprite(window);










			al_flip_display();
			window->render = false;

		}

	}


	//delete window;
	//delete player;

	return 0;
}
