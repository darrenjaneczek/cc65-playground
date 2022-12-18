#!/bin/sh

echo Creating destination...
mkdir /src_copy

function copy_and_build {
  cp -urv /src/* /src_copy
  make -C /src_copy
}



inotifywait -e close_write,moved_to,create -m /src --exclude \.o$| 
while read -r directory events filename; 
do
  echo "Detected change in ${filename}. Rebuild!";
  copy_and_build  
  echo "Done-----------------"
  
done