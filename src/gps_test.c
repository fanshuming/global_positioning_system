#include "log.h"
#include "gps.h"
#include <unistd.h>

int main()
{
	int run_status = 0;
//1. start gps correct time program
	start_gps_correct_time();
	sleep(3);
//2. check the gps correct time program is running or not
	gps_correct_time_status(&run_status);
	LOG(DEBUG,"GPS correct time is run 1 or not 0   :  %d\n", run_status);
//3. stop gps correct time program
	stop_gps_correct_time();

//4. check the gps correct time program is running or not agin
	gps_correct_time_status(&run_status);
	LOG(DEBUG,"GPS correct time is run 1 or not 0   :  %d\n", run_status);
}
