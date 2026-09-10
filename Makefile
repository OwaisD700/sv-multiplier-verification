MODULE ?= adder

test: build
	./obj_dir/tb_$(MODULE)

build:
	verilator --cc -Wall --exe --build --top-module $(MODULE) rtl/*.sv tb/tb_$(MODULE).cpp -o tb_$(MODULE)

clean:
	rm -rf obj_dir