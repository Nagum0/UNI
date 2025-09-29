PROTO=./bin/proto

.PHONY: build run setup clean

clean:
	rm -rf bin/
	rm -rf .prot/

build:
	mkdir -p bin
	go build -o bin/proto ./src/cmd/proto1/

run:
	go run ./src/cmd/proto1/

setup:
	$(PROTO) init

	$(PROTO) add README.md
	$(PROTO) add src/cmd/proto1/main.go
	$(PROTO) add src/pkg/commands.go
	$(PROTO) add src/pkg/objects.go
	$(PROTO) add bin/proto
	
	$(PROTO) commit "test commit"

	$(PROTO) branch "feat"
