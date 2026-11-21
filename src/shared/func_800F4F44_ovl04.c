#include "types.h"
#include "mmx5/globals.h"

extern u8* alloc_class3_slot(void);
extern signed char D_8009A0A5;
extern u8 D_8009A23F;
extern signed char D_800D1C0C;

void func_800F4F44_ovl04(Ent8EF0* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        D_8009A23F = 2;
        if (D_800D1C0C != 0xC) {
            func_8003D29C(0x1D, 0x40);
        }
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u8**)((u8*)a + 0x80) = p;
        }
        a->unk7C = 0x168;
        a->unk5++;
    }
}
