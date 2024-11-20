
#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_physfs.h>
#include<allegro5/allegro_primitives.h>

#include"Onre.cpp"
#include"GameObject.h"

class Collision :  public Onre{

	private:
		float right, left,top, bottom;


	public :
		bool Collide(Onre player, Sprite enemy);
		bool CollideForGround(Onre player, GameObject ground);
		Collision();
		~Collision();

};
