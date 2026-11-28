#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/globals.h"

extern void func_8003AA4C(u8* arg0);

void func_80043DBC(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        player_spawn_weapon(1, 0x21, 0, obj);
        obj[6]++;
    } else {
        animate_object(obj);
    }
    if (((s8*)obj)[0x46] == 0) {
        func_8003AA4C(obj);
    }
}

#define D_800FA778_ovl09 D_80074D7C

#define func_800EF37C_ovl09 func_80043E30
#include "shared/func_800EF37C_ovl09.c"
#undef func_800EF37C_ovl09
#undef D_800FA778_ovl09

extern void (*D_80074D88[])(u8* obj);

void func_80043E78(u8* obj) {
    animate_object(obj);
    if (((s8*)obj)[6] != 0) {
        obj[0x4F]++;
    }
    if (obj[0x4B] == 0xFF && !(*(u16*)(obj + 0x7C) & 0x10)) {
        obj[0x4B] = obj[0x4F];
    }
    D_80074D88[((s8*)obj)[6]](obj);
}

extern u8* func_8002D078();
extern s32 func_80044730(u8* arg0);
extern void func_8003A670(u8* arg0);

void func_80043F10(u8* obj) {
    s8 state = ((s8*)obj)[6];
    u8* p;

    if (state == 0) {
        p = func_8002D078();
        if (p != 0) {
            p[0] = 0x11;
            p[1] = 0x1D;
        }
        obj[6]++;
    } else if (state == 1) {
        animate_object(obj);
        func_80044730(obj);
    } else if (state == 2) {
        func_8003A670(obj);
    }
}

extern s32 func_800306E0(u8* obj);
extern void func_8003A874(u8* obj);
extern void func_800443A8(u8* obj, s8 arg1);

void func_80043FA4(u8* obj) {
    s32 v;

    func_80043B88(obj);
    if (((s8*)obj)[6] == 0) {
        obj[6]++;
    } else {
        animate_object(obj);
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

extern void func_8003A94C(void);
extern void (*D_80074D64[])(Obj440A8*);

void func_800440A8(Obj440A8* obj) {
    if (obj->unkD3 != 0) {
        func_8003A94C();
        return;
    }
    animate_object(obj);
    D_80074D64[obj->state](obj);
    if (obj->unk5 != 0x37 && obj->unk14B != -1) {
        obj->unk7A = 0;
    }
}
