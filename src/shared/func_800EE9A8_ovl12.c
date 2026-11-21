#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

extern u8 D_80074EE0[];
extern u8 D_80076100[];
extern u8 D_8009A11A;
extern u8 D_800F1BC4_ovl12[];
extern u8 D_800F1BC8_ovl12[];
extern u8 D_800F1BCC_ovl12[];
extern u8 D_800F1BD0_ovl12[];
extern u8 D_800F1BD4_ovl12[];
extern u8 D_800F1BD8_ovl12[];
extern u8 D_800F1BDC_ovl12[];
extern void* D_800F2000_ovl12[];

void func_800EE9A8_ovl12(u8* o) {
    u8* p;
    u8* q;
    s32 r;
    u8 t;
    u8 d;
    u8 c;

    t = o[0x47];
    if ((u32)(t - 0x2D) < 11) {
        if (t == 0x34) {
            *(u8**)(o + 0x50) = D_800F1BCC_ovl12;
        } else {
            *(u8**)(o + 0x50) = D_800F1BC8_ovl12;
        }
    } else {
        *(u8**)(o + 0x50) = D_800F1BC4_ovl12;
    }
    func_800317B8(o);
    r = o[0x47];
    if ((u32)(r - 0x5A) < 4) {
        *(u8**)(o + 0x54) = D_800F1BDC_ovl12;
        q = D_80074EE0;
        *(u8**)(o + 0x58) = q;
        r = func_80031DD0(o);
        if (r == 0) {
            if (o[0x84] != 0) {
                *(u8**)(o + 0x58) = q;
            } else {
                *(u8**)(o + 0x58) = D_80076100;
            }
            p = D_800F1BD8_ovl12;
            goto store54; // !FAKE: goto kept for the matching branch layout
        }
        o[0x84] = 1;
    } else {
        if (*(s8*)(o + 5) == 9) {
            if (o[0x84] < 20) {
                o[0x84] = 40;
            }
            if (*(s8*)(o + 6) == 3 && o[0x84] < 50) {
                o[0x84] = 120;
            }
        } else {
            c = r - 0x2D;
            if (c < 11) {
                p = D_800F1BD4_ovl12;
            } else {
                p = D_800F1BD0_ovl12;
            }
        store54:
            *(u8**)(o + 0x54) = p;
        }
        r = func_80031DD0(o);
    }
    if (r < 0) {
        o[4] = 2;
        o[5] = 0;
        o[6] = 0;
        *(u16*)(o + 0x42) &= 0x7FFF;
        D_8009A11A = 1;
        func_8002D9EC(o, 100, 100);
        return;
    }
    if (r > 0 && r != 0x7F) {
        o[0x84] = ((u32)(r - 0x19) < 2) ? 2 : 30;
        *(u8**)(o + 0x58) = D_80074EE0;
        if (r == 9 || r == 0x12 || r == 0x2D) {
            o[5] = 9;
            o[6] = 0;
        }
    }
    d = o[0x84];
    if (d != 0) {
        o[0x84] = d + 0xFF;
        if (d & 2) {
            *(u16*)(o + 0x42) |= 0x8000;
        } else {
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
        if (o[0x84] == 0) {
            *(u8**)(o + 0x58) = D_80076100;
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
    }
    ((void (*)(u8*))D_800F2000_ovl12[*(s8*)(o + 5)])(o);
}

extern u8 D_800D1C00[];
extern u8 D_800F1BC0_ovl12[];

void func_800EEC38_ovl12(u8* arg0) {
    u8* p;
    s32 snd;

    if (*(u8**)(arg0 + 0x68) == 0 && *(s16*)(arg0 + 0xE) >= 0x12C) {
        *(u8**)(arg0 + 0x68) = D_800F1BC0_ovl12;
    }
    if (arg0[0x70] & 8) {
        *(s32*)(arg0 + 0x24) = 0;
    }
    if (*(s8*)(arg0 + 0x46) == 0) {
        p = D_800D1C00;
        if (*(s8*)(p + 0xC) != 0xC) {
            snd = 0x35;
            if (*(s8*)(arg0 + 2) == 0) {
                snd = 0x33;
            }
            ((s32(*)())func_8002385C)(snd, 0xFF, *(s8*)(p + 0x2E));
            p[0x2E] = 1;
        }
        set_animation(arg0, 1);
        *(s16*)(arg0 + 0x7C) = 3;
        arg0[6]++;
    }
    animate_object(arg0);
    move_object(arg0);
    func_8002D9EC(arg0, 0x40, 0x40);
}

extern s8 D_8009A0A2;
extern u8 D_800F1F94_ovl12[][6];

void func_800EED30_ovl12(u8* obj) {
    u32 r;

    r = random_byte() & 0xF;
    obj[0x87] = 0;
    if (((s8*)obj)[2] == 0) {
        if (D_8009A0A2 == 0) {
            if (r < 6) {
                obj[0x86] = 0;
            } else if (r < 12) {
                obj[0x86] = 1;
            } else {
                obj[0x86] = 4;
            }
        } else {
            if (r < 6) {
                obj[0x86] = 2;
            } else if (r < 10) {
                obj[0x86] = 3;
            } else {
                obj[0x86] = 4;
            }
        }
    } else {
        if (D_8009A0A2 == 0) {
            if (r < 6) {
                obj[0x86] = 5;
            } else if (r < 10) {
                obj[0x86] = 6;
            } else {
                obj[0x86] = 9;
            }
        } else {
            if (r < 6) {
                obj[0x86] = 7;
            } else if (r < 10) {
                obj[0x86] = 8;
            } else {
                obj[0x86] = 9;
            }
        }
    }
    obj[5] = D_800F1F94_ovl12[obj[0x86]][obj[0x87]++];
    obj[6] = 0;
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}

extern u8 D_800F1F94_ovl12[][6];

void func_800EEE5C_ovl12(ObjEE5C* obj) {
    if (obj->unk24 < 0) {
        if (obj->unk20 < 0) {
            obj->unk20 = -0x10000;
        } else {
            obj->unk20 = 0x10000;
        }
    }
    if (obj->unk45 == 3) {
        obj->unk45 = 0;
        if (obj->unk15 == 0) {
            obj->unk15 = 0x40;
        } else {
            obj->unk15 = 0;
        }
    }
    if (obj->unk70 & 8) {
        if (obj->unk24 != 0) {
            play_sound(2, 0x42, obj);
        }
        obj->unk20 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0;
    }
    if (obj->unk46 == 0) {
        if ((random_byte() & 3) == 0) {
            play_sound(2, 0x3D, obj);
            set_animation(obj, 8);
            if (D_8009A0AA > obj->unkA) {
                obj->unk15 = 0x40;
            } else {
                obj->unk15 = 0;
            }
            obj->unk7C = 0;
            obj->unk6++;
        } else {
            set_animation(obj, 1);
            obj->unk5 = D_800F1F94_ovl12[obj->unk86][obj->unk87++];
            obj->unk6 = 0;
        }
    }
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800EEFE0_ovl12(u8* obj) {
    s16 d;

    set_animation(obj, 6);
    if (D_8009A0AA < 0xB8) {
        d = 0x130 - *(u16*)(obj + 0xA);
        obj[0x15] = 0;
        if ((d < 0 ? -d : d) < 0x20) {
            set_animation(obj, 7);
            play_sound(2, 0x3D, obj);
            obj[6] += 2;
        } else {
            *(s32*)(obj + 0x20) = (d << 16) / 42;
            goto far; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        obj[0x15] = 0x40;
        d = 0x40 - *(u16*)(obj + 0xA);
        if ((d < 0 ? -d : d) < 0x20) {
            set_animation(obj, 7);
            play_sound(2, 0x3D, obj);
            obj[6] += 2;
        } else {
            *(s32*)(obj + 0x20) = (d << 16) / 42;
        far:
            *(s32*)(obj + 0x24) = 0x30000;
            *(s32*)(obj + 0x2C) = 0x2666;
            play_sound(2, 0x35, obj);
            obj[6] += 1;
        }
    }
}
