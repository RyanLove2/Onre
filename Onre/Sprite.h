#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include"Window.h"

class Sprite {


	private:

		ALLEGRO_BITMAP * attack1[5];
		ALLEGRO_BITMAP * attack2[5];
		ALLEGRO_BITMAP * attack3[5];
		ALLEGRO_BITMAP * dead[5];
		ALLEGRO_BITMAP * flight[5];
		ALLEGRO_BITMAP* hurt[5];
		ALLEGRO_BITMAP * idle[5];
		ALLEGRO_BITMAP * run[5];
		ALLEGRO_BITMAP * scream[5];
		ALLEGRO_BITMAP* walk[5];
		ALLEGRO_BITMAP* tmp;

		ALLEGRO_PATH* custpath;


	public:
		bool  Controls(Window* window);
		void AnimationWalk();
		void DisplaySprite();
		Sprite();
		~Sprite();





};
