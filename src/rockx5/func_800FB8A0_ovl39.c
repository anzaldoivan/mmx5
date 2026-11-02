#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern u8* func_8002D0E4(void);
extern void func_8002D89C(u8* obj);

void func_800FB8A0_ovl39(u8* obj) {
    s32 hit;
    u8* child;
    u8 f;

    hit = func_800317B8(obj);
    func_80017248(obj);
    func_8002DF54(obj);
    if (func_80031DD0(obj) >= 0) {
        if (obj[0x70] == 0) {
            func_8002F8FC(obj);
        }
        if (hit != 0 || (((f = obj[0x70]) & 1) && *(s32*)(obj + 0x20) > 0) ||
            ((f & 2) && *(s32*)(obj + 0x20) < 0)) {
            child = func_8002D0E4();
            if (child != 0) {
                child[0] = 0x61;
                child[1] = 0x15;
                child[2] = 0;
                *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
                *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                if (obj[0x15] != 0) {
                    *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
                } else {
                    *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
                }
                child[0x15] = obj[0x15];
                *(u16*)(child + 0xE) = *(u16*)(obj + 0xE);
                *(u8**)(child + 0x50) = obj;
            }
        } else {
            goto other; // !FAKE: goto kept for the matching branch layout
        }
    }
    obj[4]++;
    return;
other: // !FAKE: label kept for the matching branch layout
    func_8002D89C(obj);
}
