#include "types.h"
#include "addr.h"

extern u8 D_8009A197;
extern void (*D_800F52EC_ovl05[])(u8*);
extern u8 D_800F52B4_ovl05[];
extern void func_800F0990_ovl05(u8* obj);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002FB58(u8* obj);

void func_800EF9BC_ovl05(u8* obj) {
    s32 r;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        func_800F0990_ovl05(obj);
        func_80017248(obj);
        D_800F52EC_ovl05[*(signed char*)(obj + 5)](obj);
    }
    func_800317B8(obj);
    D_1F80004C.bytes[0x85] = 0;
    r = func_80031DD0(obj);
    if (r < 0) {
        func_8004D4F4(6, D_800F52B4_ovl05, obj);
        obj[3] = 0;
        *(s16*)(obj + 0x7C) = 0xF;
        *(s16*)(obj + 0x7E) = 5;
        func_80054440(obj, 0x12);
        obj[4] = 5;
        return;
    }
    if (r > 0) {
        D_1F80004C.bytes[0x85] = 1;
    }
    if ((obj[0x70] & 0xC) == 0xC || (obj[0x70] & 3) == 3) {
        func_8004D4F4(6, D_800F52B4_ovl05, obj);
        obj[3] = 0;
        *(s16*)(obj + 0x7C) = 0xF;
        *(s16*)(obj + 0x7E) = 5;
        obj[4] = 5;
        return;
    }
    if (func_8002D938(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
    } else {
        obj[4] = 3;
    }
    func_8002FB58(obj);
}
