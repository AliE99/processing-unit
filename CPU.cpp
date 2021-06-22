#include "systemc.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

SC_MODULE(CPU)
{
    sc_in_clk Clock;
    sc_in<sc_logic> instruction_opcode;
    //sc_out<sc_lv<8>> data_out;

    sc_int<5> trans_state = 0;
    sc_lv<11> temp = "00000000000";

    void cpu_runner() {
        cout << "CPU RUNNER" << endl;
    }

    SC_CTOR(CPU)
    {
        cout << "Executing new" << endl;
        SC_METHOD(cpu_runner);
        sensitive << Clock;
    }
};

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> clock;
    sc_signal<sc_logic> instruction_opcode;
    //sc_signal<sc_lv<8>> data_out;


    CPU cpu("CPU_1");
    cpu.Clock(clock);
    cpu.instruction_opcode(instruction_opcode);

    //sc_start();
    sc_trace_file* wf = sc_create_vcd_trace_file("CPU");
    sc_trace(wf, clock, "clock");

    clock = 0;
    sc_start();

    clock = 1;
    sc_start();


    clock = 0;
    sc_start();

    return (0);
}
