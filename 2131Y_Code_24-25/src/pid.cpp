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

void PID::tune(int M1, int M2, int M3, int M4, int M5, int M6){
    bool run = true;
    while(run){

        char p_en = '*';
        char i_en = '-';
        char d_en = '-';

        int selected = 0;

        pros::c::controller_clear(pros::E_CONTROLLER_MASTER);

        pros::c::controller_print(pros::E_CONTROLLER_MASTER, 1,1, "P: %f1.6 %s", p, p_en);
        pros::c::controller_print(pros::E_CONTROLLER_MASTER, 2,1, "I: %f1.6 %s", i, i_en);
        pros::c::controller_print(pros::E_CONTROLLER_MASTER, 3,1, "D: %f1.6 %s", d, d_en);

        if (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_A)) {
            selected++;
            if (selected > 2) selected = 0;

            switch (selected){
                case 0: 
                    p_en = '*';
                    i_en = '-';
                    d_en = '-';

                case 1:
                    p_en = '-';
                    i_en = '*';
                    d_en = '-';
                
                case 2:
                    p_en = '-';
                    i_en = '-';
                    d_en = '*';


            }

        }

        if (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_UP)) {
            switch (selected){
                case 0:
                    p+=0.0001;
                    break;
                
                case 1:
                    i+=0.00001;

                case 2:
                    d+=0.0001;
            }
        
        }

        if (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_DOWN)) {
            switch (selected){
                case 0:
                    p-=0.0001;
                    break;
                
                case 1:
                    i-=0.00001;

                case 2:
                    d-=0.0001;
            }
        
        }
        
    }
}
    


