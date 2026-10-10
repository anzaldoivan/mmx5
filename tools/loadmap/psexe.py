"""PS-X EXE header parser (0x800-byte header). `parse(path) -> dict` of the header words."""
import struct
import sys
from pathlib import Path

FIELDS = ("pc0", "gp0", "t_addr", "t_size", "d_addr", "d_size", "b_addr", "b_size", "s_addr", "s_size")
HEADER = 0x800


def parse(path):
    raw = Path(path).read_bytes()[:HEADER]
    assert raw[:8] == b"PS-X EXE", f"{path}: not a PS-X EXE"
    return dict(zip(FIELDS, struct.unpack_from("<10I", raw, 0x10)))


if __name__ == "__main__":
    exe = Path(__file__).resolve().parents[2] / "extracted/retail/SLUS_013.34"
    h = parse(exe)
    assert h["pc0"] == 0x8005894C, hex(h["pc0"])
    assert h["t_addr"] == 0x80010000, hex(h["t_addr"])
    assert h["t_size"] == 0x82000, hex(h["t_size"])
    assert h["t_size"] + HEADER == exe.stat().st_size
    print("psexe: OK", {k: f"{v:08X}" for k, v in h.items()})
    sys.exit(0)
