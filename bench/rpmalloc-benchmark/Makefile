#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rpmalloc-benchmark
PKG_VERSION:=f4927445
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/mjansson/rpmalloc-benchmark.git
PKG_SOURCE_VERSION:=f492744530a349b9b6c831305b25aec0ec5a6a5b
PKG_MIRROR_HASH:=a6363d2bf33bd3847ea3eb5f1bce629ca8fa658e640d5fcc245dbb061e4d4583

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=LICENSE

PKG_BUILD_DEPENDS:=ninja/host

include $(INCLUDE_DIR)/package.mk

define Package/rpmalloc-benchmark
  SECTION:=utils
  CATEGORY:=Utilities
  URL:=https://github.com/jneuhauser/malloc-benchmarks
  DEPENDS:= +libc +libpthread +libstdcpp
  TITLE:=rpmalloc benchmarks
endef

define Package/rpmalloc-benchmark/description
  rpmalloc benchmarks
endef

# Seems to work for all archs
PKG_TARGET_ARCH := generic

define Build/Configure
	export \
		AR=$(TARGET_AR) \
		CC=$(TARGET_CC) \
		CXX=$(TARGET_CXX) \
		LD=$(TARGET_LD) \
		ARFLAGS="$(TARGET_ARFLAGS) $(EXTRA_ARFLAGS)" \
		CFLAGS="$(TARGET_CFLAGS) $(EXTRA_CFLAGS)" \
		CXXFLAGS="$(TARGET_CXXFLAGS) $(EXTRA_CXXFLAGS)" \
		LDFLAGS="$(TARGET_LDFLAGS) $(EXTRA_LDFLAGS)" \
	&& \
	cd $(PKG_BUILD_DIR) \
	&& \
	./configure.py \
		--toolchain gcc \
		--config release \
		--arch $(PKG_TARGET_ARCH)
endef

include $(TOPDIR)/package/feeds/packages/ninja/ninja.mk

NINJA_ENV_VARS += 

define Build/Compile
	$(call Ninja,-C $(PKG_BUILD_DIR) -v,$(NINJA_ENV_VARS))
endef

define Package/rpmalloc-benchmark/install
	$(INSTALL_DIR) $(1)/usr/local/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/bin/linux/release/$(PKG_TARGET_ARCH)/benchmark-* $(1)/usr/local/bin/
endef

$(eval $(call BuildPackage,rpmalloc-benchmark))
