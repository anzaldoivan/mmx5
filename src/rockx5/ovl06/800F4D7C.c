#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"

static inline u8 func_800F4D7C_ovl06_face(u8* obj) {
    if (((s8*)obj)[2] == 0) {
        if (obj[0x8A] == 0) {
            return 0;
        }
        if (obj[0x8A] & 1) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        return 1;
    }
    if (*(s16*)(obj + 0xA) - D_8009A0AA < 0) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    return 0;
}

void func_800F4D7C_ovl06(u8* obj) {
    u8 st;

    if (((s8*)obj)[6] == 0) {
        obj[6]++;
        obj[0x8A] = 0;
        set_animation(obj, 0);
        *(s16*)(obj + 0x84) = 0x160;
        obj[0x8C] = random_byte() & 0x3F;
        func_800F4D7C_ovl06_face(obj);
    }
    if (obj[0x70] & 8) {
        if (obj[0x8C] != 0) {
            goto dec; // !FAKE: goto kept for the matching branch layout
        }
        if (obj[0x8D] & 2) {
            goto call; // !FAKE: goto kept for the matching branch layout
        }
        if (func_800F4D7C_ovl06_face(obj)) {
            st = 3;
        } else if (obj[0x86] != 0) {
            st = 8;
        } else if (obj[0x87] != 0) {
            st = 9;
        } else {
            goto call; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        st = 4;
    }
    obj[5] = st;
    obj[6] = 0;
    return;
call:
    animate_object(obj);
    return;
dec:
    obj[0x8C]--;
    animate_object(obj);
}

extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];

static inline u8 func_800F4F10_ovl06_face(u8* o) {
    u8 t;

    if (((s8*)o)[2] == 0) {
        t = o[0x8A];
        if (t != 0) {
            if (t & 1) {
                o[0x15] = 0x40;
            } else {
                o[0x15] = 0;
            }
            return 1;
        }
    } else if (*(s16*)(o + 0xA) - D_8009A0AA < 0) {
        o[0x15] = 0x40;
    } else {
        o[0x15] = 0;
    }
    return 0;
}

void func_800F4F10_ovl06(u8* o) {
    if (((s8*)o)[6] == 0) {
        o[6]++;
        set_animation(o, 1);
        *(s16*)(o + 0x84) = 0x160;
        func_800F4F10_ovl06_face(o);
        *(u8**)(o + 0x54) = D_800FE914_ovl06;
        *(u8**)(o + 0x50) = D_800FE918_ovl06;
        o[0x60] = 5;
        o[0x8D] &= 0xF3;
    }
    if (!(o[0x70] & 8)) {
        o[5] = 4;
        o[6] = 0;
        return;
    }
    {
        if (!(o[0x8D] & 2)) {
            if (func_800F4F10_ovl06_face(o) == 0) {
                o[5] = 2;
                o[6] = 0;
                o[0x88] = 0;
                o[0x86] = 0;
                o[0x87] = 0;
                *(u8**)(o + 0x54) = D_800FE914_ovl06;
                *(u8**)(o + 0x50) = D_800FE918_ovl06;
                o[0x60] = 5;
                return;
            }
            if (o[0x86] != 0) {
                o[5] = 8;
                o[6] = 0;
                return;
            }
            if (o[0x87] != 0) {
                o[5] = 9;
                o[6] = 0;
                return;
            }
            if (o[0x15] != 0) {
                *(s32*)(o + 0x20) = 0x16000;
            } else {
                *(s32*)(o + 0x20) = 0xFFFEA000;
            }
            *(s32*)(o + 8) += *(s32*)(o + 0x20);
            animate_object(o);
        } else {
            animate_object(o);
        }
    }
}

extern u8* find_free_visual_obj(void);
extern u8 D_800FE924_ovl06[];

static inline u8 func_800F5118_face(u8* p) {
    if (*(s8*)(p + 2) == 0) {
        u8 t = p[0x8A];
        if (t != 0) {
            if (t & 1) {
                p[0x15] = 0x40;
            } else {
                p[0x15] = 0;
            }
            return 1;
        }
    } else {
        if (*(s16*)(p + 0xA) - D_8009A0AA < 0) {
            p[0x15] = 0x40;
        } else {
            p[0x15] = 0;
        }
    }
    return 0;
}

void func_800F5118_ovl06(u8* p, u8* c) {
    s32 v;
    s32 six;

    c = (u8*)(u32)
        p[6]; // !FAKE: one a1 local for the state byte and the child (param c)
    if (*(s8*)(p + 6) == 0) {
        p[6] = (s32)c + 1;
        *(s32*)(p + 0x24) = 0x58000;
        *(s32*)(p + 0x2C) = 0x4200;
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x28) = 0;
        p[0x67] = 1;
        set_animation(p, 2);
        six = 6;
        p[0x70] &= 0xF7;
        c = find_free_visual_obj();
        if (c != 0) {
            c[0] = p[0];
            c[1] = 0xC;
            c[2] = six;
            *(s32*)(c + 0x8) = *(s32*)(p + 0x8);
            *(s32*)(c + 0xC) = *(s32*)(p + 0xC);
            *(s32*)(c + 0x30) = *(s32*)(p + 0x30);
            *(s16*)(c + 0x40) = *(s16*)(p + 0x40);
            *(s32*)(c + 0x3C) = *(s32*)(p + 0x3C);
            *(s16*)(c + 0x42) = *(s16*)(p + 0x42) & 0x7FFF;
            c[0x16] = p[0x16];
            c[0x15] = p[0x15];
            *(u8**)(c + 0x50) = p;
        }
        *(u8**)(p + 0x50) = D_800FE924_ovl06;
        p[0x60] = six;
    }
    if (p[0x87] == 0) {
        if (p[0x8D] & 2) {
            return;
        }
        *(s32*)(p + 0x20) = 0;
        if (func_800F5118_face(p)) {
            v = *(s16*)(p + 0x84) << 8;
            if (p[0x15] == 0) {
                v = -v;
            }
            *(s32*)(p + 0x20) = v;
        }
        if (!(p[0x70] & 4) && *(s32*)(p + 0x24) >= 0) {
            apply_object_motion(p);
            return;
        }
        p[5] = 4;
        p[6] = 0;
    } else {
        p[5] = 0xA;
        p[6] = 0;
    }
}

extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];

static inline u8 func_800F5314_ovl06_face(u8* o) {
    u8 t;

    if (((s8*)o)[2] == 0) {
        t = o[0x8A];
        if (t != 0) {
            if (t & 1) {
                o[0x15] = 0x40;
            } else {
                o[0x15] = 0;
            }
            return 1;
        }
    } else if (*(s16*)(o + 0xA) - D_8009A0AA < 0) {
        o[0x15] = 0x40;
    } else {
        o[0x15] = 0;
    }
    return 0;
}

void func_800F5314_ovl06(u8* o) {
    if (((s8*)o)[6] == 0) {
        o[6]++;
        *(s16*)(o + 0x84) = 0x160;
        o[0x67] = 0;
        set_animation(o, 4);
        *(u8**)(o + 0x54) = D_800FE914_ovl06;
        *(u8**)(o + 0x50) = D_800FE918_ovl06;
        o[0x86] = 0;
        o[0x60] = 5;
        o[0x70] |= 8;
    }
    if (((s8*)o)[0x46] == 0) {
        o[5] = 2;
        o[6] = 0;
        o[0x88] = 0;
        o[0x86] = 0;
        o[0x87] = 0;
        *(u8**)(o + 0x54) = D_800FE914_ovl06;
        *(u8**)(o + 0x50) = D_800FE918_ovl06;
        o[0x60] = 5;
        return;
    }
    if (!(o[0x8D] & 2)) {
        if (!(o[0x70] & 8)) {
            o[5] = 4;
            o[6] = 0;
        } else if (o[0x87] != 0) {
            o[5] = 9;
            o[6] = 0;
        } else if (func_800F5314_ovl06_face(o) != 0) {
            if (o[0x15] != 0) {
                *(s32*)(o + 0x20) = 0x16000;
            } else {
                *(s32*)(o + 0x20) = 0xFFFEA000;
            }
            *(s32*)(o + 8) += *(s32*)(o + 0x20);
        }
        animate_object(o);
    } else {
        animate_object(o);
    }
}

extern u8 D_800FE918_ovl06[];
extern u8 D_800FE924_ovl06[];

void func_800F54D8_ovl06(u8* p) {
    s32 v;
    u8 t;
    u8* d;
    s8 n;

    if (*(s8*)(p + 6) == 0) {
        p[6]++;
        set_animation(p, 0xA);
    }
    if (p[0x70] & 8) {
        p[5] = 5;
        p[6] = 0;
        return;
    }
    if (!(p[0x8D] & 2)) {
        t = p[0x8A];
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x28) = 0;
        if (t != 0) {
            v = *(s16*)(p + 0x84) << 8;
            if (!(t & 1)) {
                v = -v;
            }
            *(s32*)(p + 0x20) = v;
        }
        if (*(s32*)(p + 0x24) >= 0 && (p[0x70] & 4)) {
            *(s32*)(p + 0x24) = 0;
        }
        if (*(s8*)(p + 0x46) == 0) {
            n = 8;
            if (*(s32*)(p + 0x24) < 0) {
                n = 4;
            }
            p[5] = n;
        } else {
            if (*(s32*)(p + 0x24) < -0x5E000) {
                *(s32*)(p + 0x24) = -0x5E000;
            }
            apply_object_motion(p);
        }
        n = *(s8*)(p + 0x45);
        if (n == 1) {
            d = D_800FE924_ovl06;
            n = 6;
            goto store; // !FAKE: goto kept for the matching branch layout
        }
        if (n == 2) {
            d = D_800FE918_ovl06;
            n = 5;
        store:
            *(u8**)(p + 0x50) = d;
            p[0x60] = n;
        }
        animate_object(p);
        return;
    }
    animate_object(p);
}

extern u8* find_free_visual_obj(void);

void func_800F5634_ovl06(u8* obj) {
    u8* n;
    u8 t;
    u8 f;
    u8 c;
    s32 st;

    if (*(s8*)(obj + 6) == 0) {
        if (*(s8*)(obj + 2) == 0) {
            if (obj[0x8A] != 0) {
                if (obj[0x8A] & 1) {
                    obj[0x15] = 0x40;
                } else {
                    obj[0x15] = 0;
                }
            }
        } else if (*(s16*)(obj + 0xA) - D_8009A0AA < 0) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        obj[6] = 1;
        *(s16*)(obj + 0x84) = 0x420;
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x42000;
        } else {
            *(s32*)(obj + 0x20) = -0x42000;
        }
        obj[0x8E] = 0x1E;
        n = find_free_visual_obj();
        if (n != 0) {
            t = obj[0];
            n[1] = 0xC;
            n[2] = 5;
            n[0] = t;
            *(s32*)(n + 8) = *(s32*)(obj + 8);
            *(s32*)(n + 0xC) = *(s32*)(obj + 0xC);
            *(s32*)(n + 0x30) = *(s32*)(obj + 0x30);
            *(s16*)(n + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(n + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(n + 0x42) = *(s16*)(obj + 0x42) & 0x7FFF;
            n[0x16] = obj[0x16];
            n[0x15] = obj[0x15];
            *(u8**)(n + 0x50) = obj;
        }
        set_animation(obj, 5);
        obj[0x8D] |= 4;
    }
    if (!(obj[0x8D] & 2)) {
        if (obj[0x86] != 0) {
            st = 8;
        } else if (obj[0x87] != 0) {
            st = 0xB;
        } else {
            f = obj[0x70];
            if (f & 8) {
                goto test3; // !FAKE: goto kept for the matching branch layout
            }
            st = 4;
        }
        obj[5] = st;
        obj[6] = 0;
        goto call; // !FAKE: goto kept for the matching branch layout
    test3:
        if (!(f & 3)) {
            *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
            c = obj[0x8E];
            obj[0x8E] = c - 1;
            if ((s8)c >= 0) {
                goto call; // !FAKE: goto kept for the matching branch layout
            }
        }
        obj[5] = 7;
        obj[6] = 0;
        return;
    call:
        animate_object(obj);
        return;
    }
    animate_object(obj);
}

extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];

static inline u8 func_800F5840_ovl06_face(u8* obj) {
    if (*(s8*)(obj + 2) == 0) {
        if (obj[0x8A] != 0) {
            if (obj[0x8A] & 1) {
                obj[0x15] = 0x40;
            } else {
                obj[0x15] = 0;
            }
            return 1;
        }
    } else if (*(s16*)(obj + 0xA) - D_8009A0AA < 0) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    return 0;
}

void func_800F5840_ovl06(u8* obj) {
    s32 v;

    if (*(s8*)(obj + 6) == 0) {
        obj[6] = 1;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x4200;
        obj[0x67] = 1;
        set_animation(obj, 3);
        *(u8**)(obj + 0x54) = D_800FE914_ovl06;
        *(u8**)(obj + 0x50) = D_800FE918_ovl06;
        obj[0x60] = 5;
    }
    if (obj[0x70] & 8) {
        obj[5] = 5;
        obj[6] = 0;
        return;
    }
    if (obj[0x8D] & 2) {
        return;
    }
    if (obj[0x87] != 0) {
        obj[5] = 0xA;
        obj[6] = 0;
        return;
    }
    if (*(s8*)(obj + 1) == 0x48 && obj[0x86] != 0) {
        obj[5] = 0xC;
        obj[6] = 0;
        return;
    }
    *(s32*)(obj + 0x20) = 0;
    if (func_800F5840_ovl06_face(obj)) {
        v = *(s16*)(obj + 0x84) << 8;
        if (obj[0x15] == 0) {
            v = -v;
        }
        *(s32*)(obj + 0x20) = v;
    }
    if (*(s32*)(obj + 0x24) < -0x5E000) {
        *(s32*)(obj + 0x24) = -0x5E000;
    }
    apply_object_motion(obj);
}
