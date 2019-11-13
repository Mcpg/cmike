#include <mikeos.h>

#define INPUT_DIALOG_COLOR       COLOR_CREATE(COLOR_WHITE, COLOR_RED)
#define INPUT_DIALOG_INPUT_COLOR COLOR_CREATE(COLOR_BLACK, COLOR_LIGHT_GRAY)

#define INPUT_DIALOG_WIDTH  56
#define INPUT_DIALOG_HEIGHT 5
#define INPUT_DIALOG_X 12
#define INPUT_DIALOG_Y 10

#define INPUT_DIALOG_TEXT_X INPUT_DIALOG_X + 1
#define INPUT_DIALOG_TEXT_Y INPUT_DIALOG_Y + 1

#define INPUT_DIALOG_INPUT_X INPUT_DIALOG_X + 2
#define INPUT_DIALOG_INPUT_Y INPUT_DIALOG_Y + 3

#define INPUT_DIALOG_MAX_STRING INPUT_DIALOG_WIDTH - 4

void _os_input_dialog(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    os_input_dialog((char*) *bx, (char*) *ax);
}

void os_input_dialog(char* message, char* target)
{
    os_draw_block(
        INPUT_DIALOG_COLOR,
        INPUT_DIALOG_X,
        INPUT_DIALOG_Y,
        INPUT_DIALOG_WIDTH,
        INPUT_DIALOG_Y + INPUT_DIALOG_HEIGHT + 1
    );
    os_draw_block(
        INPUT_DIALOG_INPUT_COLOR,
        INPUT_DIALOG_INPUT_X,
        INPUT_DIALOG_INPUT_Y,
        INPUT_DIALOG_MAX_STRING,
        INPUT_DIALOG_INPUT_Y + 1
    );

    os_move_cursor(INPUT_DIALOG_TEXT_Y, INPUT_DIALOG_TEXT_X);
    os_print_string(message, INPUT_DIALOG_COLOR);

    os_move_cursor(INPUT_DIALOG_INPUT_Y, INPUT_DIALOG_INPUT_X);
    os_input_string(target, INPUT_DIALOG_INPUT_COLOR, 52);
}
