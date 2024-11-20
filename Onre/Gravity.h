#include<iostream>


class Gravity{

    private:
        float force;
        float mass;
        float accel;
        float time;

        //force = (Mass * acceleration) * delta

    public:
        float GravityFall(float delta);
        float GetAcceleration();
        float GetTime();

        Gravity();
        ~Gravity();

};
