SUMMARY = "Linux kernel"
SECTION = "kernel"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

# x86 builds use ORC unwinder by default which needs libelf
DEPENDS:append:x86-64 = " elfutils-native"

SRC_URI = " \
    git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git;branch=linux-5.15.y;protocol=https \
    file://defconfig \
"
SRCREV = "793d8378b74ac283a4dd7cef1b304553c8a42260"

LINUX_VERSION = "5.15.77"
PV = "${LINUX_VERSION}"

# Prevent kernel module packages from depending on virtual/kernel. This lets
# the kernel modules be installed in the initramfs without pulling in the
# kernel binary.
KERNEL_MODULE_PROVIDE_VIRTUAL = "0"

inherit kernel
inherit kernel-yocto
