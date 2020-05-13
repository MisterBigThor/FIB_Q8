transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/tipos_constantes_pkg/riscv32_coop_funct_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/tipos_constantes_pkg/retardos_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/tipos_constantes_pkg/retardos_even_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/tipos_constantes_pkg/cte_tipos_deco_camino_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/tipos_constantes_pkg/param_disenyo_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/COMPONENTES/ELEMENTOS/mux2m.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MI/tipos_ctes_MI_pkg/tipos_constan_memoria_I_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/USecuen/componentes_secuenciamiento_pkg/componentes_secuenciamiento_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/UCalculo/componentes_cam_datos_pkg/componentes_cam_datos_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/AUTO_CONTROL/DECODIFICADOR/CODIGO/componentes_decodificador_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/tipos_ctes_MD_pkg/tipos_constan_memoria_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/tipos_constantes_pkg/cte_tipos_UF_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CP/CODIGO/regcp.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/AUTO_CONTROL/DECODIFICADOR/CODIGO/decocamino.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/AUTO_CONTROL/DECODIFICADOR/CODIGO/decoopalu.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/AUTO_CONTROL/DECODIFICADOR/CODIGO/decoopmd.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/AUTO_CONTROL/DECODIFICADOR/CODIGO/deco_excep.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/UCalculo/COMPONENTES/FMTD/CODIGO/fmtd.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/UCalculo/COMPONENTES/BR/CODIGO/br.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/UCalculo/COMPONENTES/MULTIPLEXORES/CODIGO/mux3.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/UCalculo/COMPONENTES/MULTIPLEXORES/CODIGO/mux2.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/USecuen/COMPONENTES/CUATRO/CODIGO/cuatro.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/USecuen/COMPONENTES/SUMADOR/CODIGO/sumador.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/USecuen/COMPONENTES/FMTS/CODIGO/fmts.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/USecuen/COMPONENTES/MULTIPLEXORES/CODIGO/muxdirec.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/USecuen/COMPONENTES/SUMADOR/CODIGO/sum_secu.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/USecuen/COMPONENTES/acceso_MI/CODIGO/acceso_mi.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/COMPONENTES/ACCESO/CODIGO/acceso_md.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/MD/componentes_MD_fmte_pkg/componentes_MD_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/MD/COMPONENTES/FMTE/componentes_FMTE_pkg/componentes_FMTE_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MI/componentes_MI_pkg/componentes_MI_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/componentes_proc_MD_MI_pkg/componentes_proc_MD_MI_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MI/memoria_MI/CODIGO/ini_mem_I_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/memoria_ram/CODIGO/ini_mem_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/ENSAMBLADO_DECO_UC_US/CODIGO/deco_cam_dat_secu.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/AUTO_CONTROL/DECODIFICADOR/CODIGO/decodificador.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/AUTO_CONTROL/DECODIFICADOR/CODIGO/decoopsec.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/UCalculo/ENSAMBLADO_UC/CODIGO/camino_datos.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/UCalculo/COMPONENTES/ALU/CODIGO/alu.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/USecuen/DECS/CODIGO/decs.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/USecuen/ENSAMBLADO_US/CODIGO/camino_secuen.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/PROCESADOR/CAMINO_DATOS/USecuen/COMPONENTES/EVALUACION/CODIGO/eval.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/COMPONENTES/FMTE/COMPONENTES/SELEC_BYTE/CODIGO/sel_byte.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/COMPONENTES/FMTL/COMPONENTES/SEL_SIGNO/CODIGO/fmtl_sel_signo.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/ENSAMBLADO/CODIGO/proc_MD_MI_fmte.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MI/ENSAMBLADO_componentes_MI/CODIGO/cam_mem_inst.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MI/memoria_MI/CODIGO/mi.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/ENSAMBLADO_compontes_memoria/CODIGO/cam_mem_datos.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/MD/COMPONENTES/FMTE/ENSAMBLADO_FMTE/CODIGO/fmte.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/MD/COMPONENTES/FMTE/COMPONENTES/ALINEARE/CODIGO/alineare.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/memoria_ram/CODIGO/md.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/COMPONENTES/FMTL/ENSAMBLADO_FMTL/CODIGO/fmtl.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/COMPONENTES/FMTL/COMPONENTES/ALINEAR/CODIGO/alinear.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/COMPONENTES/FMTL/COMPONENTES/EXTSIG/CODIGO/fmtl_extsig.vhd}

vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/ENSAMBLADO/QUARTUS/../../../PROC_SERIE/UTILIDADES_pkg/generar_impri_instruc_pkg/imprimir_inst_ascii_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/ENSAMBLADO/QUARTUS/../../../PROC_SERIE/UTILIDADES_pkg/impri_instruc_pkg/deco_Inst_impri_pkg.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/ENSAMBLADO/QUARTUS/../../../PROC_SERIE/UTILIDADES_pkg/imprimir_traza_pkg/impri_traza_pkg.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/ENSAMBLADO/QUARTUS/../../../PROC_SERIE/UTILIDADES_pkg/impri_BR_memoria_pkg/impri_BR_pkg.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/ENSAMBLADO/QUARTUS/../../../PROC_SERIE/UTILIDADES_pkg/impri_BR_memoria_pkg/impri_MD_pkg.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/ENSAMBLADO/QUARTUS/../../../PROC_SERIE/UTILIDADES_pkg/impri_BR_memoria_pkg/impri_MI_pkg.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/ENSAMBLADO/QUARTUS/../PRUEBAS/prueba_proc_MD_MI_fmte.vhd}

vsim -t 1ps -L altera -L lpm -L sgate -L altera_mf -L altera_lnsim -L cycloneiv_hssi -L cycloneiv_pcie_hip -L cycloneiv -L rtl_work -L work -voptargs="+acc"  prueba_proc_MD_MI_fmte

do D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/ENSAMBLADO/QUARTUS/../PRUEBAS/formato_ventanas.do
