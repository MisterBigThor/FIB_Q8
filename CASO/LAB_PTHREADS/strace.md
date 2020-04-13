execve("./pthreads.exe", ["./pthreads.exe", "4"], 0x7ffef4545ce8 /* 72 vars */) = 0
>execute a binary.

brk(NULL) = 0x5560c3fed000
> change data segment size

access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT



openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=118959, ...}) = 0
mmap(NULL, 118959, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f187e6ff000
close(3)                                = 0


access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)

openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpthread.so.0", O_RDONLY|O_CLOEXEC) = 3
read(3, "...", 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=144976, ...}) = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f187e6fd000
mmap(NULL, 2221184, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f187e2d7000
mprotect(0x7f187e2f1000, 2093056, PROT_NONE) = 0
mmap(0x7f187e4f0000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x19000) = 0x7f187e4f0000
mmap(0x7f187e4f2000, 13440, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f187e4f2000
close(3)                                = 0
> open the pthreads library, read 832 bytes & get file info.

access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\260\34\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=2030544, ...}) = 0
mmap(NULL, 4131552, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f187dee6000
mprotect(0x7f187e0cd000, 2097152, PROT_NONE) = 0
mmap(0x7f187e2cd000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1e7000) = 0x7f187e2cd000
mmap(0x7f187e2d3000, 15072, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f187e2d3000
close(3)                                = 0
> open another library

mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f187e6fa000
arch_prctl(ARCH_SET_FS, 0x7f187e6fa740) = 0
mprotect(0x7f187e2cd000, 16384, PROT_READ) = 0
mprotect(0x7f187e4f0000, 4096, PROT_READ) = 0
mprotect(0x5560c3f7d000, 4096, PROT_READ) = 0
mprotect(0x7f187e71d000, 4096, PROT_READ) = 0
munmap(0x7f187e6ff000, 118959)          = 0
set_tid_address(0x7f187e6faa10)         = 6826
set_robust_list(0x7f187e6faa20, 24)     = 0
rt_sigaction(SIGRTMIN, {sa_handler=0x7f187e2dccb0, sa_mask=[], sa_flags=SA_RESTORER|SA_SIGINFO, sa_restorer=0x7f187e2e9890}, NULL, 8) = 0
rt_sigaction(SIGRT_1, {sa_handler=0x7f187e2dcd50, sa_mask=[], sa_flags=SA_RESTORER|SA_RESTART|SA_SIGINFO, sa_restorer=0x7f187e2e9890}, NULL, 8) = 0
rt_sigprocmask(SIG_UNBLOCK, [RTMIN RT_1], NULL, 8) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
brk(NULL)                               = 0x5560c3fed000
brk(0x5560c400e000)                     = 0x5560c400e000
fstat(1, {st_mode=S_IFREG|0664, st_size=3060, ...}) = 0
mmap(NULL, 8392704, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0) = 0x7f187d6e5000
mprotect(0x7f187d6e6000, 8388608, PROT_READ|PROT_WRITE) = 0
**clone**(child_stack=0x7f187dee4fb0, flags=CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, parent_tidptr=0x7f187dee59d0, tls=0x7f187dee5700, child_tidptr=0x7f187dee59d0) = 6827
mmap(NULL, 8392704, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0) = 0x7f187cee4000
mprotect(0x7f187cee5000, 8388608, PROT_READ|PROT_WRITE) = 0
**clone**(child_stack=0x7f187d6e3fb0, flags=CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, parent_tidptr=0x7f187d6e49d0, tls=0x7f187d6e4700, child_tidptr=0x7f187d6e49d0) = 6828
mmap(NULL, 8392704, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0) = 0x7f187c6e3000
mprotect(0x7f187c6e4000, 8388608, PROT_READ|PROT_WRITE) = 0
**clone**(child_stack=0x7f187cee2fb0, flags=CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, parent_tidptr=0x7f187cee39d0, tls=0x7f187cee3700, child_tidptr=0x7f187cee39d0) = 6829
mmap(NULL, 8392704, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0) = 0x7f18777ff000
mprotect(0x7f1877800000, 8388608, PROT_READ|PROT_WRITE) = 0
**clone**(child_stack=0x7f1877ffefb0, flags=CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, parent_tidptr=0x7f1877fff9d0, tls=0x7f1877fff700, child_tidptr=0x7f1877fff9d0) = 6830

**futex**(0x7f187d6e49d0, FUTEX_WAIT, 6828, NULL) = 0

> 4 clone, one for each pthread and a futex (provides a method for waiting until certain condition becomes true.)

write(1, "PTHREAD CREATE: \nPTHREAD JOIN: \n"..., 52PTHREAD CREATE: 
PTHREAD JOIN: 
factorial de 4 = 24
) = 52
exit_group(0)                           = ?
+++ exited with 0 +++
