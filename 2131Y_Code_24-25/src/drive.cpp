#include "main.h"



using namespace pros::c; //For convenience - I don't have to type out pros::c every time
DriveController::DriveController(int L1, int L2, int R1, int R2, float Wheel_Diameter)
{
    l1_port = L1;
    l2_port = L2;
    r1_port = R1;
    r2_port = R2;
    wheel_diameter = Wheel_Diameter;

}

void DriveController::move_voltage(float L1_Volt, float L2_Volt, float R1_Volt, float R2_Volt){
    motor_move(l1_port, L1_Volt);
    motor_move(l2_port, L2_Volt);
    motor_move(r1_port, R1_Volt);
    motor_move(r2_port, R2_Volt);
}

void DriveController::update(int DriveMethod){

    //DriveMethod has 5 options - refer to DRIVEMETHOD ENUM
    switch(DriveMethod){
        case NONE:
            break;
        
        case TANK:
            //Calculate Motor velocity based on joy pos
        

    }
    return;

}

void DriveController::set_motor_speed_tank(){

    //Get Y value from left stick
    int left = controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_LEFT_Y);

   //Check if joy is above or below deadband threshold | This still needs work, commented out for now
   //if (left > deadband) left = ((pow(left-deadband, 3)*3)*curve_modifier)+static_volt;
   //else if (left < -deadband) left = ((pow(left+deadband, 3)*3)*curve_modifier)-static_volt;
   //else if (left < deadband & left > -deadband) left = 0;
   

    //Apply value to left motors
    motor_move(l1_port, left);
    motor_move(l2_port, left);

    //Repeat for right
    int right = controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    //Check if joy is above or below deadband threshold | This still needs work, commented out for now
    //if (right > deadband) right = ((pow(right-deadband, 3)*3)*curve_modifier)+static_volt;
    //else if (right < -deadband) right = ((pow(right+deadband, 3)*3)*curve_modifier)-static_volt;
    //else if (right < deadband & right > -deadband) right = 0;

    motor_move(r1_port, right);
    motor_move(r2_port, right);


}