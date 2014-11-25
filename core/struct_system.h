struct _easymsp_info
{
	unsigned char major;
	unsigned char minor;
};

struct ram
{
	unsigned short int total;
	unsigned short int used;
	unsigned short int free;
};

struct _easymsp_flash_infoblock
{
	unsigned short int nextfree;
	unsigned short int total;
	unsigned short int used;
	unsigned short int free;
};

struct flash
{
};

struct _system
{
	struct _easymsp_info info;
	struct _easymsp_interrupts interrupts;
	struct _easymsp_ram ram;
	struct _easymsp_flash flash;
	struct _easymsp_timers timers;
	struct _easymsp_clocks clocks;
	struct _easymsp_modules modules;
};