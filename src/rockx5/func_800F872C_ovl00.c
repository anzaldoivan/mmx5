#include "types.h"

extern s32 func_8002DF78(void);
extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s8 D_800D1CA2;
extern u8 D_800FB448_ovl00[][6];

void func_800F872C_ovl00(u8* obj) {
    u32 r;
    u8 t;

    r = func_8002DF78() & 0xF;
    obj[0x8E] = 0;
    if (D_800D1CA2 / 2 < (s8)obj[0x5C]) {
        if (r < 8) {
            obj[0x8D] = 0;
        } else {
            obj[0x8D] = 1;
        }
    } else {
        if (r < 8) {
            obj[0x8D] = 2;
        } else {
            obj[0x8D] = 3;
        }
    }
    t = D_800FB448_ovl00[obj[0x8D]][obj[0x8E]++];
    obj[0x6] = 0;
    obj[0x5] = t;
    func_80017248(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
