#include "main.h"

//Written assuming primary use in drivetrain, though entirely usable for anyother subsystem

PID::PID(double P, double I, double D){
    p = P;
    i = I;
    d = D;
}
PID::PID(double P, double I, double D,int Timeout, float Error, float Cap, float Start_I){
    p = P;
    i = I;
    d = D;
    timeout = Timeout;
    error = Error;
    cap = Cap;
    start_i = Start_I;
}

void PID::set(double P, double I, double D,int Timeout, float Error, float Cap, float Start_I){
            p = P;
            i = I;
            d = D;
            timeout = Timeout;
            error = Error;
            cap = Cap;
            start_i = Start_I;
        }

void PID::set(double P, double I, double D){
            p = P;
            i = I;
            d = D;
            
        }

void PID::set(int Timeout,float Error, float Cap, float Start_I){
            timeout = Timeout;
            error = Error;
            cap = Cap;
            start_i = Start_I;
        }


double PID::calculate(float error){
            double p_portion = error*p;
            double d_portion = (error-prev_error)*d;

            if (error < start_i & start_i != -1) prev_i += error;
            double i_portion = prev_i*i;

            return (p_portion+i_portion+d_portion);

            

            
}


    


