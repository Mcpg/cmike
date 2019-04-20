# CMike
CMike is a project attempting to create a
[MikeOS](http://mikeos.sourceforge.net/) compatible kernel.

It aims to fully implement program API of MikeOS 4.6.1.

## Building
In order to build the kernel you need to install the
following software:
 * GNU Make,
 * [Unofficial port of GCC to 16-bit Intel CPUs](https://launchpad.net/~tkchia/+archive/ubuntu/build-ia16)

Now in the root directory of this repository execute
`make all`. After the build process finishes, `kernel.bin`
should be created.

## Usage
To use the CMike kernel you just need to replace the
original MikeOS KERNEL.BIN with CMike's KERNEL.BIN.

It should now work.
