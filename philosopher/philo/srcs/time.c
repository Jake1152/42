#include "philo_struct.h"
#include <sys/time.h>

int current_time_returner(struct timeval cur_time_val)
{
	if (gettimeofday(&cur_time_val, NULL) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}