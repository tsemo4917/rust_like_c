add_rules("mode.debug", "mode.release")

-- toolchain
add_requires("llvm 14.0.0", {alias = "llvm-14"})
set_toolchains("llvm@llvm-14")

-- dependency
add_requires("zlog")

target("hello")
    set_kind("binary")
    add_files("src/*.c")
    add_includedirs("include")
    add_packages("zlog")
