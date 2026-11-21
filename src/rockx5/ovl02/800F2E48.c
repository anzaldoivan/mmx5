#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
extern X4_BackgroundObj D_8009A24C[3];
extern u8 D_800D1C27;
void func_80032CEC();

void func_800F2E48_ovl02(u8* a0) {
    u16 c;

    if (D_8009A197 != 0 || D_8009A24C[0].unk3 == 0 ||
        (c = (s8)D_800D1C27) == 0) {
        a0[3] = 0;
    } else {
        *(u16*)(a0 + 0x34) = c | (c << 5) | (c << 10);
        func_80032CEC();
    }
}

#define D_800EEBA0_ovl00 func_800F2EB8_ovl02
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
