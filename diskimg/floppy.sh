#!/bin/bash

if [ "$EUID" -ne 0 ]; then
    echo "ERROR: Only root can do that!"
    exit 1
fi

TMPDIR=/tmp/cmike_floppy_$RANDOM$RANDOM$RANDOM
TMPIMG=$TMPDIR.flp

echo " >>> Creating the image..."
dd if=/dev/zero of=$TMPIMG bs=512 count=2880 || exit 1
echo " >>> Copying the bootloader image..."
dd if=$PROJECT_ROOT_DIR/bootloader/bootloader.bin of=$TMPIMG bs=512 count=1 conv=notrunc || exit 1

mkdir $TMPDIR || exit 1

echo " >>> Mounting the image..."
mount -o loop -t vfat $TMPIMG $TMPDIR || exit 1
echo " >>> Copying the files..."
cp $DISK_ROOT_DIRECTORY/** $TMPDIR || exit 1

echo " >>> Unmounting the image..."
umount $TMPDIR || exit 1
rm -rf $TMPDIR

cp $TMPIMG $FLOPPY_IMG_PATH
chmod 666 $FLOPPY_IMG_PATH

echo " >>> Done."

exit 0