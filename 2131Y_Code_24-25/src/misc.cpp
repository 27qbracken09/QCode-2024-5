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


void update_mechanisms(){
    update_clamp('A', pros::E_CONTROLLER_DIGITAL_L2, pros::E_CONTROLLER_DIGITAL_L1);
    update_lift(10, 200, pros::E_CONTROLLER_DIGITAL_UP, pros::E_CONTROLLER_DIGITAL_DOWN);
    
}


