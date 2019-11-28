#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cache-scratch
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=Unknown
PKG_LICENSE_FILES:=README.md

CMAKE_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/cache-scratch
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libpthread +libstdcpp
  TITLE:=cache-scratch
endef

define Package/cache-scratch/description
  No one knows something about it, but it´s used for benchmarking malloc implementations.
endef

define Package/cache-scratch/install
	$(INSTALL_DIR) $(1)/usr/local/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/local/bin/cache-scratch $(1)/usr/local/bin/
endef

$(eval $(call BuildPackage,cache-scratch))
