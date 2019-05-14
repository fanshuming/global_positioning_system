#ifndef __NIIC__GPS__H__
#define __NIIC__GPS__H__

/*
* function discription: start gps time correct
* args:
* returns: o means success, 1 means fail.
*/
int start_gps_correct_time();

/*
* function discription: stop gps time correct
* args:
* returns: o means success, 1 means fail.
*/

int stop_gps_correct_time();

/*
* function discription: get gps time correct programe run status
* args:run_status, 1 means gps correct time programe is running, 0 means gps correct time programe is not running
* returns: o means success, 1 means fail.
*/

int gps_correct_time_status(int * run_status);

#endif
