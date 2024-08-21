#include "main.h"

DriveController chassis(10,11,12,13,14,15,2.75);




/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	chassis.clear();
	pros::c::motor_tare_position(lift_motor);
	pros::c::adi_digital_write(clamp_port, false);
	
	pros::c::screen_erase();
	pros::c::screen_print(pros::E_TEXT_MEDIUM, 0, "2131Y Ver 0.1");
	
	
	
	
	
	
	
	
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {
	while (true){
		
		chassis.update(DriveController::TANK);
		update_mechanisms();
		pros::c::screen_print(pros::E_TEXT_MEDIUM, 1, "Auton Selected: (N/A) You Should Program");
		pros::c::screen_print(pros::E_TEXT_MEDIUM, 2, "Lift Encoder Pos: %f", pros::c::motor_get_position(lift_motor));
		bool clamp_status = pros::c::adi_digital_read(clamp_port);
		
		pros::c::screen_print(pros::E_TEXT_MEDIUM, 3, "Clamp Status: %d", clamp_status);
		pros::c::screen_print(pros::E_TEXT_MEDIUM, 4, "Left Avg: %f", pros::c::motor_get_position(11));
		pros::c::screen_print(pros::E_TEXT_MEDIUM, 5, "Right Avg: %f", pros::c::motor_get_position(14));
		

		pros::delay(20);
		
		
		
	}
}