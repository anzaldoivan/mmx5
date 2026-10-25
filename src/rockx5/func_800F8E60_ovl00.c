#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800FB3DC_ovl00[];
extern u8 D_800FB3E8_ovl00[];

void func_800F8E60_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        func_800171E8(obj, 0);
        *(u8**)(obj + 0x50) = D_800FB3DC_ovl00;
        *(u8**)(obj + 0x54) = D_800FB3E8_ovl00;
        *(s16*)(obj + 0x7C) = 10;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
