DOCKER_CMD := $(if $(shell command -v podman), podman, docker)

.PHONY: all build run test clean

all: run

build:
	$(DOCKER_CMD) build -t programvarudesign .

run: build
	$(DOCKER_CMD) run -it --rm programvarudesign

test: build
	$(DOCKER_CMD) run -it --rm programvarudesign ./build/tests

clean:
	$(DOCKER_CMD) rmi programvarudesign