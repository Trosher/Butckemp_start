#!/bin/bash

chmod ugo+rx src/ai_door_control.sh
mv src/door_managment_fi src/door_managment_files
mkdir src/door_managment_files/door_configuration
mkdir src/door_managment_files/door_map
mkdir src/door_managment_files/door_logs
mv src/door_managment_files/*conf src/door_managment_files/door_configuration
mv src/door_managment_files/*log src/door_managment_files/door_logs
mv src/door_managment_files/*map_* src/door_managment_files/door_map
