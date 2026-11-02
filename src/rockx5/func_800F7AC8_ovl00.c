#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DED4(u8* obj);
extern s32 func_800317B8(u8* a0);
extern u8 D_800FB5A4_ovl00[];

void func_800F7AC8_ovl00(u8* obj) {
    u8* child;

    switch (*(s8*)(obj + 5)) {
    case 0:
        if (*(s8*)(obj + 0x46) == 0) {
            child = func_8002D1A4();
            if (child != 0) {
                child[0] = 0x61;
                child[1] = 3;
                child[2] = 4;
                *(u8**)(child + 0x7C) = *(u8**)(obj + 0x7C);
            }
            func_800171E8(obj, 1);
            *(u8**)(obj + 0x50) = D_800FB5A4_ovl00;
            *(u16*)(obj + 0x8C) = 0xB4;
            (*(u8**)(obj + 0x7C))[7] = 1;
            obj[5]++;
        }
        break;
    case 1:
        if (--*(u16*)(obj + 0x8C) == 0 ||
            *(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
            func_800171E8(obj, 2);
            *(u8**)(obj + 0x50) = 0;
            (*(u8**)(obj + 0x7C))[7] = 2;
            obj[5]++;
        }
        break;
    case 2:
        if (*(s8*)(obj + 0x46) == 0) {
            (*(u8**)(obj + 0x7C))[7] = 3;
            obj[4]++;
        }
        break;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_800317B8(obj);
    if (func_8002D938(obj, 0x20, 0x20) == 0) {
        func_8002D9EC(obj, 0x10, 0x10);
    } else {
        obj[4]++;
    }
}
