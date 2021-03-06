include ../Common.mk

TARGET = usbdm
MODULE = usbdm

DLL_DEFS = -DUSBDM_DLL_EXPORTS -DLINK_USBDM_SYSTEM_DLL
STATIC_DEFS = -static -static-libgcc -static-libstdc++

$(TARGET):
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@${VSUFFIX} MODULE=$(MODULE)  CDEFS='$(DLL_DEFS)'

$(TARGET)-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@${VSUFFIX} MODULE=$(MODULE)  CDEFS='$(DLL_DEFS)'  DEBUG='Y'

$(TARGET)-static:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@${VSUFFIX} MODULE=$(MODULE)  CDEFS='$(DLL_DEFS)' LFLAGS='$(STATIC_DEFS)'

$(TARGET)-static-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@${VSUFFIX} MODULE=$(MODULE)  CDEFS='$(DLL_DEFS)'  LFLAGS='$(STATIC_DEFS)' DEBUG='Y'

osbdm-jm60:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@  MODULE=osbdm      CDEFS='$(DLL_DEFS)'

osbdm-jm60-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@  MODULE=osbdm      CDEFS='$(DLL_DEFS)'  DEBUG='Y'

usbdm-cff:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@  MODULE=cfflasher  CDEFS='$(DLL_DEFS)'  EXTRA_LINK_OPTS='-Wl,--kill-at' 

usbdm-cff-debug:
	@echo ''
	@echo  Building $@
	@echo "================================================================"
	$(MAKE) dll -f Target.mk BUILDDIR=$@$(BUILDDIR_SUFFIX) TARGET=$@  MODULE=cfflasher  CDEFS='$(DLL_DEFS)'  EXTRA_LINK_OPTS='-Wl,--kill-at'  DEBUG='Y'

allCommon: $(TARGET) $(TARGET)-debug

cleanCommon:
	-${RMDIR} $(TARGET)$(BUILDDIR_SUFFIX) $(TARGET)-debug$(BUILDDIR_SUFFIX)

ifeq ($(UNAME_S),Windows)
allWindows: osbdm-jm60 osbdm-jm60-debug usbdm-cff usbdm-cff-debug 
allWindows: $(TARGET)-static $(TARGET)-static-debug

cleanWindows:
	${RMDIR} osbdm-jm60${BUILDDIR_SUFFIX} osbdm-jm60-debug${BUILDDIR_SUFFIX}
	${RMDIR} usbdm-cff${BUILDDIR_SUFFIX}  usbdm-cff-debug${BUILDDIR_SUFFIX}
	${RMDIR} $(TARGET)-static$(BUILDDIR_SUFFIX) $(TARGET)-static-debug$(BUILDDIR_SUFFIX)
else
allWindows:
cleanWindows:
endif

all: allCommon allWindows

clean: cleanCommon cleanWindows

test: $(TARGET)-debug

.PHONY: all clean 
.PHONY: $(TARGET)-static $(TARGET)-static-debug
.PHONY: $(TARGET) $(TARGET)-debug
.PHONY: allCommon allWindows cleanCommon cleanWindows
.PHONY: osbdm-jm60 osbdm-jm60-debug usbdm-cff usbdm-cff-debug
.PHONY: test
