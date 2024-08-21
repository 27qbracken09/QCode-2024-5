#include "main.h"

void update_clamp_toggle(char pnumatic_port, pros::controller_digital_e_t Controller_button){
    bool toggle = false;
    if (pros::c::controller_get_digital_new_press(pros::E_CONTROLLER_MASTER, Controller_button)){
        if (toggle){
            toggle = false;
            pros::c::adi_digital_write(pnumatic_port,toggle);

        }
        else {
            toggle = true;
            pros::c::adi_digital_write(pnumatic_port, toggle);
        }
    }
}

void update_clamp(char pnumatic_port, pros::controller_digital_e_t Controller_button_clamp, pros::controller_digital_e_t Controller_button_unclamp){
    if (pros::c::controller_get_digital_new_press(pros::E_CONTROLLER_MASTER, Controller_button_clamp)) pros::c::adi_digital_write(pnumatic_port, true);
    if (pros::c::controller_get_digital_new_press(pros::E_CONTROLLER_MASTER, Controller_button_unclamp)) pros::c::adi_digital_write(pnumatic_port, false);

}

void update_lift(int lift_port, float lift_max, pros::controller_digital_e_t Controller_button_up, pros::controller_digital_e_t Controller_button_down){
    if (pros::c::controller_get_digital_new_press(pros::E_CONTROLLER_MASTER, Controller_button_up)) pros::c::motor_move_absolute(lift_port, lift_max, 100);
    if (pros::c::controller_get_digital_new_press(pros::E_CONTROLLER_MASTER, Controller_button_down)) pros::c::motor_move_absolute(lift_port, 0, 100);
}

void update_intake(int intake_port, float max_speed, pros::controller_digital_e_t Controller_Intake, pros::controller_digital_e_t Controller_Outtake){
    if (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, Controller_Intake)) pros::c::motor_move(intake_port, max_speed);
    if (!pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, Controller_Intake)) pros::c::motor_move(intake_port, 0);
   // if (!pros::c::controller_get_digital_new_press(pros::E_CONTROLLER_MASTER, Controller_Intake)) pros::c::motor_move(intake_port, 0);
    if (pros::c::controller_get_digital(pros::E_CONTROLLER_MASTER, Controller_Outtake)) pros::c::motor_move(intake_port, -max_speed);
    //if (!pros::c::controller_get_digital_new_press(pros::E_CONTROLLER_MASTER, Controller_Outtake)) pros::c::motor_move(intake_port, 0);
}

void update_mechanisms(){
    update_clamp(clamp_port, pros::E_CONTROLLER_DIGITAL_L2, pros::E_CONTROLLER_DIGITAL_L1);
    update_lift(lift_motor, 200, pros::E_CONTROLLER_DIGITAL_UP, pros::E_CONTROLLER_DIGITAL_DOWN);
    update_intake(intake_motor, 1200, pros::E_CONTROLLER_DIGITAL_R1, pros::E_CONTROLLER_DIGITAL_R2);
    
}


