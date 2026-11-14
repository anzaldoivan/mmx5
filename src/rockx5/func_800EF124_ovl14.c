#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8* func_8002D1A4();
extern void func_800171E8(u8* obj, s32 state);
extern Tbl800EE974 D_800EE974_ovl14;
extern u8 D_800F1F38_ovl14[][6];

void func_800EF124_ovl14(u8* obj) {
    Tbl800EE974 t = D_800EE974_ovl14;
    u8* p;
    s32 i;

    if (((s8*)obj)[0x45] == 4) {
        obj[0x45] = 0;
        func_80016490(2, 0x44, obj);
    }
    if (((s8*)obj)[0x45] == 5) {
        obj[0x45] = 0;
        func_80016490(2, 0x3A, obj);
    }
    if (((s8*)obj)[0x45] == 6) {
        obj[0x45] = 0;
        func_80016490(2, 0x3B, obj);
    }
    if (((s8*)obj)[0x45] == 7) {
        obj[0x45] = 0;
        func_80016490(2, 0x3C, obj);
    }
    if (((s8*)obj)[0x45] == 8) {
        obj[0x45] = 0;
        func_80016490(2, 0x45, obj);
    }
    if (((s8*)obj)[0x45] == 1) {
        obj[0x45] = 0;
        func_80016490(2, 0x46, obj);
        for (i = 0; i < 5; i++) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 4;
                *(u8**)(p + 0x7C) = obj;
                *(s16*)(p + 0xA) = t.a[0][i];
                *(s32*)(p + 0x90) = i;
            }
        }
    }
    if (((s8*)obj)[0x45] == 2) {
        obj[0x45] = 0;
        func_80016490(2, 0x46, obj);
        for (i = 0; i < 5; i++) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 4;
                *(u8**)(p + 0x7C) = obj;
                if (obj[0x15] == 0) {
                    *(s16*)(p + 0xA) = t.a[1][i];
                } else {
                    *(s16*)(p + 0xA) = t.a[2][i];
                }
                *(s32*)(p + 0x90) = i;
            }
        }
    }
    if (((s8*)obj)[0x45] == 3) {
        obj[0x45] = 0;
        func_80016490(2, 0x46, obj);
        for (i = 0; i < 5; i++) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 4;
                *(u8**)(p + 0x7C) = obj;
                if (obj[0x15] == 0) {
                    *(s16*)(p + 0xA) = t.a[2][i];
                } else {
                    *(s16*)(p + 0xA) = t.a[1][i];
                }
                *(s32*)(p + 0x90) = i;
            }
        }
    }
    if (((s8*)obj)[0x46] == 0) {
        func_800171E8(obj, 1);
        obj[5] = D_800F1F38_ovl14[obj[0x86]][obj[0x87]++];
        obj[6] = 0;
    }
}
