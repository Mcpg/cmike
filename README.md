# CMike
CMike is an operating system written in C that aims to be
fully compatible with [MikeOS](http://mikeos.sourceforge.net/) 4.6

## Build
In order to build CMike you need:
 * [ia16-elf toolchain](https://github.com/tkchia/build-ia16)
 * nasm
 * mtools
 * make
 * qemu for `make run`

In the root of the repository a Makefile is located. It supports
following targets:
 * `make all` - build everything, including the disk image
 * `make bootloader` - NatLoader, boot sector used by CMike
 * `make kernel` - the kernel, obviously
 * `make libcmike` - front end library for MikeOS/CMike C programs
 * `make programs` - CMike software
 * `make run` - runs QEMU with diskimg/cmike.flp in floppy drive A:
   and PC speaker enabled

Have fun. :)
