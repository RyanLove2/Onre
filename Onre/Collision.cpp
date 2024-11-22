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
	bool isonfloor;

	for(it = ground.begin(); it != ground.end(); ++it ){
		(*it)->DrawObject();
		++it;
	}

	for(it = ground.begin(); it != ground.end(); ++it ){

		//(*it)->DrawObject();
		if(player->GetLeft() > (*it)->GetLeft()-2 && player->GetRight() < (*it)->GetRight()+10
		&& player->GetBottom() > (*it)->GetTop() && player->GetTop() < (*it)->GetBottom()){
			player->SetIsOnGround(true);

		//	player->SetFall(false);
			break;

		}
		else{
			player->SetIsOnGround(false);
		}


		}


		//	player->SetFall(true);


	}


/*






	for(it = ground.begin(); it != ground.end(); ++it ){

		//(*it)->DrawObject();
		if(player->GetLeft() > (*it)->GetLeft()-2 && player->GetRight() < (*it)->GetRight()+5
		&& player->GetBottom() > (*it)->GetTop() && player->GetTop() < (*it)->GetBottom()){

			isonfloor = false;
			player->SetFall(isonfloor);
			//return;
			break;
			//std::cout<<"landed: ";
			//
		}
		++it;
		isonfloor = true;

	}
	cout<<"ISONFLOOR: "<<isonfloor;

	player->SetFall(isonfloor);
	return;

















*/
//top,bottom, left,right;
//al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0,0,200));
	//	bool finalground = true;
/*
		std::cout<<"Player Left: "<<player->GetLeft()<<std::endl;
		std::cout<<"Ground Left: " <<ground->GetLeft()<<std::endl;
		std::cout<<"Ground Right: " <<ground->GetRight()<<std::endl;
		std::cout<<"Player Right: " <<player->GetRight()<<std::endl;


	bool finalground;

	if(player->GetLeft() > ground->GetLeft()-2 && player->GetRight() < ground->GetRight()+5
				&& player->GetBottom() > ground->GetTop() && player->GetTop() < ground->GetBottom()){
			//	std::cout<<"Right and left is greater then other one"<<std::endl;
			//	player->SetFall(false);
				finalground = false;
				player->SetFall(false);
				player->onground = true;
			//cout<<"On Ground "<<endl;
				//return finalground;
			}
			else{
				//player->SetFall(true);
			//	player->onground = false;
				player->onground = false;

			}






	return finalground;
*/



