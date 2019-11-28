#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=malloc-benchmarks
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/jneuhauser/malloc-benchmarks/tar.gz/$(PKG_VERSION)?
PKG_HASH:=d5ceb3682a1762280670d8804ee004869cd30f264a46545d8bc1430cc4698188

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
#PKG_LICENSE:=MIT
#PKG_LICENSE_FILES:=LICENSE

CMAKE_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/malloc-benchmarks
  SECTION:=utils
  CATEGORY:=Utilities
  URL:=https://github.com/jneuhauser/malloc-benchmarks
  DEPENDS:= +libpthread
  TITLE:=malloc benchmarks
endef

define Package/malloc-benchmarks/description
  malloc benchmarks
endef

CMAKE_OPTIONS += -DCMAKE_VERBOSE_MAKEFILE=ON

define Package/malloc-benchmarks/install
	$(INSTALL_DIR) $(1)/usr/local/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/local/bin/* $(1)/usr/local/bin/
endef

$(eval $(call BuildPackage,malloc-benchmarks))
