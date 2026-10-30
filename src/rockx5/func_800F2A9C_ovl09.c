#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D144(void);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DED4(u8* obj);
extern s32 func_8002DFF8(u8* obj, s32 a1, s32 a2);
extern void func_8002E0F8(s32* a0, s32* a1, u8 a2);
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u8 D_800C9310;
extern signed char D_800D1C0C;
extern u16 D_800D50DE;
extern s16 D_800FB61C_ovl09;
extern s16 D_800FB61E_ovl09;

void func_800F2A9C_ovl09(u8* obj) {
    u8* slot;
    s32 n;

    n = *(u16*)(obj + 0x7C) + 1;
    *(u16*)(obj + 0x7C) = n;
    if ((s16)((s16)n % 5) == 0) {
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        if (D_800D50DE == 0) {
            D_800C9310 = 1;
            func_8002E0F8((s32*)(obj + 0x20), (s32*)(obj + 0x24),
                          func_8002DFF8(obj, D_800FB61C_ovl09 << 16,
                                        D_800FB61E_ovl09 << 16));
            *(s32*)(obj + 0x20) *= 3;
            *(s32*)(obj + 0x24) *= 3;
            obj[6]++;
            if (D_800D1C0C != 0xC) {
                slot = func_8002D144();
                if (slot != 0) {
                    slot[0] = 1;
                    slot[1] = 2;
                    slot[2] = 1;
                }
            }
        }
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
