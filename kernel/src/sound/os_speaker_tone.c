#include <mikeos.h>

struct gp_registers _os_speaker_tone(struct gp_registers regs)
{
    os_speaker_tone(regs.ax);
    return regs;
}

void os_speaker_tone(int frequency)
{
    
}
