#!/bin/bash

# $DISK_ROOT_DIRECTORY
# $FLOPPY_IMG_PATH

if [ "$EUID" -ne 0 ]; then
    echo "ERROR: Only root can do that!"
    exit 1
fi

dd if=/dev/zero of=$FLOPPY_IMG_PATH bs=512 count=2880
dd if=$PROJECT_ROOT_DIR/bootloader/bootload.bin of=$FLOPPY_IMG_PATH bs=512 count=1 conv=notrunc

rm -rf tmp
mkdir tmp

mount $FLOPPY_IMG_PATH tmp
cp $DISK_ROOT_DIRECTORY/** tmp

umount tmp
rm -rf tmp
exit 0