#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D078();
extern s32 func_8002B5B4(s32);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];
extern s8 D_8009A0FC;

static inline void func_800F1DD8_ovl06_spawn(u8* p, u8* obj, s32 k) {
    s32 r;

    p[0] = 0x41;
    p[1] = 0x3B;
    p[2] = k;
    *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
    *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
    *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
    *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
    *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
    r = (u8)func_8002B5B4(0x81);
    *(u16*)(p + 0x42) = ((r * 4 + 0x18) % 16) | ((((r + 6) / 4) + 0x1E0) << 6);
    p[0x16] = obj[0x16];
    *(u8**)(p + 0x7C) = obj;
    p[0x15] = obj[0x15];
    obj[0x86]++;
}

static inline s32 func_800F1DD8_ovl06_test(u8* obj) {
    if ((*(u16*)(obj + 0x88) & 7) == 4) {
        if (*(u16*)(obj + 0x8A) & 0x80) {
            return 1;
        }
    } else if (D_8009A0FC == -0x80) {
        return 1;
    }
    return 0;
}

static inline s32 func_800F1DD8_ovl06_dir(u8* obj) {
    if (*(u16*)(obj + 0x88) & 2) {
        obj[0x15] = 0;
        return 1;
    }
    if (*(u16*)(obj + 0x88) & 1) {
        obj[0x15] = 0x40;
        return 1;
    }
    return 0;
}

static inline s32 func_800F1DD8_ovl06_jump(u8* obj) {
    s32 r;

    if (*(u16*)(obj + 0x8A) & 0x30) {
        r = 1;
        if (*(s8*)(obj + 2) != 0) {
            r = obj[0x7E] == 0;
        }
    } else {
        r = 0;
    }
    return r;
}

void func_800F1DD8_ovl06(u8* obj) {
    u8* p;
    s32 flag;
    s32 t;

    if (*(s8*)(obj + 6) == 0) {
        obj[6] = 1;
        obj[0x7D] = 1;
        *(s16*)(obj + 0x98) = 0x160;
        if (*(u16*)(obj + 0x88) & 8) {
            if (obj[0x86] < 3) {
                p = func_8002D078();
                if (p != 0) {
                    func_800F1DD8_ovl06_spawn(p, obj, 1);
                }
            }
            func_800171E8(obj, 0xB);
            if (obj[0x8D] == 0) {
                D_8009A0A0[0xD8] = 0x3D;
                D_8009A0A0[6] = 0;
            }
        } else if (obj[0x86] < 3) {
            p = func_8002D078();
            if (p != 0) {
                func_800F1DD8_ovl06_spawn(p, obj, 0);
            }
        }
        obj[0x87] = 0;
        func_80016490(5, 7, 0);
    }
    flag = func_800F1DD8_ovl06_test(obj);
    if (flag) {
        obj[5] = 0xB;
        obj[6] = 0;
        return;
    }
    if (obj[0xA8] & 8) {
        obj[5] = 5;
        obj[6] = 0;
        return;
    }
    if ((obj[0x97] & 2) == 0) {
        if (*(u16*)(obj + 0x8A) & 0x80) {
            obj[5] = 0xC;
            obj[6] = 0;
            return;
        }
        if (*(s8*)(obj + 0x46) < 0) {
            obj[5] = 0xE;
            obj[6] = 0;
            return;
        }
        if (*(s8*)(obj + 0x45) != 0) {
            t = func_800F1DD8_ovl06_jump(obj);
            if (t && obj[0x86] < 3) {
                obj[5] = 0x11;
                if (*(u16*)(obj + 0x88) & 8) {
                    p = func_8002D078();
                    if (p != 0) {
                        func_800F1DD8_ovl06_spawn(p, obj, 1);
                    }
                    func_800171E8(obj, 0xB);
                    if (obj[0x8D] == 0) {
                        D_8009A0A0[0xD8] = 0x3D;
                        D_8009A0A0[6] = 0;
                    }
                    return;
                }
                func_800171E8(obj, 0xD);
                if (obj[0x8D] == 0) {
                    D_8009A0A0[0xD8] = 0x3C;
                    D_8009A0A0[6] = 0;
                }
                if (obj[0x86] < 3) {
                    p = func_8002D078();
                    if (p != 0) {
                        func_800F1DD8_ovl06_spawn(p, obj, 0);
                    }
                }
                return;
            }
        }
        if (func_800F1DD8_ovl06_dir(obj)) {
            if (obj[0x15] != 0) {
                *(s32*)(obj + 0x20) = 0x16000;
            } else {
                *(s32*)(obj + 0x20) = -0x16000;
            }
            *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
        }
        func_80017248(obj);
    } else {
        func_80017248(obj);
    }
}
