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

void update_mechanisms(){
    update_clamp('A', pros::E_CONTROLLER_DIGITAL_L1, pros::E_CONTROLLER_DIGITAL_L2);

}

