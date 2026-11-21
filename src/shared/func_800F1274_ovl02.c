#include "types.h"
#include "mmx5/object.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

#define SCR D_1F80004C.scr4c
extern s32 func_8003157C(Ent14C8*, s32, s32);
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_800F463E_ovl02;
extern u8 D_800F463F_ovl02;

void func_800F1274_ovl02(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 1) {
        SCR->cnt88--;
        SCR->box.d = D_800F463F_ovl02;
        e->f20 = 0;
        e->f24 = 0x38000;
        e->state = 6;
    } else if (!(e->flags70 & 8)) {
        i = 0;
        SCR->cnt88--;
        e->f20 = 0;
        do {
            if (e->dir) {
                x = e->x - SCR->box.a - SCR->box.c;
            } else {
                x = e->x + SCR->box.a - SCR->box.c;
            }
            if ((u8)func_8003157C(e, x - i,
                                  (s16)(e->y + SCR->box.b + SCR->box.d) + 1)) {
                if (i) {
                    SCR->box.c += i - 1;
                }
                e->f24 = 0xFFFC8000;
                e->state = 4;
                SCR->flags83 |= 1;
                break;
            }
            if (i == 4) {
                e->state = 2;
                e->f28 = 0;
                e->f2C = 0x1000;
                SCR->box = D_800F463C_ovl02;
                return;
            }
            i++;
        } while (i < 5);
    } else if (SCR->flags83 & 1) {
        SCR->box.c = D_800F463E_ovl02;
        SCR->flags83 &= ~1;
    }
    move_object(e);
}

#define SCR D_1F80004C.scr4c
extern s32 func_8003157C(Ent14C8*, s32, s32);
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_800F463E_ovl02;
extern u8 D_800F463F_ovl02;

void func_800F14C8_ovl02(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 8) {
        SCR->cnt88--;
        SCR->box.c = D_800F463E_ovl02;
        e->f20 = 0x38000;
        e->f24 = 0;
        e->state = 3;
    } else if (!(e->flags70 & 2)) {
        i = 0;
        SCR->cnt88--;
        e->f24 = 0;
        do {
            if (e->dir) {
                x = e->x - SCR->box.a - SCR->box.c;
            } else {
                x = e->x + SCR->box.a - SCR->box.c;
            }
            if ((u8)func_8003157C(
                    e, x - 1, (s16)(e->y + SCR->box.b - SCR->box.d) - i - 1)) {
                SCR->box.d += i;
                e->f20 = 0xFFFC8000;
                e->state = 5;
                SCR->flags83 |= 0x10;
                break;
            }
            if (i == 4) {
                e->state = 2;
                e->f28 = 0;
                e->f2C = 0x1000;
                SCR->box = D_800F463C_ovl02;
                return;
            }
            i++;
        } while (i < 5);
    } else if (SCR->flags83 & 0x10) {
        SCR->box.d = D_800F463F_ovl02;
        SCR->flags83 &= ~0x10;
    }
    move_object(e);
}

#define SCR D_1F80004C.scr4c
extern s32 func_8003157C(Ent14C8*, s32, s32);
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_800F463E_ovl02;
extern u8 D_800F463F_ovl02;

void func_800F1714_ovl02(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 2) {
        SCR->cnt88--;
        SCR->box.d = D_800F463F_ovl02;
        e->f20 = 0;
        e->f24 = 0xFFFC8000;
        e->state = 4;
    } else if (!(e->flags70 & 4)) {
        i = 0;
        SCR->cnt88--;
        e->f20 = 0;
        do {
            if (e->dir) {
                x = e->x - SCR->box.a + SCR->box.c;
            } else {
                x = e->x + SCR->box.a + SCR->box.c;
            }
            if ((u8)func_8003157C(e, x + i,
                                  (s16)(e->y + SCR->box.b - SCR->box.d) - 1)) {
                SCR->box.c += i;
                e->f24 = 0x38000;
                e->state = 6;
                SCR->flags83 |= 1;
                break;
            }
            if (i == 4) {
                e->state = 2;
                e->f28 = 0;
                e->f2C = 0x1000;
                SCR->box = D_800F463C_ovl02;
                return;
            }
            i++;
        } while (i < 5);
    } else if (SCR->flags83 & 1) {
        SCR->box.c = D_800F463E_ovl02;
        SCR->flags83 &= ~1;
    }
    move_object(e);
}

#define SCR D_1F80004C.scr4c
extern s32 func_8003157C(Ent14C8*, s32, s32);
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_800F463E_ovl02;
extern u8 D_800F463F_ovl02;

void func_800F195C_ovl02(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 4) {
        SCR->cnt88--;
        SCR->box.c = D_800F463E_ovl02;
        e->f20 = 0xFFFC8000;
        e->f24 = 0;
        e->state = 5;
    } else if (!(e->flags70 & 1)) {
        i = 0;
        SCR->cnt88--;
        e->f24 = 0;
        do {
            if (e->dir) {
                x = e->x - SCR->box.a + SCR->box.c;
            } else {
                x = e->x + SCR->box.a + SCR->box.c;
            }
            if ((u8)func_8003157C(e, x + 1,
                                  (s16)(e->y + SCR->box.b + SCR->box.d) + i)) {
                SCR->box.d += i;
                e->f20 = 0x38000;
                e->state = 3;
                SCR->flags83 |= 0x10;
                break;
            }
            if (i == 4) {
                e->state = 2;
                e->f28 = 0;
                e->f2C = 0x1000;
                SCR->box = D_800F463C_ovl02;
                return;
            }
            i++;
        } while (i < 5);
    } else if (SCR->flags83 & 0x10) {
        SCR->box.d = D_800F463F_ovl02;
        SCR->flags83 &= ~0x10;
    }
    move_object(e);
}

#define SCR D_1F80004C.scr4c
extern s32 func_8003157C(Ent14C8*, s32, s32);
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_800F463E_ovl02;
extern u8 D_800F463F_ovl02;

void func_800F1BA4_ovl02(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 2) {
        SCR->cnt88--;
        SCR->box.d = D_800F463F_ovl02;
        e->f20 = 0;
        e->f24 = 0x38000;
        e->state = 10;
    } else if (!(e->flags70 & 8)) {
        i = 0;
        SCR->cnt88--;
        e->f20 = 0;
        do {
            if (e->dir) {
                x = e->x - SCR->box.a + SCR->box.c;
            } else {
                x = e->x + SCR->box.a + SCR->box.c;
            }
            if ((u8)func_8003157C(e, x + i,
                                  (s16)(e->y + SCR->box.b + SCR->box.d) + 1)) {
                SCR->box.c += i;
                e->f24 = 0xFFFC8000;
                e->state = 8;
                SCR->flags83 |= 1;
                break;
            }
            if (i == 4) {
                e->state = 2;
                e->f28 = 0;
                e->f2C = 0x1000;
                SCR->box = D_800F463C_ovl02;
                return;
            }
            i++;
        } while (i < 5);
    } else if (SCR->flags83 & 1) {
        SCR->box.c = D_800F463E_ovl02;
        SCR->flags83 &= ~1;
    }
    move_object(e);
}

#define SCR D_1F80004C.scr4c
extern s32 func_8003157C(Ent14C8*, s32, s32);
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_800F463E_ovl02;
extern u8 D_800F463F_ovl02;

void func_800F1DEC_ovl02(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 8) {
        SCR->cnt88--;
        SCR->box.c = D_800F463E_ovl02;
        e->f20 = 0xFFFC8000;
        e->f24 = 0;
        e->state = 7;
    } else if (!(e->flags70 & 1)) {
        i = 0;
        SCR->cnt88--;
        e->f24 = 0;
        do {
            if (e->dir) {
                x = e->x - SCR->box.a + SCR->box.c;
            } else {
                x = e->x + SCR->box.a + SCR->box.c;
            }
            if ((u8)func_8003157C(
                    e, x + 1, (s16)(e->y + SCR->box.b - SCR->box.d) - i - 1)) {
                SCR->box.d += i;
                e->f20 = 0x38000;
                e->state = 9;
                SCR->flags83 |= 0x10;
                break;
            }
            if (i == 4) {
                e->state = 2;
                e->f28 = 0;
                e->f2C = 0x1000;
                SCR->box = D_800F463C_ovl02;
                return;
            }
            i++;
        } while (i < 5);
    } else if (SCR->flags83 & 0x10) {
        SCR->box.d = D_800F463F_ovl02;
        SCR->flags83 &= ~0x10;
    }
    move_object(e);
}

#define SCR D_1F80004C.scr4c
extern s32 func_8003157C(Ent14C8*, s32, s32);
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_800F463E_ovl02;
extern u8 D_800F463F_ovl02;

void func_800F2038_ovl02(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 1) {
        SCR->cnt88--;
        SCR->box.d = D_800F463F_ovl02;
        e->f20 = 0;
        e->f24 = 0xFFFC8000;
        e->state = 8;
    } else if (!(e->flags70 & 4)) {
        i = 0;
        SCR->cnt88--;
        e->f20 = 0;
        do {
            if (e->dir) {
                x = e->x - SCR->box.a - SCR->box.c;
            } else {
                x = e->x + SCR->box.a - SCR->box.c;
            }
            if ((u8)func_8003157C(e, x - i,
                                  (s16)(e->y + SCR->box.b - SCR->box.d) - 1)) {
                if (i) {
                    SCR->box.c += i - 1;
                }
                e->f24 = 0x38000;
                e->state = 10;
                SCR->flags83 |= 1;
                break;
            }
            if (i == 4) {
                e->state = 2;
                e->f28 = 0;
                e->f2C = 0x1000;
                SCR->box = D_800F463C_ovl02;
                return;
            }
            i++;
        } while (i < 5);
    } else if (SCR->flags83 & 1) {
        SCR->box.c = D_800F463E_ovl02;
        SCR->flags83 &= ~1;
    }
    move_object(e);
}

#define SCR D_1F80004C.scr4c
extern s32 func_8003157C(Ent14C8*, s32, s32);
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_800F463E_ovl02;
extern u8 D_800F463F_ovl02;

void func_800F228C_ovl02(Ent14C8* e) {
    s32 i;
    s16 x;

    if (e->flags70 & 4) {
        SCR->cnt88--;
        SCR->box.c = D_800F463E_ovl02;
        e->f20 = 0x38000;
        e->f24 = 0;
        e->state = 9;
    } else if (!(e->flags70 & 2)) {
        i = 0;
        SCR->cnt88--;
        e->f24 = 0;
        do {
            if (e->dir) {
                x = e->x - SCR->box.a - SCR->box.c;
            } else {
                x = e->x + SCR->box.a - SCR->box.c;
            }
            if ((u8)func_8003157C(e, x - 1,
                                  (s16)(e->y + SCR->box.b + SCR->box.d) + i)) {
                SCR->box.d += i;
                e->f20 = 0xFFFC8000;
                e->state = 7;
                SCR->flags83 |= 0x10;
                break;
            }
            if (i == 4) {
                e->state = 2;
                e->f28 = 0;
                e->f2C = 0x1000;
                SCR->box = D_800F463C_ovl02;
                return;
            }
            i++;
        } while (i < 5);
    } else if (SCR->flags83 & 0x10) {
        SCR->box.d = D_800F463F_ovl02;
        SCR->flags83 &= ~0x10;
    }
    move_object(e);
}

extern u8 D_8009A197;
extern void (*D_800F4770_ovl02[])(ObjEECF8*);
extern s32 func_8004FC64(ObjEECF8*);

void func_800F24D4_ovl02(ObjEECF8* e) {
    if (D_8009A197 == 0) {
        e->unk18 = e->x.val;
        e->unk1C = e->y.val;
        D_800F4770_ovl02[e->unk5](e);
        animate_object(e);
    }
    if (func_80031DD0(e) < 0 || D_1F80004C.scr24d4->unk88 <= 0) {
        func_8004FC64(e);
        e->unk4 = 6;
        return;
    }
    if (is_off_screen(e, 0x40, 0x40)) {
        e->unk4 = 6;
        return;
    }
    func_8002D9EC(e, 0x20, 0x20);
    if ((e->unk70 & 0xC) == 0xC || (e->unk70 & 3) == 3) {
        func_8004FC64(e);
        e->unk4 = 6;
        return;
    }
    func_8002FB58(e);
}
