@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.3\\bin
call %xv_path%/xsim design_1_wrapper_time_impl -key {Post-Implementation:sim_1:Timing:design_1_wrapper} -tclbatch design_1_wrapper.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
