#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/ovl03.h"

extern s32 get_launch_variant(void);

void func_800F35F0_ovl03(u8* obj) {
    s8* p;

    if (*(s8*)(obj + 0x46) == 0) {
        p = (s8*)g_playthrough_state.u;
        if (p[0xC] != 0xC) {
            if (get_launch_variant() == 0) {
                func_8002385C(0x6B, 0xFF, p[0x2E]);
            } else if (get_launch_variant() == 1) {
                func_8002385C(0x30, 0xFF, p[0x2E]);
            } else {
                func_8002385C(0x62, 0xFF, p[0x2E]);
            }
            g_playthrough_state.u[0x2E] = 1;
        }
        set_animation(obj, 1);
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
    }
    if (*(s8*)(obj + 0x45) != 0 && *(s32*)(obj + 0x24) == 0) {
        *(s32*)(obj + 0x24) = 0xFFFF0000;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA248_ovl03;

void func_800F3700_ovl03(Obj3700* obj) {
    s16 x;
    s16 a;
    s32 e;

    set_animation(obj, 1);
    if (obj->unkA < D_800FA248_ovl03) {
        x = D_800FA240_ovl03 - 1;
    } else {
        x = D_800FA242_ovl03 + 1;
    }
    e = obj->unkE + 1;
    a = ratan2(D_800FA244_ovl03 - e, x - obj->unkA);
    obj->unk20 = rcos(a) * 48;
    obj->unk24 = -rsin(a) * 48;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk6++;
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800F37F0_ovl03(u8* o) {
    s32 k = 0x2000;

    if (++*(s16*)(o + 0x7C) == 50) {
        if (o[0x8F] == 4) {
            *(s16*)(o + 0x7C) = 0;
            o[6] += 2;
        } else {
            switch (o[0x8E]) {
            case 0:
                if ((random_byte() & 0xF) < 8) {
                    o[0x8E] = 1;
                    *(s32*)(o + 0x84) = k;
                    *(s32*)(o + 0x88) = 0;
                } else {
                    o[0x8E] = 2;
                    *(s32*)(o + 0x84) = 0;
                    *(s32*)(o + 0x88) = -0x2000;
                }
                break;
            case 1:
                if ((random_byte() & 0xF) < 8) {
                    o[0x8E] = 0;
                    *(s32*)(o + 0x84) = -0x2000;
                    *(s32*)(o + 0x88) = 0;
                } else {
                    o[0x8E] = 3;
                    *(s32*)(o + 0x84) = 0;
                    *(s32*)(o + 0x88) = -0x2000;
                }
                break;
            case 2:
                if ((random_byte() & 0xF) < 4) {
                    o[0x8E] = 3;
                    *(s32*)(o + 0x84) = k;
                    *(s32*)(o + 0x88) = 0;
                } else {
                    o[0x8E] = 0;
                    *(s32*)(o + 0x84) = 0;
                    *(s32*)(o + 0x88) = k;
                }
                break;
            case 3:
                if ((random_byte() & 0xF) < 4) {
                    o[0x8E] = 2;
                    *(s32*)(o + 0x84) = -0x2000;
                    *(s32*)(o + 0x88) = 0;
                } else {
                    o[0x8E] = 1;
                    *(s32*)(o + 0x84) = 0;
                    *(s32*)(o + 0x88) = k;
                }
                break;
            }
            *(s16*)(o + 0x7C) = -1;
            o[6]++;
        }
    }
    animate_object(o);
    apply_object_motion(o);
}

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA246_ovl03;

void func_800F3988_ovl03(Obj3988* o) {
    o->unk20 += o->unk84;
    o->unk24 += o->unk88;
    if ((o->unk20 < 0 ? -o->unk20 : o->unk20) > 0x30000) {
        o->unk84 = 0;
    }
    if ((o->unk24 < 0 ? -o->unk24 : o->unk24) > 0x30000) {
        o->unk88 = 0;
    }
    if (o->unk20 < 0) {
        if (o->unkA <= D_800FA240_ovl03) {
            o->unkA = D_800FA240_ovl03;
            goto clr_x; // !FAKE: clamp branches share the target's zeroing tail
        }
    } else if (o->unk20 > 0) {
        if (o->unkA >= D_800FA242_ovl03) {
            o->unkA = D_800FA242_ovl03;
        clr_x:
            o->unk20 = 0;
            o->unk84 = 0;
        }
    }
    if (o->unk24 > 0) {
        if (o->unkE <= D_800FA244_ovl03) {
            o->unkE = D_800FA244_ovl03;
            goto clr_y; // !FAKE: clamp branches share the target's zeroing tail
        }
    } else if (o->unk24 < 0) {
        if (o->unkE >= D_800FA246_ovl03) {
            o->unkE = D_800FA246_ovl03;
        clr_y:
            o->unk24 = 0;
            o->unk88 = 0;
        }
    }
    if (o->unk20 == 0 && o->unk24 == 0) {
        o->unk7C = 0;
        o->unk8F++;
        o->unk6--;
    }
    animate_object(o);
    apply_object_motion(o);
}

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA246_ovl03;
extern s16 D_800FA248_ovl03;
extern s16 D_800FA24A_ovl03;

void func_800F3B18_ovl03(u8* obj) {
    s32 e1;
    s32 e2;
    s32 d1;
    s32 d2;
    s16 x;
    s16 a;
    u8* p;
    u8* q;
    s32 e;

    set_animation(obj, 1);
    p = g_Player;
    if (*(s16*)(p + 0xA) > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    if (*(s16*)(obj + 0xE) < D_800FA24A_ovl03) {
        if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 1;
        } else {
            x = D_800FA242_ovl03 + 1;
        }
        d1 = D_800FA244_ovl03;
        e1 = *(s16*)(obj + 0xE) + 1;
        a = ratan2(d1 - e1, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x20) = rcos(a) * 48;
        *(s32*)(obj + 0x24) = -rsin(a) * 48;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6] += 1;
    } else if (q = g_Player, ((s8*)q)[2] == 0) {
        if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 1;
        } else {
            x = D_800FA242_ovl03 + 1;
        }
        d2 = D_800FA246_ovl03;
        e2 = *(s16*)(obj + 0xE) - 1;
        a = ratan2(d2 - e2, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x20) = rcos(a) * 48;
        *(s32*)(obj + 0x24) = -rsin(a) * 48;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6] += 3;
    } else {
        if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 1;
            obj[0x8E] = 2;
        } else {
            x = D_800FA242_ovl03 + 1;
            obj[0x8E] = 3;
        }
        e = *(s16*)(obj + 0xE) - 1;
        a = ratan2(D_800FA246_ovl03 - e, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x20) = rcos(a) * 48;
        *(s32*)(obj + 0x24) = -rsin(a) * 48;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6] += 5;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void func_800F3DD4_ovl03(Obj3DD4* o) {
    if (D_8009A0AA > o->unkA) {
        o->unk15 = 0x40;
    } else {
        o->unk15 = 0;
    }
    if (o->unk20 < 0) {
        if (o->unkA <= D_800FA240_ovl03) {
            o->unkA = D_800FA240_ovl03;
            o->unk20 = 0;
        }
    } else if (o->unk20 > 0) {
        if (o->unkA >= D_800FA242_ovl03) {
            o->unkA = D_800FA242_ovl03;
            o->unk20 = 0;
        }
    }
    if (o->unkE <= D_800FA244_ovl03) {
        o->unkE = D_800FA244_ovl03;
        o->unk24 = 0;
    }
    if (o->unk20 == 0 && o->unk24 == 0) {
        set_animation(o, 5);
        o->unk7C = 0;
        o->unk7E = 0;
        o->unk6++;
    }
    animate_object(o);
    apply_object_motion(o);
}

extern u8* func_8002C938();

void func_800F3EEC_ovl03(Obj3EEC* o) {
    u8* c;
    s32 i;

    o->unk7C++;
    if (o->unk7E == 0) {
        if (o->unk7C == 20) {
            o->unk7 = 0;
            for (i = 0; i < 6; i++) {
                c = func_8002C938();
                if (c != 0) {
                    c[0] = 0x61;
                    c[1] = 0x39;
                    c[2] = 2;
                    *(Obj3EEC**)(c + 0x80) = o;
                }
            }
            {
                Obj3EEC* p = (Obj3EEC*)g_Player;
                if (p->unkA > o->unkA) {
                    o->unk15 = 0x40;
                } else {
                    o->unk15 = 0;
                }
            }
            o->unk7C = 0;
            o->unk7E++;
        }
    } else if (o->unk7C == 120) {
        if (o->unk7E == 3) {
            set_animation(o, 1);
            o->unk5 = D_800FA0BC_ovl03[o->unk92][o->unk93++];
            o->unk6 = 0;
        } else {
            o->unk7 = 0;
            for (i = 0; i < 6; i++) {
                c = func_8002C938();
                if (c != 0) {
                    c[0] = 0x61;
                    c[1] = 0x39;
                    c[2] = 2;
                    *(Obj3EEC**)(c + 0x80) = o;
                }
            }
            {
                Obj3EEC* p = (Obj3EEC*)g_Player;
                if (p->unkA > o->unkA) {
                    o->unk15 = 0x40;
                } else {
                    o->unk15 = 0;
                }
            }
            o->unk7C = 0;
            o->unk7E++;
        }
    }
    animate_object(o);
    apply_object_motion(o);
}

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA246_ovl03;

void func_800F40A8_ovl03(Obj3DD4* o) {
    if (D_8009A0AA > o->unkA) {
        o->unk15 = 0x40;
    } else {
        o->unk15 = 0;
    }
    if (o->unk20 < 0) {
        if (o->unkA <= D_800FA240_ovl03) {
            o->unkA = D_800FA240_ovl03;
            o->unk20 = 0;
        }
    } else if (o->unk20 > 0) {
        if (o->unkA >= D_800FA242_ovl03) {
            o->unkA = D_800FA242_ovl03;
            o->unk20 = 0;
        }
    }
    if (o->unkE >= D_800FA246_ovl03) {
        o->unkE = D_800FA246_ovl03;
        o->unk24 = 0;
    }
    if (o->unk20 == 0 && o->unk24 == 0) {
        set_animation(o, 5);
        o->unk7C = 0;
        o->unk7E = 0;
        o->unk6++;
    }
    animate_object(o);
    apply_object_motion(o);
}

extern u8* func_8002C938();

void func_800F41BC_ovl03(Obj3EEC* o) {
    u8* c;
    s32 i;

    o->unk7C++;
    if (o->unk7E == 0) {
        if (o->unk7C == 20) {
            o->unk7 = 0;
            for (i = 0; i < 3; i++) {
                c = func_8002C938();
                if (c != 0) {
                    c[0] = 0x61;
                    c[1] = 0x39;
                    c[2] = 3;
                    *(Obj3EEC**)(c + 0x80) = o;
                }
            }
            {
                Obj3EEC* p = (Obj3EEC*)g_Player;
                if (p->unkA > o->unkA) {
                    o->unk15 = 0x40;
                } else {
                    o->unk15 = 0;
                }
            }
            o->unk7C = 0;
            o->unk7E++;
        }
    } else if (o->unk7C == 20) {
        if (o->unk7E == 6) {
            set_animation(o, 1);
            o->unk5 = D_800FA0BC_ovl03[o->unk92][o->unk93++];
            o->unk6 = 0;
        } else {
            o->unk7 = 0;
            for (i = 0; i < 3; i++) {
                c = func_8002C938();
                if (c != 0) {
                    c[0] = 0x61;
                    c[1] = 0x39;
                    c[2] = 3;
                    *(Obj3EEC**)(c + 0x80) = o;
                }
            }
            {
                Obj3EEC* p = (Obj3EEC*)g_Player;
                if (p->unkA > o->unkA) {
                    o->unk15 = 0x40;
                } else {
                    o->unk15 = 0;
                }
            }
            o->unk7C = 0;
            o->unk7E++;
        }
    }
    animate_object(o);
    apply_object_motion(o);
}

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA246_ovl03;

void func_800F4378_ovl03(Obj3DD4* o) {
    if (D_8009A0AA > o->unkA) {
        o->unk15 = 0x40;
    } else {
        o->unk15 = 0;
    }
    if (o->unk20 < 0) {
        if (o->unkA <= D_800FA240_ovl03) {
            o->unkA = D_800FA240_ovl03;
            o->unk20 = 0;
        }
    } else if (o->unk20 > 0) {
        if (o->unkA >= D_800FA242_ovl03) {
            o->unkA = D_800FA242_ovl03;
            o->unk20 = 0;
        }
    }
    if (o->unkE >= D_800FA246_ovl03) {
        o->unkE = D_800FA246_ovl03;
        o->unk24 = 0;
    }
    if (o->unk20 == 0 && o->unk24 == 0) {
        set_animation(o, 5);
        if (((u8*)o)[0x8E] == 2) {
            o->unk15 = 0x40;
        } else {
            o->unk15 = 0;
        }
        o->unk7C = 0;
        o->unk6++;
    }
    animate_object(o);
    apply_object_motion(o);
}

extern u8* func_8002C938();
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;

void func_800F44A4_ovl03(u8* o) {
    u8* c;

    if (--*(s16*)(o + 0x7C) == 0 || *(s32*)(o + 0x20) == 0) {
        c = func_8002C938();
        if (c != 0) {
            c[0] = 0x61;
            c[1] = 0x39;
            c[2] = 4;
            *(u8**)(c + 0x80) = o;
        }
        *(s16*)(o + 0x7C) = 0x16;
    }
    if (*(s32*)(o + 0x20) < 0) {
        if (*(s16*)(o + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(o + 0xA) = D_800FA240_ovl03;
            *(s32*)(o + 0x20) = 0;
        }
    } else if (*(s32*)(o + 0x20) > 0) {
        if (*(s16*)(o + 0xA) >= D_800FA242_ovl03) {
            *(s16*)(o + 0xA) = D_800FA242_ovl03;
            *(s32*)(o + 0x20) = 0;
        }
    }
    if (*(s32*)(o + 0x20) == 0) {
        set_animation(o, 1);
        o[5] = D_800FA0BC_ovl03[o[0x92]][o[0x93]++];
        o[6] = 0;
    }
    animate_object(o);
    apply_object_motion(o);
}
