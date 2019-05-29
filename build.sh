#!/bin/bash
sudo rmmod 007 2>/dev/null
make test
if [ $? != 0 ]; then
            printf "Error when executing command: make"
fi
