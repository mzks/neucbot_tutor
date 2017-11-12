#!/bin/bash

echo This is a shell script to help lecture.

git clone https://github.com/shawest/neucbot.git
mv neucbot ../neucbot
cd ..
mv neucbot_tutor neucbot
cd neucbot
cd Data/Isotopes
git clone https://github.com/neucbot-datasets/fe.git
tar xzf fe/Fe.tar.gz 
cd ../../
echo fe 0 100 > Materials/Iron.dat
cat Materials/Iron.dat               
./neucbot.py -c Chains/U238upperChain.dat -m Materials/Iron.dat -o iron_u.dat

