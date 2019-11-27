#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rpmalloc
PKG_VERSION:=1.4.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/mjansson/rpmalloc/tar.gz/$(PKG_VERSION)?
PKG_HASH:=c5b63c40253d7f048d4489a6fa78e7a0c77d90037018c712df3bf68c033888a8

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=Unlicense
PKG_LICENSE_FILES:=LICENSE

PKG_BUILD_DEPENDS:=ninja/host

include $(INCLUDE_DIR)/package.mk

define Package/rpmalloc
  SECTION:=libs
  CATEGORY:=Libraries
  URL:=https://github.com/mjansson/rpmalloc
  DEPENDS:=+libpthread
  TITLE:=cross platform lock free thread caching 16-byte aligned memory allocator implemented in C
endef

define Package/rpmalloc/description
  This library provides a public domain cross platform lock free thread caching 16-byte aligned memory allocator implemented in C.
  The latest source code is always available at https://github.com/mjansson/rpmalloc
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

define Package/rpmalloc/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/bin/linux/release/$(PKG_TARGET_ARCH)/*.so $(1)/usr/lib/
endef

$(eval $(call BuildPackage,rpmalloc))
