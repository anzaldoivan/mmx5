#include "types.h"

extern void func_800F6D58_ovl00(s32);
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800F8420_ovl00(u8* obj) {
    func_800F6D58_ovl00(0);
    func_800F6D58_ovl00(1);
    func_800F6D58_ovl00(2);
    func_800F6D58_ovl00(3);
    *(s16*)(obj + 0x7C) += 1;
    if ((s16)(*(s16*)(obj + 0x7C) % 5) == 0) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
        if (D_800D50DE == 0x1F) {
            *(s16*)(obj + 0x7C) = 0x78;
            obj[6]++;
        }
    }
}
