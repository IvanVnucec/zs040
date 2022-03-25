BUILD_FOLDER = build

.PHONY: all install_deps setup_cmake build test docs clean

all: build

install_deps:
	sudo apt-get install -y gcc cmake ninja-build doxygen

setup_cmake: 
	rm -rf $(BUILD_FOLDER)
	mkdir $(BUILD_FOLDER)
	cd $(BUILD_FOLDER) && \
	cmake -GNinja ..

build:
	cd $(BUILD_FOLDER) && ninja

test: build
	cd $(BUILD_FOLDER) && ninja test

docs:
	cd $(BUILD_FOLDER) && ninja docs

clean:
	rm -rf $(BUILD_FOLDER)

help:
	@echo all install_deps setup_cmake build test docs clean