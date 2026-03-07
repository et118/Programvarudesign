DOCKER_CMD := $(if $(shell command -v podman), podman, docker)

.PHONY: all build run clean

all: run

build:
	$(DOCKER_CMD) build -t programvarudesign .

run: build
	$(DOCKER_CMD) run -it --rm programvarudesign

clean:
	$(DOCKER_CMD) rmi programvarudesign