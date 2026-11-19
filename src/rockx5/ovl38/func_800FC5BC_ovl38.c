#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FD94C_ovl38[])(u8*);
extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];

void func_800FC5BC_ovl38(u8* obj) {
    animate_object(obj);
    D_800FD94C_ovl38[*(s8*)(obj + 6)](obj);
    if (obj[0x47] == 0x2E) {
        *(u8**)(obj + 0x50) = 0;
        *(u8**)(obj + 0x54) = 0;
    } else {
        *(u8**)(obj + 0x50) = D_800FD574_ovl38;
        *(u8**)(obj + 0x54) = D_800FD578_ovl38;
    }
}
