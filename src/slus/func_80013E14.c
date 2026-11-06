#include "types.h"
#include "addr.h"

extern s32 D_8009A420;
extern u8 D_800AA9A8[];
extern u8 D_800C9588[];
extern void func_800132F8(s8 arg);
extern void func_800176B0(void);
extern void func_80013C04(s32);
extern void func_80012E6C(s32);

void func_80013E14(void) {
    s8* p;
    s8* q;
    u8 i;

    func_800132F8(0x10);
    p = (s8*)&D_8009A420;
    if (p[4] != 0) {
        do {
            ((u8**)&D_1F800000)[0x40] = D_800AA9A8 + D_1F800000 * 0xA000;
            ((u8**)&D_1F800000)[0x41] = D_800C9588 + D_1F800000 * 0x2000;
            func_800176B0();
            for (i = 0; i < 5; i++) {
                func_80013C04(i);
            }
            func_80012E6C(1);
            q = (s8*)&D_8009A420;
        } while (q[4] != 0);
    }
}
