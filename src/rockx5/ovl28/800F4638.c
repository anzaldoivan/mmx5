#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "addr.h"

void func_800F4638_ovl28(u8* obj) {
    u8* parent;
    u8* spawn;
    s32 kind;

    animate_object(obj);
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

extern u8* find_free_visual_obj(void);

void func_800F47A4_ovl28(u8* obj) {
    u8* p = *(u8**)(obj + 0x50);
    u8* n;
    s32 t;

    obj[3] = 1;
    animate_object(obj);
    *(s32*)(obj + 8) = *(s32*)(p + 8);
    *(s32*)(obj + 0xC) = *(s32*)(p + 0xC);
    if (((s8*)obj)[2] == 3) {
        if (((s8*)obj)[0x45] == 1) {
            n = find_free_visual_obj();
            if (n != 0) {
                n[0] = 0x61;
                n[1] = 0xB;
                n[2] = 4;
                *(u16*)(n + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(n + 0x30) = *(s32*)(obj + 0x30);
                *(s32*)(n + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(n + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                n[0x15] = obj[0x15];
                *(s32*)(n + 8) = *(s32*)(obj + 8);
                *(s32*)(n + 0xC) = *(s32*)(obj + 0xC);
                *(u8**)(n + 0x50) = p;
            }
        } else if (((s8*)obj)[0x45] == 2) {
            if (((s8*)p)[5] == 5) {
                obj[0x60] = (random_byte() & 3) * 10 + 10;
            } else {
                obj[0x60] = 10;
            }
        }
        t = (obj[0x5C] + 1) & 3;
        obj[0x5C] = t;
        if (t >= 2) {
            switch (p[0x8B]) {
            case 5:
                load_palette(0x13C, D_1F800030 + 0x60, 1);
                load_palette(0x13D, D_1F800030 + 0x80, 1);
                break;
            case 9:
                load_palette(0x13C, D_1F800030 + 0x120, 1);
                load_palette(0x13D, D_1F800030 + 0x140, 1);
                break;
            case 10:
                load_palette(0x13C, D_1F800030 + 0xE0, 1);
                load_palette(0x13D, D_1F800030 + 0x100, 1);
                break;
            case 11:
                load_palette(0x13C, D_1F800030 + 0xA0, 1);
                load_palette(0x13D, D_1F800030 + 0xC0, 1);
                break;
            }
            *(s16*)(obj + 0x42) = 0x7CCC;
        } else {
            if (((s8*)obj)[0x60] != 0 || ((s8*)p)[7] >= 2) {
                if (p[0x8B] != 5) {
                    load_palette(0x13C, D_1F800030 + 0x1A0, 1);
                    load_palette(0x13D, D_1F800030 + 0x1C0, 1);
                } else {
                    load_palette(0x13C, D_1F800030 + 0x220, 1);
                    load_palette(0x13D, D_1F800030 + 0x240, 1);
                }
                t = obj[0x60] - 1;
                obj[0x60] = t;
                if ((t << 24) == 0 && ((s8*)p)[7] == 1) {
                    p[7] = 2;
                }
            } else {
                load_palette(0x13C, D_1F800030 + 0x160, 1);
                load_palette(0x13D, D_1F800030 + 0x180, 1);
            }
            *(s16*)(obj + 0x42) = 0x7CCC;
        }
    }
    if (((s8*)p)[7] == 3) {
        obj[3] = 0;
        switch (p[0x8B]) {
        case 5:
            load_palette(0x13C, D_1F800030 + 0x60, 1);
            load_palette(0x13D, D_1F800030 + 0x80, 1);
            break;
        case 9:
            load_palette(0x13C, D_1F800030 + 0x120, 1);
            load_palette(0x13D, D_1F800030 + 0x140, 1);
            break;
        case 10:
            load_palette(0x13C, D_1F800030 + 0xE0, 1);
            load_palette(0x13D, D_1F800030 + 0x100, 1);
            break;
        case 11:
            load_palette(0x13C, D_1F800030 + 0xA0, 1);
            load_palette(0x13D, D_1F800030 + 0xC0, 1);
            break;
        }
        obj[4]++;
    }
}
