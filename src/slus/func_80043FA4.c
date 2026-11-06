#include "types.h"

extern s32 func_80043B88(u8* arg0);
extern void func_80017248(u8* obj);
extern s32 func_800306E0(u8* obj);
extern void func_8003A874(u8* obj);
extern void func_800443A8(u8* obj, s8 arg1);

void func_80043FA4(u8* obj) {
    s32 v;

    func_80043B88(obj);
    if (((s8*)obj)[6] == 0) {
        obj[6]++;
    } else {
        func_80017248(obj);
        func_800443A8(obj, (obj[0x45] & 0x7F) + 0x26);
    }
    if (*(u16*)(obj + 0x80) & 2) {
        obj[0x15] = 0;
    }
    if (*(u16*)(obj + 0x80) & 1) {
        obj[0x15] = 0x40;
    }
    if (((s8*)obj)[0xD3] == 0) {
        obj[0x8E] = 0;
        if (*(u16*)(obj + 0x80) & 0x80) {
            func_8003A874(obj);
            return;
        }
        obj[0x8E] = 1;
    }
    if (((s8*)obj)[0x46] == 0) {
        obj[0x8E] = 0;
        v = func_800306E0(obj);
        if (v == 0x2E) {
            v = 0x1B;
        } else {
            v = 0x1C;
        }
        obj[5] = v;
        obj[6] = 1;
    }
}
