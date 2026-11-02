#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);

void func_800FB308_ovl38(u8* obj) {
    u8* p;
    u16 t;

    p = *(u8**)(obj + 0x50);
    if (*(s8*)(p + 4) == 2) {
        goto end; // !FAKE: goto kept for the matching branch layout
    }
    if (p[0x47] == 0x2E) {
        obj[3] = 0;
    } else {
        obj[3] = 1;
    }
    if (*(s8*)(obj + 3) != 0 && (s16)(*(s16*)(obj + 0x54) % 30) == 0) {
        func_80016490(2, 0xA4, 0);
    }
    func_80017248(obj);
    t = *(u16*)(obj + 0x54);
    if (*(s16*)(obj + 0x54) != 0) {
        *(u16*)(obj + 0x54) = --t;
        if ((t << 16) == 0) {
        end: // !FAKE: label kept for the matching branch layout
            obj[3] = 0;
            obj[4]++;
            return;
        }
    }
    p = *(u8**)(obj + 0x50);
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    obj[0x15] = p[0x15];
}
