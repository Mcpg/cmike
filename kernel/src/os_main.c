#include <mikeos.h>

void os_main(uint16_t boot_device)
{
    __asm__ __volatile__("mov $0x0E, %ah;mov '!', %al;int $0x10");

    panic("End of os_main reached");
    while(1);
}