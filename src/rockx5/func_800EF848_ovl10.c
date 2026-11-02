#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern void func_80054440(u8* a0, s32 a1);
extern s32 func_800317B8(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D7A0();
extern u8 D_8009A197;
extern void* D_800FB39C_ovl10[];
extern u8 D_800FB340_ovl10[];
extern u8 D_800FB348_ovl10[];
extern u8 D_800FB34C_ovl10[];
extern u8 D_800FB350_ovl10[];
extern u8 D_800FB354_ovl10[];
extern u8 D_800FB358_ovl10[];
extern u8 D_800FB35C_ovl10[];
extern u8 D_800FB360_ovl10[];
extern u8 D_800FB364_ovl10[];
extern u8 D_800FB368_ovl10[];
extern u8 D_800FB36C_ovl10[];
extern u8 D_800FB370_ovl10[];
extern u8 D_800FB374_ovl10[];
extern u8 D_80075340[];
extern u8 D_80074EE0[];

void func_800EF848_ovl10(u8* o) {
    s32 r;
    u8 st;
    s8 t;
    u8* a;

    if (D_8009A197 == 0) {
        ((void (*)(u8*))D_800FB39C_ovl10[*(s8*)(o + 5)])(o);
    }
    if (*(s8*)(o + 0x45) == 2 || o[0x47] == 0x12 || o[0x47] == 0x24 ||
        o[0x47] == 0x32 || o[0x47] == 0x27) {
        *(u8**)(o + 0x54) = 0;
        *(u8**)(o + 0x50) = 0;
        if (*(s8*)(o + 2) != 0) {
            *(u8**)(o + 0x68) = D_800FB364_ovl10;
        } else {
            *(u8**)(o + 0x68) = D_800FB370_ovl10;
        }
    } else {
        if (*(s8*)(o + 2) != 0) {
            *(u8**)(o + 0x54) = D_800FB35C_ovl10;
            *(u8**)(o + 0x50) = D_800FB35C_ovl10;
        } else {
            *(u8**)(o + 0x54) = D_800FB350_ovl10;
            *(u8**)(o + 0x50) = D_800FB350_ovl10;
        }
        if (*(s8*)(o + 0x45) == 3) {
            *(u8**)(o + 0x54) = 0;
            *(u8**)(o + 0x50) = 0;
            if (*(s8*)(o + 2) != 0) {
                a = D_800FB364_ovl10;
            } else {
                a = D_800FB370_ovl10;
            }
            *(u8**)(o + 0x68) = a;
        }
        *(u8**)(o + 0x58) = D_80075340;
        r = func_80031DD0(o);
        if (r < 0) {
            func_80054440(o, 0x12);
            goto die; // !FAKE: goto kept for the matching branch layout
        }
        if (r == 0) {
            if (*(s8*)(o + 2) != 0) {
                t = *(s8*)(o + 0x45);
                if (t == 3 || t == 10) {
                    *(u8**)(o + 0x54) = D_800FB358_ovl10;
                    *(u8**)(o + 0x50) = D_800FB358_ovl10;
                    *(u8**)(o + 0x68) = D_800FB374_ovl10;
                } else {
                    *(u8**)(o + 0x54) = D_800FB354_ovl10;
                    *(u8**)(o + 0x50) = D_800FB354_ovl10;
                    *(u8**)(o + 0x68) = D_800FB36C_ovl10;
                }
                st = o[0x47];
                if (st == 0x29 || st == 0x31) {
                    *(u8**)(o + 0x54) = D_800FB35C_ovl10;
                    *(u8**)(o + 0x50) = D_800FB35C_ovl10;
                }
            } else {
                t = *(s8*)(o + 0x45);
                if (t == 3 || t == 10) {
                    *(u8**)(o + 0x54) = D_800FB34C_ovl10;
                    *(u8**)(o + 0x50) = D_800FB34C_ovl10;
                    *(u8**)(o + 0x68) = D_800FB368_ovl10;
                } else {
                    *(u8**)(o + 0x54) = D_800FB348_ovl10;
                    *(u8**)(o + 0x50) = D_800FB348_ovl10;
                    *(u8**)(o + 0x68) = D_800FB360_ovl10;
                }
                st = o[0x47];
                if (st == 0x14 || st == 0x23) {
                    *(u8**)(o + 0x54) = D_800FB350_ovl10;
                    *(u8**)(o + 0x50) = D_800FB350_ovl10;
                }
            }
            *(u8**)(o + 0x58) = D_80074EE0;
            func_800317B8(o);
            func_80031DD0(o);
        }
    }
    if (*(s32*)(o + 0x70) & 6) {
    die:
        func_8004FD24(o);
        func_8004D4F4(5, D_800FB340_ovl10, o);
        o[4] = 2;
        return;
    }
    if (func_8002D938(o, 0x40, 0x40) == 0) {
        func_8002D9EC(o, 0x40, 0x40);
        return;
    }
    func_8002D7A0(o);
}
