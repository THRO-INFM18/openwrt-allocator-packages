#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jemalloc
PKG_VERSION:=5.2.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/jemalloc/jemalloc/tar.gz/$(PKG_VERSION)?
PKG_HASH:=ed51b0b37098af4ca6ed31c22324635263f8ad6471889e0592a9c0dba9136aea
#PKG_SOURCE_PROTO:=git
#PKG_SOURCE_URL:=https://github.com/jemalloc/jemalloc.git
#PKG_SOURCE_VERSION:=ea6b3e973b477b8061e0076bb257dbd7f3faa756
#PKG_MIRROR_HASH:=a39f299fbdb6c79699dbf101c61313a78c7d184423954b441464904d483e47a8

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
### ??? LICENCE ???
PKG_LICENSE:=NLPL
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf
PKG_BUILD_PARALLEL:=1

#include $(INCLUDE_DIR)/uclibc++.mk
include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/autotools.mk

define Package/jemalloc
  SECTION:=libs
  CATEGORY:=Libraries
  URL:=https://github.com/jemalloc/jemalloc
  DEPENDS:= +librt +libstdcpp
  TITLE:=jemalloc general purpose allocator
endef

define Package/jemalloc/description
  jemalloc is a general purpose malloc(3) implementation that emphasizes
  fragmentation avoidance and scalable concurrency support.  jemalloc first came
  into use as the FreeBSD libc allocator in 2005, and since then it has found its
  way into numerous applications that rely on its predictable behavior.  In 2010
  jemalloc development efforts broadened to include developer support features
  such as heap profiling and extensive monitoring/tuning hooks.  Modern jemalloc
  releases continue to be integrated back into FreeBSD, and therefore versatility
  remains critical.  Ongoing development efforts trend toward making jemalloc
  among the best allocators for a broad range of demanding applications, and
  eliminating/mitigating weaknesses that have practical repercussions for real
  world applications.
endef

# jemalloc supports a runtime page size that's smaller or equal to the build
# time one, but aborts on a larger one. If not defined, it falls back to the
# the build system's _SC_PAGESIZE, which in many architectures can vary. Set
# this to 4K on x86 for performance, and set it to 64K (2^16) on every other
# architecture, which should be a reasonable maximum. See Debian #843926, as
# well as upstream #467 for more context.
ifneq (,$(filter $(ARCH),i386 i686 x86_64))
  CONFIGURE_ARGS += --with-lg-page=12
else
  CONFIGURE_ARGS += --with-lg-page=16
endif

# 2MB (2^21) is the default, but (as of 5.1.0) is overriden by whatever is
# found in /proc/meminfo. Avoid relying on the build system's configuration and
# just set it statically here.
CONFIGURE_ARGS += --with-lg-hugepage=21

# Broken multiple times on random architectures using all the different methods
# (including libunwind). Profiling is nice-to-have but not necessary, and
# i386/amd64 seem regularly tested by upstream, so enable it only for these.
ifneq (,$(filter $(ARCH),i386 i686 x86_64))
  DEPENDS += +PACKAGE_libunwind:libunwind
  CONFIGURE_ARGS += --enable-prof
endif

ifneq (,$(filter $(ARCH),powerpc))
  TARGET_CPPFLAGS += -maltivec
endif

define Package/jemalloc/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/*.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,jemalloc))
