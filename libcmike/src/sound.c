#include <libcmike.h>

void os_speaker_tone(uint16_t tone)
{
    cmike_syscall_nr(OS_SPEAKER_TONE_ADDR, (syscall_regs) {
        .ax = tone
    });
}

void os_speaker_off()
{
    cmike_syscall_ns(OS_SPEAKER_OFF_ADDR);
}
