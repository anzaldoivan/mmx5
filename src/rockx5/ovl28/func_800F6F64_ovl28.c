#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern void (*D_800FE34C_ovl28[])(u8*);

void func_800F6F64_ovl28(u8* obj) {
    u8* p;

    p = *(u8**)(obj + 0x50);
    D_800FE34C_ovl28[((signed char*)obj)[6]](obj);
    if (is_off_screen(obj, 0x60, 0x60) == 0) {
        if (((signed char*)obj)[3] != 0) {
            func_8002D9EC(obj, 0x20, 0x20);
        }
    } else {
        obj[4]++;
    }
    if (((signed char*)p)[4] == 2) {
        obj[4]++;
    }
}
