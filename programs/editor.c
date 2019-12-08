#include <libcmike.h>

#define VERSION "0.1"

#define DEBUG

#define BG_COLOR \
    COLOR_CREATE(COLOR_WHITE, COLOR_BLACK)

static char* editor_header = "CMike Text Editor v" VERSION;

static uint16_t text_buffer_size;
#define text_buffer ((char*)free_space_start)

struct
{
    uint16_t top_x;
    uint16_t top_y;
    uint16_t cursor_x;
    uint16_t cursor_y;
    uint16_t scr_cursor_x;
    uint16_t scr_cursor_y;
} scroll_data;

void render_ui()
{
    os_draw_background(editor_header, "[Esc] Quit", BG_COLOR);
}

void render_text()
{
    os_move_cursor(scroll_data.scr_cursor_y, scroll_data.scr_cursor_x);
    /* TODO: text pritning */
}

void calc_screen_cursor_pos()
{
    scroll_data.scr_cursor_x = 0;
    scroll_data.scr_cursor_x += scroll_data.cursor_x - scroll_data.top_x;

    scroll_data.scr_cursor_y = 1;
    scroll_data.scr_cursor_y += scroll_data.cursor_y - scroll_data.top_y;
}

void main()
{
    text_buffer_size = 0xFFFF - (uint16_t) text_buffer;
    scroll_data.top_x = 0;
    scroll_data.top_y = 0;
    scroll_data.cursor_x = 0;
    scroll_data.cursor_y = 0;
    calc_screen_cursor_pos();

    memset(text_buffer, 0, text_buffer_size);

#ifdef DEBUG

    os_print_string(editor_header);
    os_print_newline();
    os_print_string("Debug information:\r\n");
    os_print_string(" * text buffer size: 0x");
    os_print_4hex(text_buffer_size);
    os_print_newline();
    os_print_newline();
    os_print_string("Press any key to start the editor");
    os_wait_for_key();

#endif

    render_ui();
    render_text();

    while (1)
    {
        char pressedKey = os_wait_for_key(); 

        if (pressedKey == KEY_ESCAPE)
        {
            if (os_dialog_box(
                "Are you sure?", NULL, "Unsaved changes will be lost.",
                DIALOG_MODE_OK_CANCEL
                ) != DIALOG_PICKED_OK)
            {
                render_ui();
                continue;
            }

            os_clear_screen();
            break;
        }
    }
}
