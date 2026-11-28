#!/usr/bin/env python3
"""splat_root -- `python -m splat` with its yaml output paths moved under BUILD_ROOT (mmx6 C0506).

Adapted from mmx6 (tools/mmx6/splat_closure.py). A BUILD_ROOT other than `build` moves build_path, ld_script_path,
elf_path, the undefined_*_auto paths, asm_path, generated_asm_macros_directory, asset_path and the build/ entries of
symbol_addrs_path so a split writes only that tree; BUILD_ROOT=build leaves every path as the yaml spells it.
"""
import layout


OUTPUT_OPTS = ("build_path", "ld_script_path", "elf_path", "undefined_funcs_auto_path", "undefined_syms_auto_path",
               "asm_path", "generated_asm_macros_directory", "asset_path")


def move_paths(opts):
    """Move a merged splat config's output paths; config/... inputs stay where they are."""
    for key in OUTPUT_OPTS:
        if isinstance(opts.get(key), str):
            opts[key] = str(layout.tree_path(opts[key]))
    syms = opts.get("symbol_addrs_path")
    if isinstance(syms, list):
        opts["symbol_addrs_path"] = [str(layout.tree_path(p)) if isinstance(p, str) else p for p in syms]
    elif isinstance(syms, str):
        opts["symbol_addrs_path"] = str(layout.tree_path(syms))


def main():
    if layout.BUILD_ROOT != "build":
        from splat.util import options
        original = options.initialize

        def initialize(config, *args, **kwargs):
            if isinstance(config.get("options"), dict):
                move_paths(config["options"])
            return original(config, *args, **kwargs)

        options.initialize = initialize
    from splat.__main__ import splat_main
    splat_main()


if __name__ == "__main__":
    main()
