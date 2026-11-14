#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_800317B8(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern s32 func_80031DD0(u8* a0);
extern void func_8002D6FC(u8* obj);
extern void* D_800FA0D0_ovl26[];
extern u8 D_800FA682_ovl26;
extern s32 D_800761A0[];
extern u8 D_8009A11A;
extern u8 D_80074EE0[];

void func_800F23D4_ovl26(u8* o) {
    u8* s;
    u8* p;
    u8* q;
    s32 k;
    s32 v;
    u8 c;
    u8 d;

    ((void (*)(u8*))D_800FA0D0_ovl26[((s8*)o)[5]])(o);
    k = ((s8*)o)[0x45];
    if (k == 0x40) {
        func_80016490(2, 0x5F, o);
    } else if (k == 0x41) {
        func_80016490(2, 0x60, o);
    } else if (k == 0x42) {
        func_80016490(2, 0x61, o);
    }
    if (D_1F80004C.bytes[0x8D] != 0 && o[2] == 0) {
        func_800317B8(o);
        if (D_800FA682_ovl26 == 1) {
            s = D_1F80004C.bytes;
            if (s[0x92] == 0) {
                s[0x8C] = 0;
                *(s32**)(o + 0x58) = D_800761A0;
                *(u16*)(o + 0x42) &= 0x7FFF;
            }
        }
        s = D_1F80004C.bytes;
        D_800FA682_ovl26 = s[0x92];
        c = s[0x92];
        if (c == 1) {
            v = *(s32*)(s + 0x88);
            o[0x5C] = s[0x95];
            if (v < 0) {
                if (o[0x47] == 0x4B) {
                    o[0x47] = 0x32;
                }
                D_8009A11A = c;
                o[4] = 2;
                o[5] = 0;
                return;
            }
            if (v > 0) {
                if (v != 0x7F) {
                    *(u8**)(o + 0x58) = D_80074EE0;
                    if ((u32)(v - 0x19) < 2) {
                        D_1F80004C.bytes[0x8C] = 2;
                    } else {
                        D_1F80004C.bytes[0x8C] = 0x1E;
                    }
                }
                if (v == 6 || v == 0xF || v == 0x25) {
                    if (D_1F80004C.bytes[0x8F] == 0 && !((u8)(o[5] - 10) < 2)) {
                        func_800171E8(o, 0x17);
                        D_1F80004C.bytes[0x8F] = 0x3C;
                    }
                }
            }
            q = D_1F80004C.bytes;
            d = q[0x8C];
            if (d != 0) {
                q[0x8C] = d + 0xFF;
                if (d & 2) {
                    *(u16*)(o + 0x42) |= 0x8000;
                } else {
                    *(u16*)(o + 0x42) &= 0x7FFF;
                }
                if (D_1F80004C.bytes[0x8C] == 0) {
                    *(s32**)(o + 0x58) = D_800761A0;
                    *(u16*)(o + 0x42) &= 0x7FFF;
                }
            }
        }
        func_8002D9EC(o, 0x60, 0x60);
        if (D_1F80004C.bytes[0x8F] != 0) {
            func_80017248(o);
            s = D_1F80004C.bytes;
            if (--s[0x8F] == 0) {
                if (((s8*)o)[5] == 5) {
                    func_800171E8(o, 0x30);
                }
                D_1F80004C.bytes[0x8C] = 0x3C;
            }
            p = func_8002D27C();
            if (p != 0 && (D_1F80004C.bytes[0x8F] & 7) == 0) {
                p[0] = 0x41;
                p[1] = 0x3D;
                p[2] = 0;
                *(s32*)(p + 0x3C) = *(s32*)(o + 0x3C);
                *(u16*)(p + 0x40) = *(u16*)(o + 0x40);
                *(s32*)(p + 0x30) = *(s32*)(o + 0x30);
                *(u16*)(p + 0x42) = *(u16*)(o + 0x42);
                *(u16*)(p + 0xA) =
                    *(u16*)(o + 0xA) + ((func_8002DF78() & 3) * 16 - 0x30);
                *(u16*)(p + 0xE) =
                    *(u16*)(o + 0xE) + ((func_8002DF78() & 3) * 16 - 0x20);
                p[0x15] = func_8002DF78() & 0x40;
                *(u8**)(p + 0x50) = o;
            }
        }
    } else if ((u8)(o[2] - 1) < 2) {
        *(s32**)(o + 0x58) = D_800761A0;
        if (*(u32*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x8C) & 0xFF0000FF) {
            *(u8**)(o + 0x58) = D_80074EE0;
        }
        *(s32*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x88) = func_80031DD0(o);
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x95] = o[0x5C];
        *(u16*)(o + 0x42) = *(u16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x42);
        *(void**)(o + 0x58) =
            *(void**)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x58);
        func_8002D9EC(o, 0x60, 0x60);
        if ((*(s8**)(D_1F80004C.bytes + 0x80))[4] == 2) {
            func_8002D6FC(o);
        }
    }
}
