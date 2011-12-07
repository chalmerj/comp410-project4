#!/usr/pkg/bin/bash

echo "Taking Service Down"
service down time
echo "Running Make"
make && make install
echo "Taking Service Up"
service up /usr/sbin/time -dev /dev/time
