#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "log.h"

/*
* function discription: start gps time correct
* args:
* returns: o means success, 1 means fail.
*/

int start_gps_correct_time()
{
	int ret = 0;

	ret = system("/usr/bin/gps_correct_time start");
	return ret;

}

/*
* function discription: stop gps time correct
* args:
* returns: o means success, 1 means fail.
*/

int stop_gps_correct_time()
{
	int ret = 0;

	ret = system("/usr/bin/gps_correct_time stop");

	return ret;
}

/*
* function discription: get gps time correct programe run status
* args:run_status, 1 means gps correct time programe is running, 0 means gps correct time programe is not running
* returns: o means success, 1 means fail.
*/

int gps_correct_time_status(int * run_status)
{
	int ret = 0;
	FILE *fp = NULL;
	char data[10] = {0};
	char pidvalue[10] = {0};
	int pidv = 0;

	if(NULL == run_status){
		LOG(ERROR, "run_status is null");
		return 1;
	}

	fp = popen("/bin/pidof ntpd", "r");
	if(NULL == fp){
		LOG(ERROR, "popen fail.");
		return 1;
	}

	while(fgets(data, sizeof(data), fp) != NULL)
	{
		strncpy(pidvalue, data, strlen(data));
		LOG(DEBUG, "pidvalue:%s\n",pidvalue);
		pidv = atoi(pidvalue);
		LOG(DEBUG, "pidv:%d\n",pidv);

		if(pidv > 0){
			*run_status = 1;
		}else{
			*run_status = 0;
		}
	}
	
	if(strlen(pidvalue) < 1){
			*run_status = 0;
	} 
	LOG(DEBUG, "run status:%d\n", *run_status);
	pclose(fp);

	return ret;
}
