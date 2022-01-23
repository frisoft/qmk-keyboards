USER = frisoft

KEYBOARDS = dactyl_manuform
# KEYBOARDS = dactyl_manuform kyria
PATH_dactyl_manuform = handwired/dactyl_manuform/4x5

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS) update setup
$(KEYBOARDS):
	@echo run lint check
	cd qmk_firmware; qmk lint -km $(USER) -kb $(PATH_$@) --strict

	@echo falsh
	make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware $(PATH_$@):$(USER):flash

define rmlinks
	# cleanup symlinks
	$(foreach K, $(KEYBOARDS), rm -rf qmk_firmware/keyboards/$(PATH_$(K))/keymaps/$(USER))
endef

define mklinks
	# add new symlinks
	$(foreach K, $(KEYBOARDS), ln -s $(shell pwd)/$(K) qmk_firmware/keyboards/$(PATH_$(K))/keymaps/$(USER))
endef

setup:
	$(call rmlinks)
	git submodule update --init --recursive
	$(call mklinks)

update:
	$(call rmlinks)
	cd qmk_firmware; git fetch; git checkout master; git pull
	$(call mklinks)

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
