#include <mikeos.h>

#define DEBUG_READ_BOOT_SECTOR

struct _boot_sector boot_sector = { 0 };

int cmike_read_boot_sector()
{
	uint8_t sectors_read = cmike_disk_read(&boot_sector, 0, 1);

#ifdef DEBUG_READ_BOOT_SECTOR
	ASSERT(sectors_read == 1);
	ASSERT(last_disk_error == 0);
#endif

	if (sectors_read != 1 || last_disk_error != 0)
		return 0;
	
	return 1;
}
