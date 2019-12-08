#include <libcmike.h>

#define VERSION "0.1"

#define BG_COLOR \
    COLOR_CREATE(COLOR_WHITE, COLOR_BLACK)

void render_ui()
{
    os_draw_background("CMike Text Editor v" VERSION, "[Esc] Quit", BG_COLOR);
}

void main()
{
    render_ui();

    while (1)
    {
        char pressedKey = os_wait_for_key(); 
        
        if (pressedKey == KEY_ESCAPE)
        {
            if (os_dialog_box(
                "Are you sure?", NULL, "Unsaved changes will be lost.",
                DIALOG_MODE_OK_CANCEL
                ) != DIALOG_PICKED_OK) continue;
            break;
        }
    }
}
