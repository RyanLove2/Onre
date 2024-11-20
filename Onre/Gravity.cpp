#include"Gravity.h"


Gravity::Gravity(){
	accel = 9.8;
	time = .55;
}


Gravity::~Gravity(){


};


float Gravity::GetAcceleration(){

	return accel;
}

float Gravity::GetTime(){
	return time;
}

float Gravity::GravityFall(float delta){
// force = accel*delta-1;
    //force=force +1;
    /*
	if !is_on_floor():
		time = time + 0.55 #4.1
		velocity.y = gravity * time
		on_the_ground = false
        */
		return	accel*.55;
}
