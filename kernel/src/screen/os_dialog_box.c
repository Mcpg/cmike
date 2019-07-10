#include <mikeos.h>

/* Partial customization of the dialog window can be done here.
   By default the dialog window mimicks MikeOS box with its size and colors. */
#define DIALOG_COLOR  COLOR_CREATE(COLOR_WHITE, COLOR_RED)
#define DIALOG_BUTTON_INACTIVE_COLOR DIALOG_COLOR
#define DIALOG_BUTTON_ACTIVE_COLOR   COLOR_CREATE(COLOR_BLACK, COLOR_WHITE)

#define DIALOG_X      19
#define DIALOG_Y      10
#define DIALOG_WIDTH  42
#define DIALOG_STRMAX DIALOG_WIDTH - 2

#define DIALOG_BUTTON_WIDTH 8
#define DIALOG_0_OK_BUTTON_POS_X     DIALOG_X + 16
#define DIALOG_0_OK_BUTTON_POS_Y     DIALOG_Y + 6
#define DIALOG_1_OK_BUTTON_POS_X     DIALOG_X + 8
#define DIALOG_1_OK_BUTTON_POS_Y     DIALOG_Y + 6
#define DIALOG_1_CANCEL_BUTTON_POS_X DIALOG_X + 26
#define DIALOG_1_CANCEL_BUTTON_POS_Y DIALOG_Y + 6

#define DIALOG_OK_TEXT     "   OK   "
#define DIALOG_CANCEL_TEXT " Cancel "

void _os_dialog_box(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    *ax = os_dialog_box((char*) *ax, (char*) *bx, (char*) *cx, *dx);
}

static void draw_0_ok_active_button()
{
    os_move_cursor(
        DIALOG_0_OK_BUTTON_POS_Y,
        DIALOG_0_OK_BUTTON_POS_X
    );
    os_print_string(DIALOG_OK_TEXT, DIALOG_BUTTON_ACTIVE_COLOR);
}

static void draw_1_ok_active_button()
{
    os_move_cursor(
        DIALOG_1_OK_BUTTON_POS_Y,
        DIALOG_1_OK_BUTTON_POS_X
    );
    os_print_string(DIALOG_OK_TEXT, DIALOG_BUTTON_ACTIVE_COLOR);
}

static void draw_1_ok_inactive_button()
{
    os_move_cursor(
        DIALOG_1_OK_BUTTON_POS_Y,
        DIALOG_1_OK_BUTTON_POS_X
    );
    os_print_string(DIALOG_OK_TEXT, DIALOG_BUTTON_INACTIVE_COLOR);
}

static void draw_1_cancel_active_button()
{
    os_move_cursor(
        DIALOG_1_CANCEL_BUTTON_POS_Y,
        DIALOG_1_CANCEL_BUTTON_POS_X
    );
    os_print_string(DIALOG_CANCEL_TEXT, DIALOG_BUTTON_ACTIVE_COLOR);
}

static void draw_1_cancel_inactive_button()
{
    os_move_cursor(
        DIALOG_1_CANCEL_BUTTON_POS_Y,
        DIALOG_1_CANCEL_BUTTON_POS_X
    );
    os_print_string(DIALOG_CANCEL_TEXT, DIALOG_BUTTON_INACTIVE_COLOR);
}

int os_dialog_box(char* string1, char* string2, char* string3, int mode)
{
    int retval = 0;

    os_draw_block(DIALOG_COLOR, DIALOG_X, DIALOG_Y, DIALOG_WIDTH, DIALOG_Y + 7);
    if (string1 != NULL && os_string_length(string1) <= DIALOG_STRMAX)
    {
        os_move_cursor(DIALOG_Y + 1, DIALOG_X + 1);
        os_print_string(string1, DIALOG_COLOR);
    }
    if (string2 != NULL && os_string_length(string2) <= DIALOG_STRMAX)
    {
        os_move_cursor(DIALOG_Y + 2, DIALOG_X + 1);
        os_print_string(string2, DIALOG_COLOR);
    }
    if (string3 != NULL && os_string_length(string3) <= DIALOG_STRMAX)
    {
        os_move_cursor(DIALOG_Y + 3, DIALOG_X + 1);
        os_print_string(string3, DIALOG_COLOR);
    }

    if (mode == DIALOG_MODE_OK)
    {
        draw_0_ok_active_button();
        while (os_wait_for_key() != 13);
    }
    else
    {
        char key;
        retval = 0;
        draw_1_ok_active_button();
        draw_1_cancel_inactive_button();

        while ((key = os_wait_for_key()) != 13)
        {
            if (last_scancode == 75) /* left */
            {
                draw_1_ok_active_button();
                draw_1_cancel_inactive_button();
                retval = 0;
            }
            else if (last_scancode == 77) /* right */
            {
                draw_1_ok_inactive_button();
                draw_1_cancel_active_button();
                retval = 1;
            }
        }
    }
    
    return retval;
}
