#
# Copyright (C) 2019 Johann Neuhauser <johann@it-neuhauser.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=gperftools
PKG_VERSION:=2.7
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/gperftools/gperftools.git
PKG_SOURCE_VERSION:=9608fa3bcf8020d35f59fbf70cd3cbe4b015b972
PKG_MIRROR_HASH:=63f3e9c0b9d08ba4d02f84ddb91113c961d23e2e625f5c7c30a472d6674eb8de

PKG_MAINTAINER:=Johann Neuhauser <johann@it-neuhauser.de>
PKG_LICENSE:=BSD-3-Clause
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/autotools.mk

define Package/gperftools
  SECTION:=libs
  CATEGORY:=Libraries
  URL:=https://github.com/gperftools/gperftools
  DEPENDS:= +librt +PACKAGE_libunwind:libunwind
  TITLE:=optimized thread-caching malloc
endef

define Package/gperftools/description
  The gperftools, previously called google-perftools,
  package contains some utilities to improve and analyze the performance of C++ programs.
endef

define Package/libtcmalloc/default
  SECTION:=libs
  CATEGORY:=Libraries
  URL:=https://github.com/gperftools/gperftools
  DEPENDS:= +librt
  TITLE:=optimized thread-caching malloc
endef

define Package/libtcmalloc-full
  $(call Package/libtcmalloc/default)
  TITLE+=(full)
  VARIANT:=full
endef

define Package/libtcmalloc-full/description
  $(call Package/gperftools/description)

  This is a part of that package, and includes an optimized thread-caching malloc.
endef

# enable libunwind only on x86
ifeq ($(ARCH),$(filter $(ARCH),x86 x86_64))
  DEPENDS+= +PACKAGE_libunwind:libunwind
else
  CONFIGURE_ARGS+= --disable-libunwind
endif

define Package/libtcmalloc-minimal
  $(call Package/libtcmalloc/default)
  TITLE+=(minimal)
  VARIANT:=minimal
  DEFAULT_VARIANT:=1
endef

Package/libtcmalloc-minimal/description = $(Package/libtcmalloc-full/description)

ifeq ($(BUILD_VARIANT),minimal)
  CONFIGURE_ARGS+= --enable-minimal
endif

define Package/libtcmalloc/install/default
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/*.so* $(1)/usr/lib/
endef

Package/libtcmalloc-full/install = $(Package/libtcmalloc/install/default)
Package/libtcmalloc-minimal/install = $(Package/libtcmalloc/install/default)

$(eval $(call BuildPackage,libtcmalloc-full))
$(eval $(call BuildPackage,libtcmalloc-minimal))
