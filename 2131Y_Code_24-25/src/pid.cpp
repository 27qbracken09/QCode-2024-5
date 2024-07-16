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


double PID::calculate(float Error){
            double p_portion = Error*p;
            double d_portion = (Error-prev_error)*d;

            if (Error < start_i & start_i != -1) prev_i += Error;
            double i_portion = prev_i*i;

            prev_error = error;

            return (p_portion+i_portion+d_portion);

            

            
}

void PID::tune(int M1, int M2, int M3, int M4, int M5, int M6){
    bool run = true;
    int selected = 0;
    pros::c::controller_clear(pros::E_CONTROLLER_MASTER);
    while(run){

        char p_en = '*';
        char i_en = '-';
        char d_en = '-';

        

        

        pros::c::controller_print(pros::E_CONTROLLER_MASTER, 0,0, "P: %f", p);
        pros::c::controller_print(pros::E_CONTROLLER_MASTER, 1,0, "I: %f", i);
        pros::c::controller_print(pros::E_CONTROLLER_MASTER, 2,0, "D: %f%i", d, selected);
        
        if (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_A)) {
            
            selected++;
            if (selected > 2) selected = 0;

             while (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_A)) pros::delay(10);

           

        }
         

        if (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_UP)) {
            
            
            
            
            switch (selected){
                case 0:
                    p+=0.0001;
                    break;
                
                case 1:
                    i+=0.00001;
                    break;

                case 2:
                    d+=0.0001;
                    break;
            }
            pros::c::controller_clear(pros::E_CONTROLLER_MASTER);
            while (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_UP)) pros::delay(10);
        
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
            pros::c::controller_clear(pros::E_CONTROLLER_MASTER);
            while (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_DOWN)) pros::delay(10);
        
        }

        if (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_UP)) {
            DriveController test_chassis(1,2,3,4,5,6,2.75);
            test_chassis.move(6);
        }
        
        
    }
}
    