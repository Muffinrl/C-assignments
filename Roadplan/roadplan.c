/* 
 * Student: J. van der Geize
 * Number: 5462290
 * Assignment: 5.1 + 5.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "salloc.h"
#include "city.h"
#include "road.h"

#define MAX_STRING_LENGTH 100


/*
 * Locate city with name city_name on the map
 */
City *find_city (City *list_of_cities, char *city_name)
{
	City *c = list_of_cities;
	while (c != NULL)
	{
		if (strcmp (c->name, city_name) == 0)
			return c;

		c = c->next;
	}
	return NULL;
}


/*
 * Delete a map
 */
static void delete_map (City *map)
{
	City *map_copy;

	while (map != NULL)
	{
		map_copy = map;
		map = map->next;
		delete_city (map_copy);
	}
}


/*
 * Build the map datastructure
 */
static City *create_map (FILE *data_file)
{
	int num_of_cities, num_of_roads, i;

	City *map = NULL;

	/* Read in city-names	*/
	fscanf (data_file, "%d", &num_of_cities);

	for (i = 0; i < num_of_cities; i++)
	{
		char city_name[MAX_STRING_LENGTH + 1];
		City *city;
		City *c;

		fscanf(data_file, "%s", city_name);

		if(find_city (map, city_name) != NULL)
		{
			fprintf(stderr, "City %s already on the map\n", city_name);
			delete_map(map);
			exit(EXIT_FAILURE);
		}

		city = new_city(safe_strdup (city_name));

		if(map == NULL) {
			map = city;
		} else {
			c = map;
			while (c->next) {
				c = c->next;
			}
			/* Append new city */
			c -> next = city;
		}
	}

       	/* (Assignment 5.1)
         * Read number of roads
		 *	
         * For each road:
         *    Read origin city name, destination city name and length
         *    Find pointers to orgin city structure and destination city structure
	 	 *    using the function find_city()
         *    Create new road structure using new_road() function
         *    Add it to the list of roads of the origin city.
         */
	
	/* Read number of roads */
	fscanf(data_file, "%d", &num_of_roads);

	for(i = 0; i < num_of_roads; i++) {
		/* Initialise values */
		City *begin_city, *end_city;
		Road *r, *r_b;
		char origin_name[MAX_STRING_LENGTH + 1], destination_name[MAX_STRING_LENGTH + 1];
		int len;

		/* Scan for the values: origin_name, destination_name, len */
        fscanf (data_file, "%s", origin_name);
        fscanf (data_file, "%s", destination_name);
        fscanf (data_file, "%d", &len);

		begin_city = find_city(map, origin_name);
		end_city = find_city(map, destination_name);

		/* Check for NULL values, if the city doesn't exist, exit. */
		if(begin_city == NULL) {
			fprintf(stderr, "Cannot find city %s on the map\n", origin_name);
            delete_map(map);
            exit(EXIT_FAILURE);
		}

		if(end_city == NULL) {
			fprintf(stderr, "Cannot find city %s on the map\n", destination_name);
           	delete_map(map);
            exit(EXIT_FAILURE);
		}

		/* Create a new Road *r */
		r = new_road(begin_city, end_city, len);

		/* If the origin city doesn't have any roads, so if roads == NULL, add r to roads. */
		if(begin_city->roads == NULL) {
			begin_city->roads = r;
		} else {
			/* If it has atleast 1 road already, iterate through them and append r at the end. */
			r_b = begin_city->roads;
			while (r_b->next) {
				r_b = r_b->next;
			}
			r_b->next = r;
		}
	}

	return map;
}


static void print_city_roads (City *map)
{
	City *city;
	Road *road;

	for (city = map; city != NULL; city = city->next)
	{
		printf ("Roads from city %s:\n", city->name);

		for (road = city->roads; road != NULL; road=road->next) {
			printf ("   to city %s", road->destination->name); 
			printf (" (length %d)\n", road->length); 
		}
	}
}


static void find_shortest_roads (City *map)
{
	/* (Assignment 5.2)
     * 	While input and input != "0"
	 *  Find pointer to specified city using find_city()
	 *  Visit the roads originating from this city, 
     *  and find the road that has the shortest length
	 *  Print the destination city and the road length.
	 */

	char city_name[MAX_STRING_LENGTH + 1];
	City *target_city;
	Road *shortest, *roads;

	/* Loop until input = 0 */
	fscanf(stdin, "%s", city_name);

	while(strcmp(city_name, "0") != 0) {
		shortest = NULL;

		/* target_city == NULL means the city specified isn't valid. */
		target_city = find_city(map, city_name);
		if(target_city == NULL) {
			printf("City %s not on map\n", city_name);
			fscanf(stdin, "%s", city_name);	
			continue;
		}

		/* Iterate over roads, reassigning the value for shortest everytime a road.len < shortest.len */
		roads = target_city->roads;
		while(roads) {
			if (shortest == NULL || roads->length < shortest->length) 
				shortest = roads;
			roads = roads->next;
		}

		/* shortest == NULL means there are no roads. */
		if(shortest == NULL) {
			printf("There is no road from city %s\n", city_name);
			fscanf(stdin, "%s", city_name);	
			continue;
		}

		printf("Shortest road from city %s is to city %s: %d\n", shortest->origin->name, shortest->destination->name, shortest->length);
		fscanf(stdin, "%s", city_name);	
	}
}


int main (int argc, char *argv[])
{
	FILE *data_file = NULL;
	City *map = NULL;

	/* Check arguments		*/
	if (argc != 2)
	{
		fprintf (stderr, "Usage: %s <datafile>\n", argv[0]);
		exit (EXIT_FAILURE);
	}

	/* Open data-file		*/
	if ((data_file = fopen (argv[1], "r")) == NULL)
	{
		fprintf (stderr, "Error opening file <%s>\n", argv[1]);
		exit (EXIT_FAILURE);
	}

	/* Create map-data-structure	*/
	if ((map = create_map (data_file)) == NULL)
	{
		fprintf (stderr, "No map data found\n");
		exit (EXIT_FAILURE);
	}

	print_city_roads (map);

	find_shortest_roads (map);

	/* Outit			*/
	if (data_file != NULL)
		fclose (data_file);
	if (map != NULL)
		delete_map (map);

	return EXIT_SUCCESS;
}
