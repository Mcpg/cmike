#!/bin/bash

if [ "$EUID" -ne 0 ]; then
    echo "ERROR: Only root can do that!"
    exit 1
fi

TMPDIR=/tmp/cmike_floppy_$RANDOM$RANDOM$RANDOM
TMPIMG=$TMPDIR.flp

dd if=/dev/zero of=$TMPIMG bs=512 count=2880 || exit 1
dd if=$PROJECT_ROOT_DIR/bootloader/bootloader.bin of=$TMPIMG bs=512 count=1 conv=notrunc || exit 1

mkdir $TMPDIR || exit 1

mount -o loop -t vfat $TMPIMG $TMPDIR || exit 1
cp $DISK_ROOT_DIRECTORY/** $TMPDIR || exit 1

umount $TMPDIR || exit 1
rm -rf $TMPDIR

cp $TMPIMG $FLOPPY_IMG_PATH

exit 0