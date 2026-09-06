test: build
	./obj_dir/tb_and2

build:
	verilator --cc -Wall --exe --build rtl/and2.sv tb/tb_and2.cpp -o tb_and2

clean:
	rm -rf obj_dir