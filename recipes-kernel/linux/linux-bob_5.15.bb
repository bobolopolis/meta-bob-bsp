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

# Prevent the kernel binary from being pulled into the image.
RRECOMMENDS:${KERNEL_PACKAGE_NAME}-base = ""

inherit kernel
inherit kernel-yocto
