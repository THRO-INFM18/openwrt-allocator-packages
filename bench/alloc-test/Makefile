#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=alloc-test
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=
PKG_LICENSE_FILES:=

CMAKE_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/alloc-test
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libpthread +libstdcpp
  TITLE:=alloc-test
endef

define Package/alloc-test/description
  No one knows something about it, but it´s used for benchmarking malloc implementations.
endef

define Package/alloc-test/install
	$(INSTALL_DIR) $(1)/usr/local/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/local/bin/alloc-test $(1)/usr/local/bin/
endef

$(eval $(call BuildPackage,alloc-test))
