#!/bin/bash

if [ "$EUID" -ne 0 ]; then
    echo "ERROR: Only root can do that!"
    exit 1
fi

rm $FLOPPY_IMG_PATH
mkdosfs -C $FLOPPY_IMG_PATH 1440 || exit 1
dd if=$PROJECT_ROOT_DIR/bootloader/bootloader.bin of=$FLOPPY_IMG_PATH bs=512 count=1 conv=notrunc || exit 1

rm -rf tmp
mkdir tmp || exit 1

mount -o loop -t vfat $FLOPPY_IMG_PATH tmp || exit 1
cp $DISK_ROOT_DIRECTORY/** tmp || exit 1

umount tmp || exit 1
rm -rf tmp
exit 0