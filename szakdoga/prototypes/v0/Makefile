PROTO=./../bin/proto

.PHONY: build run setup clean

clean:
	rm -rf bin/
	rm -rf test/.prot

build:
	mkdir -p bin
	go build -o bin/proto ./src/cmd/proto1/

run:
	go run ./src/cmd/proto1/

setup:
	$(PROTO) init

	$(PROTO) add a.txt
	$(PROTO) add src/b.txt
	$(PROTO) add src/pkg/c.txt
			
	$(PROTO) commit "test commit"

	$(PROTO) branch "feat"
