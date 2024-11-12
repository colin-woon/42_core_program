dpkg -l | grep xorg >> versions.txt
dpkg -s libxext-dev | grep Version >> versions.txt
dpkg -s libbsd-dev | grep Version >> versions.txt
dpkg -s libx11-dev | grep Version >> versions.txt
