# 
# Synthesis run script generated by Vivado
# 

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_msg_config -source 4 -id {IP_Flow 19-2162} -severity warning -new_severity info
set_property webtalk.parent_dir H:/simd_final_test/simd_final/project_3/project_3.cache/wt [current_project]
set_property parent.project_path H:/simd_final_test/simd_final/project_3/project_3.xpr [current_project]
set_property XPM_LIBRARIES {XPM_CDC XPM_MEMORY} [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language VHDL [current_project]
set_property board_part digilentinc.com:nexys-a7-100t:part0:1.0 [current_project]
set_property ip_output_repo h:/simd_final_test/simd_final/project_3/project_3.cache/ip [current_project]
set_property ip_cache_permissions {read write} [current_project]
read_vhdl -library xil_defaultlib H:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/hdl/design_1_wrapper.vhd
add_files H:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/design_1.bd
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_microblaze_0_0/design_1_microblaze_0_0.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_microblaze_0_0/design_1_microblaze_0_0_ooc_debug.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_microblaze_0_0/design_1_microblaze_0_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_microblaze_1_0/design_1_microblaze_1_0.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_microblaze_1_0/design_1_microblaze_1_0_ooc_debug.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_microblaze_1_0/design_1_microblaze_1_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_clk_wiz_0_0/design_1_clk_wiz_0_0_board.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_clk_wiz_0_0/design_1_clk_wiz_0_0.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_clk_wiz_0_0/design_1_clk_wiz_0_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_dlmb_v10_0/design_1_dlmb_v10_0.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_dlmb_v10_0/design_1_dlmb_v10_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_ilmb_v10_0/design_1_ilmb_v10_0.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_ilmb_v10_0/design_1_ilmb_v10_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_dlmb_bram_if_cntlr_0/design_1_dlmb_bram_if_cntlr_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_ilmb_bram_if_cntlr_0/design_1_ilmb_bram_if_cntlr_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_lmb_bram_0/design_1_lmb_bram_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_mdm_1_0/design_1_mdm_1_0.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_mdm_1_0/design_1_mdm_1_0_ooc_trace.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_rst_clk_wiz_0_100M_0/design_1_rst_clk_wiz_0_100M_0_board.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_rst_clk_wiz_0_100M_0/design_1_rst_clk_wiz_0_100M_0.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_rst_clk_wiz_0_100M_0/design_1_rst_clk_wiz_0_100M_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_dlmb_v10_1/design_1_dlmb_v10_1.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_dlmb_v10_1/design_1_dlmb_v10_1_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_ilmb_v10_1/design_1_ilmb_v10_1.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_ilmb_v10_1/design_1_ilmb_v10_1_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_dlmb_bram_if_cntlr_1/design_1_dlmb_bram_if_cntlr_1_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_ilmb_bram_if_cntlr_1/design_1_ilmb_bram_if_cntlr_1_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_lmb_bram_1/design_1_lmb_bram_1_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_axi_uartlite_0_0/design_1_axi_uartlite_0_0_board.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_axi_uartlite_0_0/design_1_axi_uartlite_0_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_axi_uartlite_0_0/design_1_axi_uartlite_0_0.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_xbar_0/design_1_xbar_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_blk_mem_gen_0_1/design_1_blk_mem_gen_0_1_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_axi_bram_ctrl_0_0/design_1_axi_bram_ctrl_0_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_axi_timer_0_0/design_1_axi_timer_0_0.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_axi_timer_0_0/design_1_axi_timer_0_0_ooc.xdc]
set_property used_in_implementation false [get_files -all h:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/ip/design_1_auto_pc_0/design_1_auto_pc_0_ooc.xdc]
set_property used_in_implementation false [get_files -all H:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/design_1_ooc.xdc]
set_property is_locked true [get_files H:/simd_final_test/simd_final/project_3/project_3.srcs/sources_1/bd/design_1/design_1.bd]

foreach dcp [get_files -quiet -all *.dcp] {
  set_property used_in_implementation false $dcp
}
read_xdc H:/simd_final_test/simd_final/project_3/project_3.srcs/constrs_2/new/cons2.xdc
set_property used_in_implementation false [get_files H:/simd_final_test/simd_final/project_3/project_3.srcs/constrs_2/new/cons2.xdc]

read_xdc dont_touch.xdc
set_property used_in_implementation false [get_files dont_touch.xdc]

synth_design -top design_1_wrapper -part xc7a100tcsg324-1


write_checkpoint -force -noxdef design_1_wrapper.dcp

catch { report_utilization -file design_1_wrapper_utilization_synth.rpt -pb design_1_wrapper_utilization_synth.pb }
