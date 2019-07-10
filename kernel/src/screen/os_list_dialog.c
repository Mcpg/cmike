#include <mikeos.h>

#define DIALOG_BACKGROUND   COLOR_CREATE(COLOR_WHITE, COLOR_RED)
#define LIST_BACKGROUND     COLOR_CREATE(COLOR_BLACK, COLOR_WHITE)
#define LIST_SELECTED_COLOR COLOR_CREATE(COLOR_WHITE, COLOR_BLACK)

#define DIALOG_X 20
#define DIALOG_Y 3
#define DIALOG_WIDTH 40
#define DIALOG_HEIGHT 21

#define LIST_X DIALOG_X + 1
#define LIST_Y DIALOG_Y + 4
#define LIST_WIDTH  DIALOG_WIDTH - 2
#define LIST_HEIGHT DIALOG_HEIGHT - 2

#define LIST_SIZE 14

void _os_list_dialog(int* ax, int* bx, int* cx, int* dx, int* si, int* di)
{
    int result = os_list_dialog((char*) *ax, (char*) *bx, (char*) *cx);
    if (result)
    {
        __asm__ __volatile__("clc");
    }
    else
    {
        __asm__ __volatile__("stc");
    }
    *ax = result;
}

static void render_list(char* strings, int arrsize, int offset, int on_screen_picked_option)
{
    os_draw_block(
        LIST_BACKGROUND,
        LIST_X, LIST_Y,
        LIST_WIDTH,
        21
    );

    for (int i = 0; i < offset; i++)
    {
        strings += os_string_length(strings) + 1;
    }

    for (int i = 0; i < LIST_SIZE; i++)
    {
        if (i + offset >= arrsize)
        {
            break;
        }

        char color = LIST_BACKGROUND;
        if (i == on_screen_picked_option)
        {
            os_draw_block(
                LIST_SELECTED_COLOR,
                LIST_X + 1, LIST_Y + i + 1,
                LIST_WIDTH - 2, LIST_Y + i + 1
            );
            color = LIST_SELECTED_COLOR;
        }

        os_move_cursor(LIST_Y + 1 + i, LIST_X + 2);
        os_print_string(strings, color);
        strings += os_string_length(strings) + 1;
    }
}

int os_list_dialog(char* strings, char* help1, char* help2)
{

    /* Calculate the amount of options and temporairly
       convert the string to an array of strings. */
    int option_amount = 1;
    for (int i = 0; strings[i]; i++)
    {
        if (strings[i] == ',')
        {
            option_amount++;
        }
    }
    os_string_charchange(strings, ',', 0);

    os_draw_block(
        DIALOG_BACKGROUND,
        DIALOG_X,
        DIALOG_Y,
        DIALOG_WIDTH,
        22
    );

    if (help1 != NULL)
    {
        os_move_cursor(DIALOG_Y + 1, DIALOG_X + 1);
        os_print_string(help1, DIALOG_BACKGROUND);
    }
    if (help2 != NULL)
    {
        os_move_cursor(DIALOG_Y + 2, DIALOG_X + 1);
        os_print_string(help2, DIALOG_BACKGROUND);
    }

    int on_screen_picked_option = 0;
    int picked_option = 0;
    unsigned int current_offset = 0;
    char key;
    
    render_list(strings, option_amount, current_offset, on_screen_picked_option);
    while ((key = os_wait_for_key()) != 13)
    {
        if (key == 27) /* Esc */
        {
            return 0;
        }

        if (last_scancode == 72 && picked_option != 0) /* Up */
        {
            if (on_screen_picked_option == 0)
            {
                current_offset--;
                picked_option--;
            }
            else
            {
                on_screen_picked_option--;
                picked_option--;
            }
        }
        else if (last_scancode == 80 && picked_option != option_amount - 1) /* Down */
        {
            if (on_screen_picked_option == LIST_SIZE - 1)
            {
                current_offset++;
                picked_option++;
            }
            else
            {
                on_screen_picked_option++;
                picked_option++;
            }
        }

        render_list(strings, option_amount, current_offset, on_screen_picked_option);
    }

    /* Revert the string array to one string */
    for (int i = 0; i < option_amount; i++)
    {
        if (i < option_amount - 1)
        {
            int size = os_string_length(strings);
            strings[size] = ',';
            strings += size + 1;
        }
    }

    return picked_option + 1;
}
