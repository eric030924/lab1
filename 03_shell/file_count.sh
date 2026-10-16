#!/bin/bash

count=$(ls -l | grep -c '^-')

echo "File count: $count"
