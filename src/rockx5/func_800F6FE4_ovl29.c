#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern u8 D_8009A1F8[];
extern u8 D_800FA4DC_ovl29[];
extern u16 D_800FA504_ovl29[];

void func_800F6FE4_ovl29(u8* obj) {
    u8* sub;
    s8 idx;
    s32 r;
    u8* g;

    sub = *(u8**)(obj + 0x7C);
    func_800317B8(obj);
    func_8002DF54(obj);
    func_80017248(obj);
    if (*(s8*)(obj + 3) == 0) {
        if (*(s8*)(sub + 4) != 1) {
            obj[5] = 0;
            obj[4]++;
            return;
        }
        func_800171E8(obj, 0x1E);
        *(u8**)(obj + 0x54) = D_800FA4DC_ovl29;
        r = func_8002DF78() & 0x1F;
        g = D_8009A1F8;
        idx = obj[7];
        *(s16*)(obj + 0xA) = *(u16*)(g + 0xA) + D_800FA504_ovl29[idx] + r;
        *(s16*)(obj + 0xE) = *(u16*)(g + 0xE) - 0x20;
        *(s32*)(obj + 0x20) = 0xFFFA0000;
        *(s32*)(obj + 0x24) = 0xFFFA0000;
        *(s16*)(obj + 0x88) = idx * 8 + 0x64;
        *(s16*)(obj + 0x8A) = 4;
        obj[6]++;
    }
}
