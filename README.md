# CMike
CMike is an operating system written in C (and a tiny, tiny bit of 
supporting Assembly), which aims to be fully binarily compatible with
[MikeOS](http://mikeos.sourceforge.net/) 4.6

You can download the latest release from the
[Releases](https://github.com/Mcpg/cmike/releases) section of this 
repository. The project is licensed under the [MIT License](LICENSE).

## System requirements
Exactly the same as MikeOS:
 * 386 class PC
 * 192 KiB of system memory
 * CGA or compatible
 * a keyboard
 * a floppy disk for boot (for now there are problems with booting off 
hard drives)
Software might require additional things, but this list is everything 
necessary for CMike.

## Build
In order to build CMike you need:
 * [ia16-elf toolchain](https://github.com/tkchia/build-ia16)
 * nasm
 * mtools
 * make
 * qemu for `make run`

There's a Makefile in the root of this repository. It supports the 
following targets:
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
