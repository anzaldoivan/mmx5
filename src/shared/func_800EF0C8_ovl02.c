#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define g_Player_as_Scr0C8 (*(Scr0C8*)&g_Player)

extern void func_80032F70(Obj0C8*);
extern s32 func_8003240C(Obj0C8*);
extern s32 func_800326BC(Obj0C8*);
extern void func_8003258C(Obj0C8*);
extern void (*D_800F44C0_ovl02[])(Obj0C8*);

void func_800EF0C8_ovl02(Obj0C8* o) {
    s32 t;

    func_80032F70(o);
    ((void (*)())func_80033024)(o);
    if (g_Player_as_Scr0C8.unkF3 == 0) {
        D_800F44C0_ovl02[o->unk6](o);
    } else if ((u8)(g_Player_as_Scr0C8.unkFA - 2) >= 2) {
        D_800F44C0_ovl02[o->unk6](o);
    }
    if (o->unk84 == 0) {
        if (g_Player_as_Scr0C8.unkF3 == 0 ||
            (u8)(g_Player_as_Scr0C8.unkFA - 2) >= 2) {
            apply_object_motion(o);
        }
    } else if (--o->unk84 == 0) {
        set_animation(o, o->unk8B);
    }
    animate_object(o);
    func_8002D9EC(o, 0x30, 0x20);
    if (g_Player_as_Scr0C8.unkF8 == 0) {
        func_8003240C(o);
        if (o->unk2 != 1 && o->unk76 != 0 && (o->unk72 & 3)) {
            t = g_Player_as_Scr0C8.unkC;
            g_Player_as_Scr0C8.unkC = t - g_Player_as_Scr0C8.unk24;
            func_8003240C(o);
            if (o->unk76 == 0) {
                g_Player_as_Scr0C8.unkC =
                    g_Player_as_Scr0C8.unkC - g_Player_as_Scr0C8.unk24;
            } else {
                g_Player_as_Scr0C8.unkC = t;
            }
        }
    }
    func_800326BC(o);
    if (D_800D1C0C.s != 4) {
        func_8003258C(o);
    }
    if (o->unk72 & 8) {
        if (o->unk8A == 0) {
            o->unk8A = 1;
            switch (o->unk2) {
            case 0:
                set_animation(o, 5);
                break;
            case 1:
                if (o->unk20 > 0) {
                    if (o->unk84 != 0) {
                        o->unk8B = 8;
                        set_animation(o, 5);
                    } else {
                        set_animation(o, 8);
                    }
                } else {
                    if (o->unk84 != 0) {
                        o->unk8B = 7;
                        set_animation(o, 5);
                    } else {
                        set_animation(o, 7);
                    }
                }
                break;
            case 2:
                if (o->unk24 > 0) {
                    if (o->unk84 != 0) {
                        o->unk8B = 5;
                        set_animation(o, 5);
                    } else {
                        set_animation(o, 5);
                    }
                } else {
                    if (o->unk84 != 0) {
                        o->unk8B = 6;
                        set_animation(o, 5);
                    } else {
                        set_animation(o, 6);
                    }
                }
                break;
            case 5:
                if (o->unk20 == 0) {
                    if (o->unk24 > 0) {
                        set_animation(o, 5);
                    } else {
                        set_animation(o, 6);
                    }
                }
                if (o->unk24 == 0) {
                    if (o->unk20 > 0) {
                        set_animation(o, 8);
                    } else {
                        set_animation(o, 7);
                    }
                }
                break;
            }
        }
    }
    if (!(o->unk72 & 8)) {
        if (o->unk8A != 0) {
            o->unk8A = 0;
            switch (o->unk2) {
            case 0:
                set_animation(o, 1);
                break;
            case 1:
                if (o->unk20 > 0) {
                    if (o->unk84 != 0) {
                        o->unk8B = 4;
                        set_animation(o, 1);
                    } else {
                        set_animation(o, 4);
                    }
                } else {
                    if (o->unk84 != 0) {
                        o->unk8B = 3;
                        set_animation(o, 1);
                    } else {
                        set_animation(o, 3);
                    }
                }
                break;
            case 2:
                if (o->unk24 > 0) {
                    if (o->unk84 != 0) {
                        o->unk8B = 1;
                        set_animation(o, 1);
                    } else {
                        set_animation(o, 1);
                    }
                } else {
                    if (o->unk84 != 0) {
                        o->unk8B = 2;
                        set_animation(o, 1);
                    } else {
                        set_animation(o, 2);
                    }
                }
                break;
            case 5:
                if (o->unk20 == 0) {
                    if (o->unk24 > 0) {
                        set_animation(o, 1);
                    } else {
                        set_animation(o, 2);
                    }
                }
                if (o->unk24 == 0) {
                    if (o->unk20 > 0) {
                        set_animation(o, 4);
                    } else {
                        set_animation(o, 3);
                    }
                }
                break;
            }
        }
    }
}
