#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

extern void func_8003CD08(u8* obj);
extern s32 func_8003F414(u8* arg0);
extern s32 func_8003952C(u8* arg0);
extern s32 func_80043C64(u8* arg0);
extern s32 func_80041A54(u8* arg0);
extern s32 func_800395E8(u8* arg0);
extern void func_8003A7E4(u8* arg0);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);
extern void func_8003CD60(u8* obj);
extern void func_8003A670(u8* arg0);

void func_80035864(u8* obj) {
    s8 state;
    s8 kind;
    s8 save;

    func_8003CD08(obj);
    func_80043B88(obj);
    if (*(u16*)(obj + 0x80) & 2) {
        obj[0x15] = 0;
    }
    if (*(u16*)(obj + 0x80) & 1) {
        obj[0x15] = 0x40;
    }
    if (func_80039ECC(obj) != 0) {
        return;
    }
    if (func_8003F414(obj) != 0) {
        return;
    }
    if (func_8003952C(obj) != 0) {
        return;
    }
    if (func_80043C64(obj) != 0) {
        return;
    }
    if (func_80041A54(obj) != 0) {
        return;
    }
    if (!(*(u16*)(obj + 0x7C) & 8) && func_800395E8(obj) != 0) {
        func_8003A7E4(obj);
        return;
    }
    animate_object(obj);
    state = *(s8*)(obj + 0x6);
    if (state == 0) {
        if (*(s8*)(obj + 0x8F) != 0 && *(s8*)(obj + 0x2) == 0) {
            save = *(s8*)(obj + 0x44);
            func_8003B4CC(obj, 0x6D, obj[0x45] & 0x3F);
            *(s8*)(obj + 0x44) = save;
        }
        if (*(s8*)(obj + 0x46) == 0) {
            obj[0x6]++;
        }
    } else if (state == 1) {
        func_8003CD60(obj);
        if (*(s8*)(obj + 0x8F) != 0 && *(s8*)(obj + 0x2) == 0) {
            kind = *(s8*)(obj + 0x96);
            if (kind == 0x12 || kind == 0x14 || kind == 0x2E) {
                func_8003B33C(obj, 0x8B);
            } else {
                func_8003B33C(obj, 0x6C);
            }
        } else if (*(s8*)(obj + 0x8E) == 0 && *(s8*)(obj + 0x2) == 0) {
            func_8003B4CC(obj, 0x51, 2);
        }
        if (!(*(u16*)(obj + 0x7C) & 8)) {
            if ((*(u32*)(obj + 0x8C) & 0xFFFF0000) && *(s8*)(obj + 0x2) == 0) {
                func_8003B33C(obj, 0x6E);
            } else {
                func_8003B33C(obj, 0x52);
            }
            obj[0x6] = 2;
        }
    } else if (*(s8*)(obj + 0x46) == 0) {
        func_8003A670(obj);
    }
}

extern s32 func_8003E0C0(u8* arg0);
extern s32 func_8003A084(u8* arg0);
extern s32 func_80041774(u8* arg0);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);
extern void func_80038388(u8* arg0);
extern void func_800381BC(u8* arg0);

void func_80035AD4(u8* arg0) {
    s8 saved;

    func_80043B88(arg0);
    if (*(u16*)(arg0 + 0x7C) & 2) {
        arg0[0x15] = 0;
    }
    if (*(u16*)(arg0 + 0x7C) & 1) {
        arg0[0x15] = 0x40;
    }
    if (func_8003E0C0(arg0) != 0) {
        return;
    }
    if (func_8003A084(arg0) != 0) {
        return;
    }
    if (func_80041774(arg0) != 0) {
        return;
    }
    if (*(s8*)(arg0 + 0x6) == 0) {
        animate_object(arg0);
        if (*(s8*)(arg0 + 0x8F) != 0 && *(s8*)(arg0 + 0x2) == 0) {
            saved = *(s8*)(arg0 + 0x44);
            func_8003B4CC(arg0, 0x90, arg0[0x45] & 0x3F);
            *(s8*)(arg0 + 0x44) = saved;
        }
        if (*(s8*)(arg0 + 0x46) == 0) {
            arg0[0x6] = 1;
        }
    } else {
        func_80038388(arg0);
        func_800381BC(arg0);
        if (*(s32*)(arg0 + 0x1C) != *(s32*)(arg0 + 0xC)) {
            if (*(s8*)(arg0 + 0x157) == 0) {
                play_sound(0, 0x27, arg0);
            }
            if (++*(s8*)(arg0 + 0x157) < 21) {
                return;
            }
        }
        arg0[0x157] = 0;
    }
}

extern s32 func_8003E0C0(u8* arg0);
extern s32 func_8003A084(u8* arg0);
extern s32 func_800418DC(u8* arg0);
extern s32 func_800306E0(u8* arg0);
extern s32 func_8003A134(u8* arg0, s32 arg1);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);
extern void func_80038748(u8* arg0);
extern void func_80038488(u8* arg0);

void func_80035C30(u8* arg0) {
    s8 saved;

    func_80043B88(arg0);
    if (*(u16*)(arg0 + 0x7C) & 2) {
        arg0[0x15] = 0;
    }
    if (*(u16*)(arg0 + 0x7C) & 1) {
        arg0[0x15] = 0x40;
    }
    if (func_8003E0C0(arg0) != 0) {
        return;
    }
    if (func_8003A084(arg0) != 0) {
        return;
    }
    if (func_800418DC(arg0) != 0) {
        return;
    }
    if (*(s8*)(arg0 + 0x6) == 0) {
        animate_object(arg0);
        if (*(s8*)(arg0 + 0x8F) != 0 && *(s8*)(arg0 + 0x2) == 0) {
            saved = *(s8*)(arg0 + 0x44);
            func_8003B4CC(
                arg0, func_8003A134(arg0, func_800306E0(arg0) & 0xFF) + 0x94,
                arg0[0x45] & 0x3F);
            *(s8*)(arg0 + 0x44) = saved;
        }
        if (*(s8*)(arg0 + 0x46) == 0) {
            arg0[0x6] = 1;
        }
    } else {
        func_80038748(arg0);
        func_80038488(arg0);
        if (*(s32*)(arg0 + 0x18) != *(s32*)(arg0 + 0x8)) {
            if (*(s8*)(arg0 + 0x157) == 0) {
                play_sound(0, 0x27, arg0);
            }
            if (++*(s8*)(arg0 + 0x157) < 21) {
                return;
            }
        }
        arg0[0x157] = 0;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80036364.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80035DA4(void* arg0) {
    s8 temp_v1;

    ((void (*)())animate_object)(arg0);
    apply_object_motion(arg0);
    temp_v1 = M2C_FIELD(arg0, s8*, 6);
    if (temp_v1 == 2) {
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            func_80039ECC(arg0);
        }
    } else if (temp_v1 == 1) {
        if (M2C_FIELD(arg0, s32*, 0x20) <= 0) {
            ((void (*)(void*, s32))func_8003B33C)(arg0, 0x52);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    } else if (temp_v1 == 0) {
        if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
            M2C_FIELD(arg0, u8*, 0x45) = M2C_FIELD(arg0, u8*, 0x45) & 0x3F;
            play_sound(1, 1, arg0);
        }
        if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
            ((void (*)(void*, s32))func_8003B33C)(arg0, 0xB);
            M2C_FIELD(arg0, s8*, 0x67) = -1;
        }
        if ((M2C_FIELD(arg0, s8*, 0x67) == -1) &&
            (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
            ((void (*)(void*, s32))func_8003B33C)(arg0, 0x51);
            M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
            M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}
#undef M2C_FIELD

extern void func_8003D344(void* arg0);
extern u8 D_8009A1F8[];

void func_80035EDC(u8* obj) {
    u8* p;
    u16 v;

    animate_object(obj);
    if (((s8*)obj)[6] == 0) {
        if (((s8*)obj)[0x46] == 0) {
            p = D_8009A1F8;
            v = *(u16*)(p + 0xE);
            *(s16*)(p + 0x28) = v;
            *(s16*)(p + 0x2A) = v;
            *(s16*)(p + 0x20) = v;
            *(s16*)(p + 0x22) = v;
            func_8003B33C(obj, 4);
            obj[6]++;
        }
    } else if (is_off_screen(obj, 0x20, 0x40) == 0) {
        move_object(obj);
        func_8003D344(obj);
    } else {
        obj[3] = 0;
        obj[4] = 3;
        obj[5] = 0;
        obj[6] = 0;
    }
}

void func_8003CD08(u8* arg0);
s32 try_enter_ladder(u8* arg0);
s32 func_8003EF28(u8* arg0);
s32 func_800437FC(u8* arg0);
s32 func_8003952C(u8* arg0);
s32 func_8004387C(u8* arg0);
s32 func_80041A54(u8* arg0);
s32 check_crouch_input(u8* arg0);
s32 func_800395E8(u8* arg0);
void func_8003A7E4(u8* arg0);
void func_800400A4(u8* arg0);

void func_80035F90(u8* arg0) {
    func_8003CD08(arg0);
    func_80043B88(arg0);
    if (func_80039ECC(arg0) != 0) {
        return;
    }
    if (try_enter_ladder(arg0) != 0) {
        return;
    }
    if (func_8003EF28(arg0) != 0) {
        return;
    }
    if (func_800437FC(arg0) != 0) {
        return;
    }
    if (func_8003952C(arg0) != 0) {
        return;
    }
    if (func_8004387C(arg0) != 0) {
        return;
    }
    if (func_80041A54(arg0) != 0) {
        return;
    }
    if (check_crouch_input(arg0) != 0) {
        return;
    }
    if (func_800395E8(arg0) != 0) {
        func_8003A7E4(arg0);
    } else {
        func_800400A4(arg0);
    }
}

s32 try_enter_ladder(u8* arg0);
s32 func_8003EF28(u8* arg0);
s32 func_800437FC(u8* arg0);
s32 func_8003952C(u8* arg0);
s32 func_8004387C(u8* arg0);
s32 func_80041A54(u8* arg0);
s32 func_800395E8(u8* arg0);
void func_8003A82C(u8* arg0);
void func_8003A70C(u8* arg0);

void func_80036064(u8* arg0) {
    func_80043B88(arg0);
    if (func_80039ECC(arg0) != 0) {
        return;
    }
    if (try_enter_ladder(arg0) != 0) {
        return;
    }
    if (func_8003EF28(arg0) != 0) {
        return;
    }
    if (func_800437FC(arg0) != 0) {
        return;
    }
    if (func_8003952C(arg0) != 0) {
        return;
    }
    if (func_8004387C(arg0) != 0) {
        return;
    }
    if (func_80041A54(arg0) != 0) {
        return;
    }
    if (func_800395E8(arg0) != 0) {
        animate_object(arg0);
        if (*(signed char*)(arg0 + 0x46) < 0) {
            func_8003A82C(arg0);
        } else {
            move_object(arg0);
            func_8003F2D8(arg0, 7);
        }
    } else {
        func_8003A70C(arg0);
    }
}

s32 try_enter_ladder(u8* arg0);
s32 func_8003EF28(u8* arg0);
s32 func_800437FC(u8* arg0);
s32 func_8003952C(u8* arg0);
s32 func_8004387C(u8* arg0);
s32 func_80041A54(u8* arg0);
s32 func_80039668(u8* arg0);
void func_8003A70C(u8* arg0);

void func_80036154(u8* arg0) {
    func_80043B88(arg0);
    if (func_80039ECC(arg0) != 0) {
        return;
    }
    if (try_enter_ladder(arg0) != 0) {
        return;
    }
    if (func_8003EF28(arg0) != 0) {
        return;
    }
    if (func_800437FC(arg0) != 0) {
        return;
    }
    if (func_8003952C(arg0) != 0) {
        return;
    }
    if (func_8004387C(arg0) != 0) {
        return;
    }
    if (func_80041A54(arg0) != 0) {
        return;
    }
    if (func_80039668(arg0) != 0) {
        animate_object(arg0);
        move_object(arg0);
        func_8003F2D8(arg0, 8);
    } else {
        func_8003A70C(arg0);
    }
}

s32 try_enter_ladder(u8* arg0);
s32 func_800437FC(u8* arg0);
s32 func_8003952C(u8* arg0);
s32 func_8004387C(u8* arg0);
s32 func_80041A54(u8* arg0);
s32 func_800395E8(u8* arg0);
void func_8003A7E4(u8* arg0);
void func_8003A670(u8* arg0);

void func_80036224(u8* arg0) {
    func_80043B88(arg0);
    if (func_80039ECC(arg0) != 0) {
        return;
    }
    if (try_enter_ladder(arg0) != 0) {
        return;
    }
    if (func_800437FC(arg0) != 0) {
        return;
    }
    if (func_8003952C(arg0) != 0) {
        return;
    }
    if (func_8004387C(arg0) != 0) {
        return;
    }
    if (func_80041A54(arg0) != 0) {
        return;
    }
    if (func_800395E8(arg0) != 0) {
        func_8003A7E4(arg0);
    } else {
        animate_object(arg0);
        if (((signed char*)arg0)[0x46] < 0) {
            func_8003A670(arg0);
        }
    }
}

extern void func_8003A9AC(u8* arg0);
extern s32 func_8003EFE0(u8* arg0);
extern s32 func_800439A8(u8* obj);
extern s32 try_grab_ladder_from_air(u8* obj);
extern s32 func_800390A4(u8* p);
extern s32 try_enter_wall_cling(void* self);
extern s32 func_80038850(u8* self);
extern void func_8003D120(u8* obj);
extern void func_8003D344(void* arg0);

void func_800362E8(u8* arg0) {
    func_80043B88(arg0);
    if (arg0[0x89] & 8) {
        func_8003A9AC(arg0);
        return;
    }
    if (func_8003EFE0(arg0) == 0 && func_800439A8(arg0) == 0 &&
        try_grab_ladder_from_air(arg0) == 0 && func_800390A4(arg0) == 0 &&
        try_enter_wall_cling(arg0) == 0 && func_80038850(arg0) == 0) {
        animate_object(arg0);
        func_8003D120(arg0);
        func_8003D344(arg0);
        func_8003F2D8(arg0, 0xB);
    }
}

s32 try_enter_ladder(u8* arg0);
s32 func_8003EF28(u8* arg0);
s32 func_800437FC(u8* arg0);
s32 player_check_dash_jump_walk(u8* arg0);
s32 func_8004387C(u8* arg0);
s32 func_80041A54(u8* arg0);
s32 check_crouch_input(u8* arg0);
void func_8003A70C(u8* arg0);

void func_800363B4(u8* arg0) {
    func_80043B88(arg0);
    if (func_80039ECC(arg0) != 0) {
        return;
    }
    if (try_enter_ladder(arg0) != 0) {
        return;
    }
    if (func_8003EF28(arg0) != 0) {
        return;
    }
    if (func_800437FC(arg0) != 0) {
        return;
    }
    if (player_check_dash_jump_walk(arg0) != 0) {
        return;
    }
    if (func_8004387C(arg0) != 0) {
        return;
    }
    if (func_80041A54(arg0) != 0) {
        return;
    }
    if (check_crouch_input(arg0) != 0) {
        return;
    }
    animate_object(arg0);
    if (((signed char*)arg0)[0x46] < 0) {
        func_8003A70C(arg0);
    } else {
        func_8003F2D8(arg0, 0xC);
    }
}

extern void func_8003A9AC(u8* arg0);
extern s32 func_8003EFE0(u8* arg0);
extern void func_8003A94C(u8* arg0);
extern s32 try_wall_jump(u8* arg0);
extern void func_8003AE80(u8* arg0);

void func_80036488(u8* arg0) {
    s32 t;

    func_80043B88(arg0);
    if (arg0[0x89] & 8) {
        func_8003A9AC(arg0);
        return;
    }
    if (*(s8*)(arg0 + 0xD3) != 0) {
        goto block_a94c; // !FAKE: goto kept for the matching branch layout
    }
    {
        if (func_8003EFE0(arg0) != 0) {
            return;
        }
        if (!(arg0[0x89] & 3)) {
        block_a94c: // !FAKE: label kept for the matching branch layout
            func_8003A94C(arg0);
            return;
        }
        if (try_wall_jump(arg0) != 0) {
            return;
        }
        animate_object(arg0);
        if (*(s8*)(arg0 + 0x45) & 0x80) {
            if (arg0[0x89] & 1) {
                arg0[0x15] = 0;
            } else {
                arg0[0x15] = 0x40;
            }
            arg0[0x45] &= 0x3F;
        }
        t = arg0[0x8A] - 1;
        arg0[0x8A] = t;
        if ((t << 24) == 0) {
            func_8003AE80(arg0);
            return;
        }
        func_8003F2D8(arg0, 0xD);
    }
}

#include "shared/func_800365A4.c"
