#include <mikeos.h>

struct gp_registers _os_check_for_key(struct gp_registers regs)
{
    regs.ax = os_check_for_key();
    return regs;
}

char os_check_for_key()
{
    struct gp_registers regs;
    regs.ax = 0x0100; /* ah = 0x01 */
    int16h(&regs);

    if (check_zf())
    {
        /* No key has been pressed */
        return '\0';
    }
    else
    {
        /* Remove the key from the buffer */
        return os_wait_for_key();
    }
}
