#pragma once //Make sure file is not recursivly added as main.h will include this file
#include "main.h" //Include everything else throughout the pros project

//Drivetrain Controller class
class DriveController{

    public:

        //Initial Drivetrain will be 4 motor with 2.75" wheels, however will leave wheels configurable and no odom
        DriveController(int L1, int L2, int R1, int R2, float wheel_diameter);

        //Move voltage command for fine grained control of each motor if nessisary.
        void move_voltage(float L1_Volt, float L2_Volt, float R1_Volt, float R2_Volt);

        //Update drivemethod, motor speeds based on joy position, and potentially log telem data
        void update(int DriveMethod);

        enum DRIVEMETHOD{NONE, TANK, ARCADE_L, ARCADE_R, SPLIT_L_DOM, SPLIT_R_DOM};

    private:
        //Stored constants from DriveController Constructor
        int l1_port;
        int l2_port;
        int r1_port;
        int r2_port;
        float wheel_diameter;

        /* Still needs work for fully usable joystick area
        const double curve_modifier = 0.00006742218892;
        const float deadband = 5;
        const float static_volt = 2;
        */

        //Private calculation functions to make code neater
        void set_motor_speed_tank();
        void set_motor_speed_arcade_l();
        void set_motor_speed_arcade_r();
        void set_motor_speed_spit_l_dom();
        void set_motor_speed_split_r_dom();
    


};
