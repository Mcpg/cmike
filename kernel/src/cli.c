#include <mikeos.h>

#define LIGHT_GRAY_COLOR COLOR_CREATE(COLOR_LIGHT_GRAY, COLOR_BLACK)
#define GRAY_COLOR       COLOR_CREATE(COLOR_DARK_GRAY, COLOR_BLACK)
#define RED_COLOR        COLOR_CREATE(COLOR_LIGHT_RED, COLOR_BLACK)
#define GREEN_COLOR      COLOR_CREATE(COLOR_LIGHT_GREEN, COLOR_BLACK)

struct cli_integrated_command
{
    char* name;
    void (*callback)(char* cmd);
};

#define INTEGRATED_COMMAND_AMOUNT 10
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

void time_cmd(char* cmd)
{
    char buffer[10] = {0};

    os_print_string(" * ", GRAY_COLOR);
    os_print_string("The current time is: ", DEFAULT_COLOR);
    os_get_time_string(buffer);
    os_print_string(buffer, GREEN_COLOR);
    os_print_newline(DEFAULT_COLOR);
}

void date_cmd(char* cmd)
{
    char buffer[10] = {0};

    os_print_string(" * ", GRAY_COLOR);
    os_print_string("The current date is: ", DEFAULT_COLOR);
    os_get_date_string(buffer);
    os_print_string(buffer, GREEN_COLOR);
    os_print_newline(DEFAULT_COLOR);
}

void system_cmd(char* cmd)
{
    os_print_string(" * ", GRAY_COLOR);
    os_print_string("os_stack_bottom: ", DEFAULT_COLOR);
    os_print_string("0x", LIGHT_GRAY_COLOR);
    os_print_4hex((unsigned int) os_stack_bottom, LIGHT_GRAY_COLOR);
    os_print_newline(DEFAULT_COLOR);

    os_print_string(" * ", GRAY_COLOR);
    os_print_string("os_stack_top: ", DEFAULT_COLOR);
    os_print_string("0x", LIGHT_GRAY_COLOR);
    os_print_4hex((unsigned int) os_stack_top, LIGHT_GRAY_COLOR);
    os_print_newline(DEFAULT_COLOR);

    os_print_string(" * ", GRAY_COLOR);
    os_print_string("Overall stack size: ", DEFAULT_COLOR);
    os_print_string("0x", LIGHT_GRAY_COLOR);
    os_print_4hex((unsigned int) os_stack_top - (unsigned int) os_stack_bottom, LIGHT_GRAY_COLOR);
    os_print_newline(DEFAULT_COLOR);

    os_print_string(" * ", GRAY_COLOR);
    os_print_string("Stack spointer: ", DEFAULT_COLOR);
    os_print_string("0x", LIGHT_GRAY_COLOR);
    os_print_4hex((unsigned int) get_sp(), LIGHT_GRAY_COLOR);
    os_print_newline(DEFAULT_COLOR);
}

void reboot_cmd(char* cmd)
{
    reboot();
}

void clear_cmd(char* cmd)
{
    os_clear_screen();
}

void dump_boot_sector_cmd(char* cmd)
{
    ASSERT(cmike_read_boot_sector());

    os_print_string("Partial boot sector dump:\r\n", GRAY_COLOR);
    os_print_string(" * ", GRAY_COLOR);
    os_print_string("Volume label: ", DEFAULT_COLOR);
    cmike_print_chars(&boot_sector.volume_label, FAT_VOLUME_LABEL_SIZE, GRAY_COLOR);

    os_print_newline(DEFAULT_COLOR);
}

void ls_cmd(char* cmd)
{
    /* NOTE: It's getting near to the stack limit */
    char buffer[512] = { 0 };
    os_get_file_list(buffer);
    os_print_string("Root directory listing:\r\n", GRAY_COLOR);
    os_print_string(buffer, DEFAULT_COLOR);
    os_print_newline(DEFAULT_COLOR);
}

void fat_dump_cmd(char* cmd)
{
    int i;

    os_print_string("First 120 cluster values from FAT0:\r\n", GRAY_COLOR);

    for (i = 0; i < 120; i += 8)
    {
        os_print_4hex(i, GRAY_COLOR);
        os_print_string(": ", GRAY_COLOR);
        os_print_4hex(cmike_get_cluster_value(i), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 1), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 2), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 3), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 4), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 5), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 6), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 7), DEFAULT_COLOR);
        os_print_newline(DEFAULT_COLOR);
    }

    os_print_string("\r\n32 entries, offset 0xF0:\r\n", GRAY_COLOR);
    for (i = 0xF0; i < 0x110; i += 8)
    {
        os_print_4hex(i, GRAY_COLOR);
        os_print_string(": ", GRAY_COLOR);
        os_print_4hex(cmike_get_cluster_value(i), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 1), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 2), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 3), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 4), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 5), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 6), DEFAULT_COLOR);
        os_print_space(DEFAULT_COLOR);
        os_print_4hex(cmike_get_cluster_value(i + 7), DEFAULT_COLOR);
        os_print_newline(DEFAULT_COLOR);
    }
}

static struct cli_integrated_command commands[INTEGRATED_COMMAND_AMOUNT] =
{
    { "help", help_cmd },
    { "version", version_cmd },
    { "time", time_cmd },
    { "date", date_cmd },
    { "system", system_cmd },
    { "reboot", reboot_cmd },
    { "clear", clear_cmd },
    { "dump_boot_sector", dump_boot_sector_cmd },
    { "ls", ls_cmd },
    { "fat_dump", fat_dump_cmd }
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
            if (os_file_exists(buffer))
            {
                cmike_run_program(buffer);
                continue;
            }

            os_print_string("Command not found.\r\n", RED_COLOR);
            continue;
        }
    }
}