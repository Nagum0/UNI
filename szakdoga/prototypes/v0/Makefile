PROTO=./../bin/proto

.PHONY: build run setup clean

clean:
	rm -rf bin/
	rm -rf test/src/
	rm -rf test/a.txt

build:
	mkdir -p bin
	go build -o bin/proto ./src/cmd/proto1/

run:
	go run ./src/cmd/proto1/

setup:
	mkdir -p src/
	mkdir -p src/pkg/
	echo "Hello A!" > a.txt
	echo "Hello B!" > src/b.txt
	echo "Hello B2!" > src/b2.txt
	echo "Hello C!" > src/pkg/c.txt
	echo "Hello C2!" > src/pkg/c2.txt

	$(PROTO) init

	$(PROTO) add a.txt
	$(PROTO) add src/b.txt
	$(PROTO) add src/pkg/c.txt
			
	$(PROTO) commit "test commit"

	$(PROTO) branch "feat"
