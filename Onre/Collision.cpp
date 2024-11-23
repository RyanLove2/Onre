#include"Collision.h"



Collision::Collision(){


}

Collision::~Collision(){



};


bool Collision::Collide(Onre* player, GameObject* enemy){
//top,bottom, left,right;
//al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0,0,200));

	return true;
}

//bool Collision::CollideForGround(Onre* player,  GameObject* ground){

void Collision::CollideForGround(Onre* player, vector<GameObject*> ground){

	vector<GameObject*>::iterator it;


	for(it = ground.begin(); it != ground.end(); ++it ){
		(*it)->DrawObject();

	}

	for(it = ground.begin(); it != ground.end(); ++it ){

		//(*it)->DrawObject(); -2
		if(player->GetLeft() > (*it)->GetLeft()-10 && player->GetRight() < (*it)->GetRight()+10
		&& player->GetBottom() > (*it)->GetTop() && player->GetTop() < (*it)->GetBottom()){
			player->SetIsOnGround(true);

		//	player->SetFall(false);
			break;

		}

		else{
			player->SetIsOnGround(false);
		}


	}

	/*
	else if(player->GetTop() >= (*it)->GetTop() && player->GetRight() >= (*it)->GetLeft() && player->GetBottom() >(*it)->GetTop() ){
			player->HitAWall();

			player->SetIsOnGround(false);

		}


		else if(player->GetBottom() > (*it)->GetTop() && player->GetRight() <= (*it)->GetRight() && player->GetRight() > (*it)->GetLeft() )
	*/
		//	player->SetFall(true);


	}
