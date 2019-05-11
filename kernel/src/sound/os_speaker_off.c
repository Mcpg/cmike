#include <mikeos.h>

struct gp_registers _os_speaker_off(struct gp_registers regs)
{
    os_speaker_off();
    return regs;
}

void os_speaker_off()
{
    
}
