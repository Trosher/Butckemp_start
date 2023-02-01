#!/bin/bash

read -p 'Ведите путь к файлу от корневой паки' file_name
read -p 'Ведите строку которую хотите заменить' str_replase
read -p 'Ведите значение которое заменит строку' replase
cd ..
sed -i'.bak'"s/&str_replase/&replase/g" $file_name
size= "$(stat -c %s $file_name)"
data_time= ($(stat -c "%y" -t '%Y-%m-%d %H:%M' $file_name))
sha_sum= ($(shasum -a 256 $file_name | cat -d' ' -f1))
echo $size
echo $data_time
echo $sha_sum
