
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include"Gravity.h"
#include"Sprite.h"

using namespace std;

class Onre :  public Gravity {


	private:
		int i,spritecounter,face ,showhitbox ;

		enum sprite_state{state_walk,state_run,state_attack,state_jump,
		state_idle,state_dead,state_hurt, state_attack3,state_attack2, state_attack1, state_flight};

		float vecx,vecy,delta,speed;

		float top,bottom, left,right;
        float mg; // wight of character
		// collision box variables
		bool collide;
		bool fall;

		bool motion;

		ALLEGRO_BITMAP *attack1[5];
		ALLEGRO_BITMAP *attack2[4];
		ALLEGRO_BITMAP *attack3[4];
		ALLEGRO_BITMAP *dead[5];
		ALLEGRO_BITMAP *flight[5];
		ALLEGRO_BITMAP *hurt[3];
		ALLEGRO_BITMAP *idle[6];
		ALLEGRO_BITMAP *run[7];
		ALLEGRO_BITMAP *scream[6];
		ALLEGRO_BITMAP *walk[7];
		ALLEGRO_BITMAP *tmp;
		ALLEGRO_PATH   *custpath;

		Gravity gr;

	public:



		float Mass(){

            return mg;
		}

		bool  Controls(Window *w){


			if(w->GetEvent().timer.source == w->GetDeltaFrame()){
				if(motion == true){
					++i;
					spritecounter = 6;
					if(i>=spritecounter-1){//7
						i=0;
					}

				}
			else if(motion == false){
					++i;
					spritecounter = 5;
				if(i>=spritecounter-1){//6
					i=0;
				}

			}
		}


		switch(w->GetEvent().keyboard.keycode){
			case ALLEGRO_EVENT_KEY_DOWN:
				case ALLEGRO_KEY_ESCAPE:
					return false;
				break;

				case ALLEGRO_KEY_LEFT:
					std::cout<<"Move left";
					motion = true;
					face = 1;


				break;

				case ALLEGRO_KEY_RIGHT:
					motion = true;
					face = 0;


				break;

				// test case for hitbox
				case ALLEGRO_KEY_T:
					showhitbox++;
					std::cout<<"SHOW HIT BOX";
				break;

				case ALLEGRO_KEY_DOWN:

				break;

				case ALLEGRO_KEY_SPACE:

				break;
			break;

			}
			//delta = w->fps;

			return true;
		}

	void ControlsUp(Window *w){
		switch(w->GetEvent().keyboard.keycode){
				case ALLEGRO_EVENT_KEY_UP:


					case ALLEGRO_KEY_LEFT:
						case ALLEGRO_KEY_RIGHT:
							motion = false;

						break;
					break;

			}

	}

	void AnimationWalk(){


	}


void ShowHitBox(){


	if(showhitbox == 1){
		al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0,0,200));//278
		//al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0,0,200));
		//void al_draw_filled_rectangle(float x1, float y1, float x2, float y2,ALLEGRO_COLOR color)
	}
	else{
		showhitbox = 0;

	}
}

void DisplaySprite(Window * w){
// this is a walk state, we need to change the data structers for jump attack and all other states.
	//	al_draw_bitmap(idle[5], vecx, vecy, face);
		delta = w->fps;
        //Setforce( delta);

		if(motion == true && face == 1){// right face

			vecx += vecx*speed-1*delta/25;
			al_draw_bitmap(walk[i], vecx, vecy, face);
			right += right*speed-1*delta/25;
			left += left*speed-1*delta/25;
		}
		else if(motion == true && face == 0){//left face

			vecx += vecx*speed+1*delta/25;
			al_draw_bitmap(walk[i], vecx, vecy, face);
			right += right*speed+1*delta/25;
			left += left*speed+1*delta/25;
		}

		if(fall == true){
		   // vecy += vecy*speed+1*delta/2;
			//al_draw_bitmap(walk[i], vecx, vecy, face);
			//top += top*speed+1*delta/2;
			//bottom += bottom*speed+1*delta/2;
            		vecy+= GravityFall(delta);
            		top += (GetAcceleration()* GetTime())*delta/60;
			bottom += (GetAcceleration()*GetTime())*delta/60;

		}


		 if(motion == false){

			al_draw_bitmap(idle[i],vecx,vecy, face);
		}
		ShowHitBox();
		//std::cout<<"Top: "<<top<<"\t";
		//std::cout<<"\n Bottom: "<<bottom<<endl;
		//std::cout<<"Left: "<<left<<"\t";
		//std::cout<<"\n Right: "<<right;

// sometimes on start up sprite disapear or go really fast
       // ++vecy;

        //std::cout<<vecy<<endl;


}


	Onre(){

		i = 0;
		showhitbox = 0;
		face = 0;
		mg = 90.8;
		motion = false;
		collide = false;
		fall = true;

		//al_draw_filled_rectangle(205, 214, 220, 278, al_map_rgb(0,0,200));
		//void al_draw_filled_rectangle(float x1, float y1, float x2, float y2,ALLEGRO_COLOR color)

		top = 214;
		bottom = 278;
		left = 205;
		right = 220;

		std::cout<<"motion: "<<motion<<std::endl;

		vecx=vecy = 150;
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
		attack2[0] = al_create_sub_bitmap(tmp, 0, 0, 128, 128);
		attack2[1] = al_create_sub_bitmap(tmp, 128, 0, 128, 128);
		attack2[2] = al_create_sub_bitmap(tmp, 256, 0, 128, 128);
		attack2[3] = al_create_sub_bitmap(tmp, 384, 0, 128, 128);
		tmp = al_load_bitmap("Attack_3.png");
		attack3[0] = al_create_sub_bitmap(tmp, 0, 0, 128, 128);
		attack3[1] = al_create_sub_bitmap(tmp, 128, 0, 128, 128);
		attack3[2] = al_create_sub_bitmap(tmp, 256, 0, 128, 128);
		attack3[3] = al_create_sub_bitmap(tmp, 384, 0, 128, 128);
		tmp = al_load_bitmap("Dead.png");
		dead[0] = al_create_sub_bitmap(tmp, 0, 0, 128, 128);
		dead[1] = al_create_sub_bitmap(tmp, 128, 0, 128, 128);
		dead[2] = al_create_sub_bitmap(tmp, 256, 0, 128, 128);
		dead[3] = al_create_sub_bitmap(tmp, 384, 0, 128, 128);
		dead[4] = al_create_sub_bitmap(tmp, 512, 0, 128, 128);
		dead[5] = al_create_sub_bitmap(tmp, 640, 0, 128, 128);
		tmp = al_load_bitmap("Flight.png");
		flight[0] = al_create_sub_bitmap(tmp, 0, 0, 128, 128);
		flight[1] = al_create_sub_bitmap(tmp, 128, 0, 128, 128);
		flight[2] = al_create_sub_bitmap(tmp, 256, 0, 128, 128);
		flight[3] = al_create_sub_bitmap(tmp, 384, 0, 128, 128);
		flight[4] = al_create_sub_bitmap(tmp, 512, 0, 128, 128);
		flight[5] = al_create_sub_bitmap(tmp, 640, 0, 128, 128);
		tmp = al_load_bitmap("Hurt.png");
		hurt[0] = al_create_sub_bitmap(tmp, 0, 0, 128, 128);
		hurt[1] = al_create_sub_bitmap(tmp, 128, 0, 128, 128);
		hurt[2] = al_create_sub_bitmap(tmp, 256, 0, 128, 128);
		tmp = al_load_bitmap("Idle.png");
		idle[0] = al_create_sub_bitmap(tmp, 0, 0, 128, 128);
		idle[1] = al_create_sub_bitmap(tmp, 128, 0, 128, 128);
		idle[2] = al_create_sub_bitmap(tmp, 256, 0, 128, 128);
		idle[3] = al_create_sub_bitmap(tmp, 384, 0, 128, 128);
		idle[4] = al_create_sub_bitmap(tmp, 512, 0, 128, 128);
		idle[5] = al_create_sub_bitmap(tmp, 640, 0, 128, 128);

		tmp = al_load_bitmap("Run.png");
		run[0] = al_create_sub_bitmap(tmp, 0, 0, 128, 128);
		run[1] = al_create_sub_bitmap(tmp, 128, 0, 128, 128);
		run[2] = al_create_sub_bitmap(tmp, 256, 0, 128, 128);
		run[3] = al_create_sub_bitmap(tmp, 384, 0, 128, 128);
		run[4] = al_create_sub_bitmap(tmp, 512, 0, 128, 128);
		run[5] = al_create_sub_bitmap(tmp, 640, 0, 128, 128);
		run[6] = al_create_sub_bitmap(tmp, 768, 0, 128, 128);
		tmp = al_load_bitmap("Scream.png");
		scream[0] = al_create_sub_bitmap(tmp, 0, 0, 128, 128);
		scream[1] = al_create_sub_bitmap(tmp, 128, 0, 128, 128);
		scream[2] = al_create_sub_bitmap(tmp, 256, 0, 128, 128);
		scream[3] = al_create_sub_bitmap(tmp, 384, 0, 128, 128);
		scream[4] = al_create_sub_bitmap(tmp, 512, 0, 128, 128);
		scream[5] = al_create_sub_bitmap(tmp, 640, 0, 128, 128);
		scream[6] = al_create_sub_bitmap(tmp, 768, 0, 128, 128);
		tmp = al_load_bitmap("Walk.png");
		walk[0] = al_create_sub_bitmap(tmp, 0, 0, 128, 128);
		walk[1] = al_create_sub_bitmap(tmp, 128, 0, 128, 128);
		walk[2] = al_create_sub_bitmap(tmp, 256, 0, 128, 128);
		walk[3] = al_create_sub_bitmap(tmp, 384, 0, 128, 128);
		walk[4] = al_create_sub_bitmap(tmp, 512, 0, 128, 128);
		walk[5] = al_create_sub_bitmap(tmp, 640, 0, 128, 128);
		walk[6] = al_create_sub_bitmap(tmp, 768, 0, 128, 128);



	}

~Onre(){
	delete this;

	}
};






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
