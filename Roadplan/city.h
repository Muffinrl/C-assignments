#ifndef _CITY_H_
#define _CITY_H_

typedef struct city City;

#include "road.h"

struct city
{
	char	*name;
	Road	*roads;
	City	*next;
};


City *new_city (char *name);
void delete_city (City *city);
City *find_city (City *map, char *name);

#endif /*_CITY_H_ */
