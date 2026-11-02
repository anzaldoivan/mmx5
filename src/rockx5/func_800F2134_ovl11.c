#include "types.h"
#include "addr.h"

extern u8 D_8009A197;
extern void (*D_800F9B34_ovl11[])(u8*);
extern u8 D_800F996C_ovl11[];
extern void func_800F2FF0_ovl11(u8* obj);
extern void func_800F22D8_ovl11(u8* o);
extern void func_800F24E8_ovl11(u8* o);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_80054440(u8* a0, s32 a1);
extern s32 func_8002D800(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D89C(u8*);

void func_800F2134_ovl11(u8* obj) {
    u8 v;
    u8 t;
    s32 r;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        v = D_1F80004C.bytes[0x85];
        if (v != 2 && v < 6) {
            func_800F2FF0_ovl11(obj);
        }
        func_800F22D8_ovl11(obj);
        if (D_1F80004C.bytes[0x86] == 0) {
            func_800F24E8_ovl11(obj);
        }
        D_800F9B34_ovl11[((s8*)obj)[5]](obj);
    }
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(5, D_800F996C_ovl11, obj);
        func_80054440(obj, 0x12);
        obj[4] = 2;
        return;
    }
    t = obj[0x70];
    if ((t & 0xC) == 0xC || (t & 3) == 3) {
        func_8004FD24(obj);
        func_8004D4F4(5, D_800F996C_ovl11, obj);
        r = 2;
    } else if (D_1F80004C.bytes[0x86] == 0) {
        if (func_8002D800(obj) == 0) {
            goto hit; // !FAKE: goto kept for the matching branch layout
        }
        obj[4] = 4;
        return;
    } else {
        if (func_8002D938(obj, 0x70, 0) == 0) {
        hit:
            func_8002D89C(obj);
            return;
        }
        r = 4;
    }
    obj[4] = r;
}
