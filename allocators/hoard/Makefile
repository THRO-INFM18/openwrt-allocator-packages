#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=hoard
PKG_VERSION:=3.13
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/emeryberger/Hoard/tar.gz/$(PKG_VERSION)?
PKG_HASH:=55b4278e6210d221fdcdd5c9e59c301d8281ef4bdb881492c9fd889bbf67c317
#PKG_SOURCE_PROTO:=git
#PKG_SOURCE_URL:=https://github.com/emeryberger/Hoard.git
#PKG_SOURCE_VERSION:=c856b43e9576a7343b20a5def7d15ca7b634940e
#PKG_MIRROR_HASH:=a39f299fbdb6c79699dbf101c61313a78c7d184423954b441464904d483e47a8

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=Apache-2.0
PKG_LICENSE_FILES:=LICENSE

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/hoard
  SECTION:=libs
  CATEGORY:=Libraries
  URL:=https://github.com/emeryberger/Hoard
  DEPENDS:= +librt +libstdcpp
  TITLE:=hoard general purpose allocator
endef

define Package/hoard/description
  The Hoard memory allocator is a fast, scalable, and memory-efficient memory allocator
  that works on a range of platforms, including Linux, Mac OS X, and Windows.

  Hoard is a drop-in replacement for malloc that can dramatically improve application performance,
  especially for multithreaded programs running on multiprocessors and multicore CPUs.
  No source code changes necessary: just link it in or set one environment variable.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	mv $(PKG_BUILD_DIR)/../Hoard-*/src/* $(PKG_BUILD_DIR)/
endef

define Package/hoard/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/*.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,hoard))
