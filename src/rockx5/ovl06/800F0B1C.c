#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

static inline s32 func_800F0B1C_ovl06_test(u8* obj) {
    if ((*(u16*)(obj + 0x88) & 7) == 4) {
        if (*(u16*)(obj + 0x8A) & 0x80) {
            return 1;
        }
    } else if (D_8009A0FC.s == -0x80) {
        return 1;
    }
    return 0;
}

void func_800F0B1C_ovl06(u8* obj) {
    s32 flag;
    s32 mask;

    if (!(D_8009A420_as_s32 & 3) && (random_byte() & 1)) {
        random_byte();
    }
    flag = func_800F0B1C_ovl06_test(obj);
    if (flag) {
        obj[5] = 0xB;
        obj[6] = 0;
        return;
    }
    if (!(obj[0x97] & 2)) {
        mask = 1;
        if (!(obj[0xA8] & 8)) {
            obj[5] = 0xC;
            obj[6] = 0;
        } else {
            *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
            if (obj[0x15] != 0) {
                mask = 2;
            }
            if ((*(u16*)(obj + 0x88) & mask) || --*(s8*)(obj + 0x90) == 0) {
                obj[6] = 3;
                set_animation(obj, 0x10);
                if (obj[0x8D] == 0) {
                    g_Player[0xD8] = 0x29;
                    g_Player[6] = 0;
                }
            }
        }
        animate_object(obj);
    } else {
        animate_object(obj);
    }
}
#undef D_8009A420_as_s32

extern u8* func_8002D078();

void func_800F0C8C_ovl06(u8* obj) {
    u8* p;
    u8* q;
    s32 flag;
    u16 f;

    p = obj;
    if ((*(u16*)(p + 0x88) & 7) == 4) {
        flag = 1;
        if (!(*(u16*)(p + 0x8A) & 0x80)) {
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        flag = 1;
        if (D_8009A0FC.s != -0x80) {
        clear:
            flag = 0;
        }
    }
    if (flag != 0) {
        p[5] = 0xB;
        p[6] = 0;
        return;
    }
    if (!(p[0x97] & 2)) {
        if (!(p[0xA8] & 8)) {
            p[5] = 0xC;
            p[6] = 0;
        } else {
            f = *(u16*)(p + 0x88);
            if (f & 2) {
                p[0x15] = 0;
            } else if (f & 1) {
                p[0x15] = 0x40;
            }
            if (!(p[0x97] & 0x10) && p[0x94] == 0) {
                p[6] = 2;
                *(s16*)(p + 0x98) = 0x420;
                if (p[0x15] == 0) {
                    *(s32*)(p + 0x20) = 0xFFFBE000;
                } else {
                    *(s32*)(p + 0x20) = 0x42000;
                }
                p[0x90] = 0x1E;
                q = func_8002D078();
                if (q != 0) {
                    q[0] = 0x41;
                    q[1] = 0x3E;
                    q[2] = 4;
                    *(u16*)(q + 0xA) = *(u16*)(p + 0xA);
                    *(u16*)(q + 0xE) = *(u16*)(p + 0xE);
                    *(s32*)(q + 0x30) = *(s32*)(p + 0x30);
                    *(u16*)(q + 0x40) = *(u16*)(p + 0x40);
                    *(s32*)(q + 0x3C) = *(s32*)(p + 0x3C);
                    *(u16*)(q + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
                    q[0x16] = p[0x16];
                    *(u8**)(q + 0x7C) = p;
                    q[0x15] = p[0x15];
                }
                set_animation(p, 0xF);
                if (p[0x8D] == 0) {
                    g_Player[0xD8] = 0x36;
                    g_Player[6] = 0;
                }
                if (*(s8*)(p + 2) == 0) {
                    play_sound(5, 0x10, 0);
                } else {
                    play_sound(5, 6, 0);
                }
            }
        }
        animate_object(p);
        return;
    }
    animate_object(p);
}

extern s32 func_8002B5B4(s32);
extern u8* func_8002D078();

void func_800F0EB4_ovl06(u8* arg0) {
    s32 flag;
    u32 i;
    u8 bits;
    u8* o;
    u8 k;
    s32 r;

    if ((*(u16*)(arg0 + 0x88) & 7) == 4) {
        flag = 1;
        if (*(u16*)(arg0 + 0x8A) & 0x80) {
        } else {
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        flag = 1;
        if (D_8009A0FC.s != -0x80) {
        clear:
            flag = 0;
        }
    }
    if (flag != 0) {
        arg0[5] = 0xB;
        arg0[6] = 0;
        return;
    }
    if (!(arg0[0x97] & 2)) {
        if (!(arg0[0xA8] & 8)) {
            arg0[5] = 0xC;
            arg0[6] = 0;
        } else {
            if (*(u16*)(arg0 + 0x88) & 2) {
                arg0[0x15] = 0;
            } else if (*(u16*)(arg0 + 0x88) & 1) {
                arg0[0x15] = 0x40;
            }
            if (!(arg0[0x97] & 0x10) && arg0[0x94] == 0) {
                bits = arg0[0x7F];
                arg0[6] = 5;
                for (i = 0; i < 3; i++) {
                    if (!(bits & 1)) {
                        k = i;
                        if (arg0[0x86] < 3) {
                            o = func_8002D078();
                            if (o != 0) {
                                o[0] = 0x41;
                                o[1] = 0x3C;
                                o[2] = k;
                                *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
                                *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
                                *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
                                *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
                                *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
                                r = func_8002B5B4(0x81) & 0xFF;
                                *(s16*)(o + 0x42) =
                                    ((r * 4 + 0x18) % 16) |
                                    (((r + 6) / 4 + 0x1E0) << 6);
                                o[0x16] = arg0[0x16];
                                *(u8**)(o + 0x7C) = arg0;
                                o[0x15] = arg0[0x15];
                            }
                        }
                        arg0[0x7F] |= 1 << i;
                    }
                    bits >>= 1;
                }
                arg0[0x7E] = 0x10;
                play_sound(5, 6, 0);
            }
        }
        animate_object(arg0);
        return;
    }
    animate_object(arg0);
}
