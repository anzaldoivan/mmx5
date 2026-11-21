#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void (*D_801017D0_ovl04[])(u8*);
extern u8 D_801017BC_ovl04[];
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);

void func_800F3B5C_ovl04(u8* obj) {
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(8, D_801017BC_ovl04, obj);
        *(signed char*)(obj + 5) = 3;
        obj[3] = 0;
    } else {
        D_801017D0_ovl04[*(signed char*)(obj + 5)](obj);
        if (*(signed char*)(obj + 5) == 2) {
            func_8002D89C(obj);
        }
    }
}

#define D_800EEBA0_ovl00 func_800F3BEC_ovl04
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEBA0_ovl00 func_800F3C0C_ovl04
#define func_8002D720 animate_object
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern u8 D_8010177C_ovl04[];
extern u8 D_8009A244;

void func_800F3C2C_ovl04(u8* obj) {
    func_80028B18(0, 0x1240, 0x400, D_8010177C_ovl04);
    D_8009A244 = 1;
    obj[4] = 2;
}
