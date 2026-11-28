#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

extern void func_8003A94C(void);
extern s32 func_8003EFE0(u8* arg0);
extern void (*D_80074CD8[])(u8*);

void update_hover(u8* arg0) {
    if (((s8*)arg0)[0xD3] != 0) {
        func_8003A94C();
    } else if (func_8003EFE0(arg0) == 0) {
        animate_object(arg0);
        D_80074CD8[(s8)arg0[6]](arg0);
    }
}

extern void func_8003C5D8(void);
extern void func_8003AA4C(u8* arg0);
extern void (*D_80074D04[])(u8*);

void func_800402DC(u8* arg0) {
    if (((s8*)arg0)[0xD3] != 0) {
        arg0[0xF3] = 0;
        func_8003C5D8();
        func_8003AA4C(arg0);
    } else {
        animate_object(arg0);
        D_80074D04[(s8)arg0[6]](arg0);
    }
}

extern void func_8003A94C(void);
extern void (*D_80074D10[])(Obj440A8*);

void func_80040350(Obj440A8* obj) {
    if (obj->unkD3 != 0) {
        func_8003A94C();
        return;
    }
    animate_object(obj);
    D_80074D10[obj->state](obj);
    if (obj->unk5 != 0x23) {
        obj->unk7A = 0;
    }
}

#define D_800FA778_ovl09 D_80074D34

#define func_800EF37C_ovl09 func_800403D0
#include "shared/func_800EF37C_ovl09.c"
#undef func_800EF37C_ovl09
#undef D_800FA778_ovl09

#define D_800FA778_ovl09 D_80074D44

#define func_800EF37C_ovl09 func_80040418
#include "shared/func_800EF37C_ovl09.c"
#undef func_800EF37C_ovl09
#undef D_800FA778_ovl09

extern void func_8003AA4C(u8* arg0);

void func_80040460(u8* obj) {
    animate_object(obj);
    if (((s8*)obj)[0x45] & 0x80) {
        obj[0x45] &= 0x7F;
    }
    if (((s8*)obj)[0x46] == 0) {
        func_8003AA4C(obj);
    }
}

extern void func_8003AA4C(u8* arg0);

void func_800404B4(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0 || *(s8*)(obj + 0x93) != 4) {
        func_8003AA4C(obj);
    }
}

extern void func_8003AA4C(u8* obj);

void func_80040500(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0 || *(s8*)(obj + 0x93) != 5) {
        func_8003AA4C(obj);
    }
}

extern void func_8003AA4C(u8* arg0);

void func_8004054C(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x99) == 0 || *(s8*)(obj + 0x93) != 3) {
        func_8003AA4C(obj);
    }
}

extern void func_8003AA4C(u8* obj);

void func_80040598(u8* p) {
    animate_object(p);
    if (*(s8*)(p + 0x46) == 0 || *(s8*)(p + 0x93) != 1) {
        func_8003AA4C(p);
    }
}

extern void func_8003AA4C(u8* arg0);
extern void (*D_80074D54[])(u8*);

void func_800405E4(u8* obj) {
    animate_object(obj);
    D_80074D54[((s8*)obj)[6]](obj);
    if (((s8*)obj)[5] != 0x29 || ((s8*)obj)[0x93] != 8) {
        func_8003AA4C(obj);
    }
}

extern void func_8003AA4C(u8* arg0);

void func_80040654(u8* obj) {
    if (*(s8*)(obj + 6) != 0) {
        if (obj[0x89] & 8) {
            *(s8*)(obj + 6) = 0;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
            if (obj[0x17] != 0x6C) {
                func_8003B33C(obj, 0x58);
            }
        } else {
            apply_object_motion(obj);
        }
    } else if (obj[0x89] & 8) {
        *(s8*)(obj + 6) = 1;
    }
    if (*(s8*)(obj + 7) != 0 || *(s8*)(obj + 0x93) != 6 ||
        *(s8*)(obj + 0x99) == 0 || *(s8*)(obj + 0x98) == 0) {
        func_8003AA4C(obj);
    }
}
