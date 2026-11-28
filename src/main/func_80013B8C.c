#include "types.h"

extern void setup_file_load(s32, s32, s32);
extern void pump_file_loads(void);
extern void read_dat_file(s32, s32);

void func_80013B8C(void) {
    setup_file_load(0x4D, 0, 0);
    pump_file_loads();
    read_dat_file(0x4E, 0x801F3000);
    pump_file_loads();
}
