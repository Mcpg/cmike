# CMike
CMike is an operating system written in C which aims to be fully compatible with
[MikeOS](http://mikeos.sourceforge.net/) 4.6

You can download the latest release from the
[Releases](https://github.com/Mcpg/cmike/releases) section of this repository.

## System requirements
 * 386 class PC
 * 1 MB of RAM

## Build
In order to build CMike you need:
 * [ia16-elf toolchain](https://github.com/tkchia/build-ia16)
 * nasm
 * mtools
 * make
 * qemu for `make run`

In the root of the repository a Makefile is located. It supports following
targets:
 * `make all` - build everything, including the disk image
 * `make bootloader` - NatLoader, boot sector used by CMike
 * `make kernel` - the kernel, obviously
 * `make libcmike` - front end library for MikeOS/CMike C programs
 * `make programs` - CMike software
 * `make diskimg` - build the floppy disk image (diskimg/cmike.flp)
 * `make run` - runs QEMU with diskimg/cmike.flp in floppy drive A: and PC
   speaker enabled
 * `make dist` prepare a cmike-VERSION.tar.gz archive with cmike.flp, all files
   from misc directory and LICENSE

Have fun. :)
