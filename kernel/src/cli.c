#include <mikeos.h>

#define LIGHT_GRAY_COLOR COLOR_CREATE(COLOR_LIGHT_GRAY, COLOR_BLACK)
#define GRAY_COLOR       COLOR_CREATE(COLOR_DARK_GRAY, COLOR_BLACK)
#define RED_COLOR        COLOR_CREATE(COLOR_LIGHT_RED, COLOR_BLACK)

struct cli_integrated_command
{
    char* name;
    void (*callback)(char* cmd);
};

#define INTEGRATED_COMMAND_AMOUNT 2
static struct cli_integrated_command commands[INTEGRATED_COMMAND_AMOUNT];

void version_cmd(char* cmd)
{
    os_print_string(" * ", GRAY_COLOR);
    os_print_string("MikeOS version: ", DEFAULT_COLOR);
    os_print_string(MIKEOS_VER "\r\n", LIGHT_GRAY_COLOR);
    os_print_string(" * ", GRAY_COLOR);
    os_print_string("Reported API version: ", DEFAULT_COLOR);
    cmike_print_dec(os_get_api_version(), LIGHT_GRAY_COLOR);
    os_print_newline(DEFAULT_COLOR);
}

void help_cmd(char* cmd)
{
    os_print_string("Available commands: ", DEFAULT_COLOR);
    for (int i = 0; i < INTEGRATED_COMMAND_AMOUNT; i++)
    {
        os_print_string(commands[i].name, LIGHT_GRAY_COLOR);
        if (i < INTEGRATED_COMMAND_AMOUNT - 1)
        {
            os_print_string(", ", DEFAULT_COLOR);
        }
    }
    os_print_newline(DEFAULT_COLOR);
}

static struct cli_integrated_command commands[INTEGRATED_COMMAND_AMOUNT] =
{
    { "help", help_cmd },
    { "version", version_cmd }
};

void start_cli()
{
    int cmd_found = 0;
    char buffer[256];

    os_print_string("CMike Integrated Shell\r\nType `help` to see available commands.\r\n", DEFAULT_COLOR);
    os_print_newline(DEFAULT_COLOR);

    while (1)
    {
        os_print_string("> ", GRAY_COLOR);
        os_input_string(buffer, DEFAULT_COLOR, 255);
        os_print_newline(DEFAULT_COLOR);

        if (os_string_length(buffer) == 0)
        {
            continue;
        }

        cmd_found = 0;

        for (int i = 0; i < INTEGRATED_COMMAND_AMOUNT; i++)
        {
            if (os_string_compare(buffer, commands[i].name))
            {
                commands[i].callback(buffer);
                cmd_found = 1;
                break;
            }
        }

        if (!cmd_found)
        {
            os_print_string("Command not found.\r\n", RED_COLOR);
            continue;
        }
    }
}