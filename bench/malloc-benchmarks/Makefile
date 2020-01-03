#
# Copyright (C) 2020 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=malloc-benchmarks
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=Apache-2.0
PKG_LICENSE_FILES:=

include $(INCLUDE_DIR)/package.mk

define Package/malloc-benchmarks
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+time +jemalloc +mimalloc +rpmalloc \
    +(i386||i686||x86_64):alloc-test +barnes +cache-scratch +cache-thrash \
    +cfrac +espresso +larson +malloc-large +malloc-test +mstress +rptest \
	+shbench +xmalloc-test
  TITLE:=malloc-benchmarks
endef

define Package/malloc-benchmarks/description
  A script that runs some known malloc benchmarks with some malloc libraries.
endef

define Build/Prepare/Default
	mkdir -p $(PKG_BUILD_DIR)
endef
Build/Prepare = $(Build/Prepare/Default)

define Build/Compile/Default

endef
Build/Compile = $(Build/Compile/Default)

define Build/Configure/Default

endef
Build/Configure = $(Build/Configure/Default)

define Package/malloc-benchmarks/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) ./files/run-malloc-benchmarks.sh $(1)/usr/bin/run-malloc-benchmarks
	$(INSTALL_BIN) ./files/malloc-bench-result2csv.sh $(1)/usr/bin/malloc-bench-result2csv
endef

$(eval $(call BuildPackage,malloc-benchmarks))
