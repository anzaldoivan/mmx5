#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"

extern s32 func_80038850(u8* self);
extern s32 try_enter_wall_cling(void* self);
extern s32 try_grab_ladder_from_air(u8* obj);
extern void func_8003D344(void* arg0);

void func_80043344(u8* obj) {
    u8* child;

    if (obj[0x89] & 8) {
        func_8003B33C(obj, 0x63);
        obj[0x67] = 0;
        obj[0x84] = 0;
        obj[0x86] = 0;
        obj[0x8C] = 0;
        if (*(s8*)(obj + 0xD3) == 0) {
            child = func_8002D27C();
            if (child != 0) {
                child[0] = 1;
                child[1] = 0x3F;
                child[2] = 0;
                child[0x14] = obj[0x14];
                if (obj[0x15] == 0) {
                    *(s16*)(child + 0xA) = *(s16*)(obj + 0xA) - 8;
                } else {
                    *(s16*)(child + 0xA) = *(s16*)(obj + 0xA) + 8;
                }
                *(s16*)(child + 0xE) = *(s16*)(obj + 0xE) + 0x18;
            }
        }
        obj[6]++;
        return;
    }
    obj[0x8E] = 0;
    if (try_grab_ladder_from_air(obj) == 0 && try_enter_wall_cling(obj) == 0 &&
        func_80038850(obj) == 0) {
        obj[0x8E] = 1;
        *(s32*)(obj + 0x20) = 0;
        if (*(s8*)(obj + 0xD3) == 0) {
            if (*(u16*)(obj + 0x7C) & 2) {
                *(s32*)(obj + 0x20) = 0xFFFE8000;
            }
            if (*(u16*)(obj + 0x7C) & 1) {
                *(s32*)(obj + 0x20) = 0x18000;
            }
        }
        apply_object_motion(obj);
        func_8003D344(obj);
    }
}

extern s32 func_8003952C(u8* arg0);
extern s32 func_80041C80(u8* p);
extern s32 func_80044228(u8* p);
extern s32 func_80041B84(u8* p);
extern s32 func_80044328(u8*);
extern void func_8003CF74(u8*, s32);
extern void func_80042090(u8*);
extern s32 try_enter_ladder(u8* arg0);
extern s32 check_crouch_input(u8* arg0);
extern s32 func_800395E8(u8* arg0);
extern void func_8003A7E4(u8* arg0);
extern void func_8003B1A8(u8* a0);
extern void func_8003A418(u8* a0);
extern void func_8003A670(u8* arg0);
extern s8 D_800D1C0F;

static inline s32 func_800434A4_probe(u8* p) {
    if (*(s8*)(p + 2) != 0 && *(s8*)(p + 0xD3) == 0) {
        p[0x156] = 1;
        if (func_80041C80(p) != 0) {
            return 1;
        }
        if (func_80044228(p) != 0) {
            return 1;
        }
        if (func_80041B84(p) != 0) {
            return 1;
        }
        p[0x156] = 0;
    }
    return 0;
}

static inline s32 func_800434A4_reset(u8* p) {
    if (func_80044328(p) == 0) {
        return 0;
    }
    func_8003B33C(p, 0x58);
    play_sound(1, 7, p);
    if (random_byte() & 4) {
        func_8003CF74(p, 3);
    }
    p[0x84] = 0;
    p[0x86] = 0;
    p[5] = 0x30;
    p[6] = 0;
    func_80042090(p);
    return 1;
}

static inline s32 func_800434A4_check(u8* p) {
    if (try_enter_ladder(p) != 0) {
        return 1;
    }
    if (check_crouch_input(p) != 0) {
        return 1;
    }
    if (func_800395E8(p) != 0) {
        func_8003A7E4(p);
        return 1;
    }
    return 0;
}

void func_800434A4(u8* p) {
    if (*(s8*)(p + 0xD3) == 0) {
        p[0x8E] = 0;
        if (func_8003952C(p) != 0) {
            return;
        }
        if (p[0x45] & 0x40) {
            if (func_800434A4_probe(p) != 0) {
                return;
            }
            if (func_800434A4_reset(p) != 0) {
                return;
            }
            if (func_800434A4_check(p) != 0) {
                return;
            }
        }
        p[0x8E] = 1;
    }
    if (*(s8*)(p + 0x46) == 0) {
        p[0x8E] = 0;
        if (D_800D1C0F != 0) {
            func_8003B1A8(p);
            return;
        }
        if (*(s8*)(p + 0xD0) != 0) {
            func_8003A418(p);
            return;
        }
        func_8003A670(p);
    }
}
