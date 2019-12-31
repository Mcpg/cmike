#!/bin/bash

# load_with_mikeos_software.sh
# Downloads MikeOS 4.6.1 and copies its software into
# cmike.flp in current working directory.
#
# Might be useful if you want to be able to do *something*
# with the kernel, since built in software is pretty much
# useless at the moment :^)
#
# Requirements:
#  - wget
#  - unzip
#  - mtools (mcopy)
#  - nasm to build MikeOS programs

# Download and unzip MikeOS
wget http://mikeos.sourceforge.net/mikeos-4.6.1.zip
unzip mikeos-4.6.1.zip

# Build the software

cd mikeos-4.6.1/programs

for i in *.asm; do
    nasm -O0 -w+orphan-labels -f bin $i -o `basename $i .asm`.bin || exit
done

cd ../..

# Copy the binaries
mcopy -i cmike.flp mikeos-4.6.1/programs/**.bin ::/

# Remove temporary files
rm -rf mikeos-4.6.1
rm mikeos-4.6.1.zip
