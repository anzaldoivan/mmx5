#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"

void func_80055798(u8* obj) {
    u8* p = g_Player;
    s16 d;

    d = *(u16*)(p + 0xA) - *(u16*)(obj + 0xA);
    if (d < 0) {
        d = -d;
    }
    if (d < 0x41) {
        d = *(u16*)(p + 0xE) - *(u16*)(obj + 0xE);
        if (d > 0) {
            if (d >= 0x11) {
                return;
            }
        } else {
            d = -d;
            if (d >= 0x69) {
                return;
            }
        }
        set_animation(obj, 0xA);
        if (*(s32*)(p + 8) - *(s32*)(obj + 8) > 0) {
            func_8003D29C(0x14, 0);
            obj[0x15] = 0x40;
        } else {
            func_8003D29C(0x14, 0x40);
            obj[0x15] = 0;
        }
        obj[6] = 0;
        obj[5]++;
    }
}

extern s32 func_80017E54(s32);
extern void func_800177B0(s32, s32);
extern u8 D_800D1F3C;

void func_8005589C(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        if (((s8*)obj)[0x45] != 0) {
            func_80017E54(3);
            obj[0x45] = 0;
            obj[6]++;
        }
    } else if (D_800D1F3C == 0) {
        func_800177B0(0x13, 0x7F);
        obj[6] = 0;
        obj[5]++;
    }
}

extern u8 D_800D1F3C;
extern u8 D_8007C3B0[];
extern s8 D_8009A0A2;

void func_80055920(u8* obj) {
    if (D_800D1F3C == 2) {
        if (((s8*)obj)[2] == 8) {
            if (D_8009A0A2 < 0) {
                func_8002385C(0x55, 0xFF, 0);
            } else {
                func_8002385C(0x55, 0xFF, 0);
            }
        } else {
            func_8002385C(D_8007C3B0[((s8*)obj)[2]], 0xFF, 0);
        }
        obj[5]++;
    }
}

extern u8 D_80091C44;

void func_800559A8(u8* obj) {
    if (D_80091C44 == 1) {
        set_animation(obj, 0xB);
        obj[6] = 0;
        obj[5]++;
    }
}

extern s32 func_80017E54(s32);
extern void func_80017B84(void);
extern u8 D_800D1F3C;
extern u8 D_80091C44;

void func_800559F4(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        if (D_80091C44 == 0) {
            func_80017E54(3);
            obj[6]++;
        }
    } else if (D_800D1F3C == 0) {
        func_80017B84();
        set_animation(obj, 12);
        obj[6] = 0;
        obj[5]++;
    }
}

void func_80055A88(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) != 0) {
        func_8003D2C4();
        arg0[5]++;
    }
}

extern u8* find_free_visual_obj(void);

void func_80055AD0(u8* obj) {
    u8* g;
    u8* p;

    if (obj[0x72] & 8) {
        set_animation(obj, 1);
        g = g_Player;
        func_8003D29C(0x18, g[0x15]);
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 0;
            {
                u8 t = obj[0x14];
                *(u8**)(p + 0x50) = obj;
                p[0x14] = t;
            }
        }
        {
            s32 v = *(s32*)(obj + 8);
            g[0xF5] = 1;
            *(s32*)(g + 8) = v;
        }
        obj[5]++;
    }
}

extern u8* find_free_visual_obj(void);

void func_80055B78(u8* obj) {
    u8* g;
    u8* p;
    u8* q;
    u8* r;
    u8* w;
    u8 st;
    u8 id;

    g = g_Player;
    st = g[0xF5];
    *(s32*)(g + 8) = *(s32*)(obj + 8);
    if (st == 2) {
        id = 0x25;
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = id;
            p[2] = 0;
            {
                u8 t = obj[0x14];
                *(u8**)(p + 0x50) = obj;
                p[0x14] = t;
            }
        }
        q = find_free_visual_obj();
        if (q != 0) {
            q[0] = 0x41;
            q[1] = id;
            q[2] = 1;
            {
                u8 t = obj[0x14];
                *(u8**)(q + 0x50) = obj;
                q[0x14] = t;
            }
        }
        r = find_free_visual_obj();
        if (r != 0) {
            r[0] = 0x41;
            r[1] = id;
            r[2] = st;
            {
                u8 t = obj[0x14];
                *(u8**)(r + 0x50) = obj;
                r[0x14] = t;
            }
        }
        w = find_free_visual_obj();
        if (w != 0) {
            w[0] = 0x41;
            w[1] = id;
            w[2] = 3;
            {
                u8 t = obj[0x14];
                *(u8**)(w + 0x50) = obj;
                w[0x14] = t;
            }
        }
        obj[5]++;
    }
}

void func_80055C90(u8* obj) {
    u8* g = g_Player;

    *(s32*)(g + 8) = *(s32*)(obj + 8);
    if (g[0xF5] == 3) {
        set_animation(obj, 2);
        *(s32*)(obj + 0x7C) = 40;
        obj[5]++;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80051E9C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_8009A0A8;

void func_80055CEC(void* arg0) {
    s32 temp_v0;

    D_8009A0A8 = M2C_FIELD(arg0, s32*, 8);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x7C);
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
        return;
    }
    M2C_FIELD(arg0, s32*, 0x7C) = (s32)(temp_v0 - 1);
}
#undef M2C_FIELD

extern void func_8003C5D8(u8* obj);
extern u8 D_800D1C00[];
extern u8 D_800D1C4B;
extern u8 D_8007C370[];

void func_80055D24(u8* obj) {
    u8* player = g_Player;

    *(s32*)(player + 8) = *(s32*)(obj + 8);
    player[0xF5] = 4;
    set_animation(obj, 0xD);
    if (((s8*)obj)[2] == 8) {
        if (((s8*)player)[2] == 0) {
            D_800D1C4B = 1;
        } else {
            D_800D1C00[0x4A] |= 0x10;
            func_8003C5D8(player);
        }
    } else {
        D_800D1C00[0xA1] |= D_8007C370[((s8*)obj)[2]];
    }
    obj[5]++;
}

void func_80055DEC(u8* arg0) {
    if (is_off_screen(arg0, 0x88, 0x88) == 1) {
        func_8002D720(arg0);
    }
}
