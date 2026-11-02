#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();

void func_800F4638_ovl28(u8* obj) {
    u8* parent;
    u8* spawn;
    s32 kind;

    func_80017248(obj);
    parent = *(u8**)(obj + 0x50);
    kind = parent[0x47];
    if (kind < 0x18) {
        if (kind >= 0x14) {
            if (obj[0x15] == 0) {
                *(u16*)(obj + 0xA) = *(u16*)(parent + 0xA) - 0x20;
            } else {
                *(u16*)(obj + 0xA) = *(u16*)(parent + 0xA) + 0x20;
            }
            *(u16*)(obj + 0xE) = *(u16*)(parent + 0xE) + 8;
            goto spawn_it; // !FAKE: goto kept for the matching branch layout
        }
    }
    if (obj[0x15] == 0) {
        *(u16*)(obj + 0xA) = *(u16*)(parent + 0xA) - 0x14;
    } else {
        *(u16*)(obj + 0xA) = *(u16*)(parent + 0xA) + 0x14;
    }
    *(u16*)(obj + 0xE) = *(u16*)(parent + 0xE);
spawn_it:
    spawn = func_8002D1A4(kind);
    if (spawn != 0) {
        if (*(s8*)(obj + 0x45) == 2) {
            spawn[0] = 0x61;
            spawn[1] = 0x23;
            spawn[2] = 0;
            *(u16*)(spawn + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(spawn + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(spawn + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(spawn + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            spawn[0x15] = obj[0x15];
            *(s32*)(spawn + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(spawn + 0xC) = *(s32*)(obj + 0xC);
            *(u8**)(spawn + 0x7C) = *(u8**)(obj + 0x50);
        }
    }
    if (*(s8*)(obj + 0x45) == 1) {
        obj[4]++;
    }
}
