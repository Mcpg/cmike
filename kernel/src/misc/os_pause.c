#include <mikeos.h>

void _os_pause(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_pause(*ax);
}

void os_pause(unsigned int time)
{
    if (time == 0)
    {
        return;
    }

    int time_counter = 0;
    int previous_time = bios_read_system_timer();
    int required_delay = time * 2;

    do
    {
        int current_ticks = 0;
        while ((current_ticks = bios_read_system_timer()) == previous_time);
        previous_time = current_ticks;
        time_counter++;
    } while (time_counter <= required_delay);
}
