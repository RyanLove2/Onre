
#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_physfs.h>
#include<allegro5/allegro_primitives.h>


#include"GameObject.h"

class Collision{

	private:
		float right, left,top, bottom;


	public :
		bool Collide(Onre player, GameObject enemy);
		bool CollideForGround(Onre player, GameObject ground);
		Collision();
		~Collision();

};
