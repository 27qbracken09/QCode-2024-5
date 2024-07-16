#pragma once
#include "main.h"


class PID{
    public:

        //Overloaded constructor to give many options
        PID(double P, double I, double D);
        PID(double P, double I, double D,int Timeout, float Error, float Cap, float Start_I);


        void set(double P, double I, double D);
        void set(int Timeout, float Error, float Cap, float Start_I);
        void set(double P, double I, double D,int Timeout, float Error, float Cap, float Start_I);

        double calculate(float error);
    
    private:

        //Basic PID variables
        double p = 0.00;
        double i = 0.00;
        double d = 0.00;

        //Additional PID variables
        int timeout = -1; //-1 is disabled - time in msec
        float error = 1; //Error in degrees
        float cap = 12; //Motor voltage cap to limit speed - in volts
        float start_i = -1; //-1 means that integral is not used - how close to target in degrees before starting integral

        float prev_error = 0;
        float prev_i = 0;


};