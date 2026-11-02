#include "types.h"

extern s32 func_80037E14(void);
extern void func_8002DF54(u8* a0);
extern s32 func_800306E0(u8* a0);
extern void func_80038F18(u8* a0, s32 a1);
extern s32 func_8003A134(u8* a0, s32 a1);
extern void func_8003B33C(u8* a0, s32 a1);
extern void func_8003B4CC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* a0);

void func_80038488(u8* a0) {
    s32 dir;
    s32 r;
    s32 in;
    s32 c;
    u16 f;
    u8 anim;

    if (*(s8*)(a0 + 0x84) != 0) {
        dir = func_80037E14();
    } else {
        f = *(u16*)(a0 + 0x7C);
        r = 0;
        if (f & 3) {
            r = 1;
            if (f & 2) {
                *(s32*)(a0 + 0x20) = -*(s32*)(a0 + 0x134);
            } else {
                r = 2;
                *(s32*)(a0 + 0x20) = *(s32*)(a0 + 0x134);
            }
            func_8002DF54(a0);
            in = (u8)(func_800306E0(a0) - 0x25) > 10;
            *(s32*)(a0 + 0x8) = *(s32*)(a0 + 0x18);
            if (in) {
                r = 0;
            } else {
                func_8002DF54(a0);
            }
        }
        dir = r;
    }
    if (dir != 0) {
        func_80038F18(a0, func_800306E0(a0));
    }
    c = func_800306E0(a0);
    if (*(s8*)(a0 + 0x2) == 0) {
        if (*(s8*)(a0 + 0x8F) != 0) {
            func_8003B33C(a0, func_8003A134(a0, c) + 0x97);
            return;
        }
        if (*(s8*)(a0 + 0x8E) != 0) {
            anim = 0x97;
            if (dir != 0) {
                anim = 0x9A;
            }
            anim += func_8003A134(a0, c);
        } else if (dir != 0) {
            anim = func_8003A134(a0, c) - 0x5A;
        } else {
            anim = func_8003A134(a0, c) - 0x69;
            if (*(u8*)(a0 + 0x17) != anim) {
                anim = func_8003A134(a0, c) - 0x5D;
            }
        }
    } else if (dir != 0) {
        anim = func_8003A134(a0, c) - 0x5A;
    } else {
        anim = func_8003A134(a0, c) - 0x5D;
    }
    if (anim != *(u8*)(a0 + 0x17)) {
        if ((u8)(anim + 0x5D) < 3) {
            if (*(s8*)(a0 + 0x2) != 0 && anim == 0xA3) {
                func_8003B4CC(a0, 0xA3, 4);
            } else {
                func_8003B4CC(a0, anim, 2);
            }
        } else {
            func_8003B33C(a0, anim);
        }
    } else {
        func_80017248(a0);
    }
    if (*(s8*)(a0 + 0x46) == 0 && *(s8*)(a0 + 0x8E) == 0) {
        anim = func_8003A134(a0, c) - 0x5D;
        if (*(s8*)(a0 + 0x2) == 0) {
            func_8003B4CC(a0, anim, 2);
        } else if (anim == 0xA3) {
            func_8003B4CC(a0, 0xA3, 4);
        } else {
            func_8003B4CC(a0, anim, 2);
        }
    }
}
