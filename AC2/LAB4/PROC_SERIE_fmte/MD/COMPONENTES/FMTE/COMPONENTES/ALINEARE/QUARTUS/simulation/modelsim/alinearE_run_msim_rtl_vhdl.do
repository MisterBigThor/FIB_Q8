transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/tipos_constantes_pkg/param_disenyo_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/tipos_constantes_pkg/cte_tipos_deco_camino_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/tipos_constantes_pkg/retardos_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/COMPONENTES/ELEMENTOS/mux2m.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE/MD/tipos_ctes_MD_pkg/tipos_constan_memoria_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/MD/COMPONENTES/FMTE/componentes_FMTE_pkg/componentes_FMTE_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/MD/COMPONENTES/FMTE/COMPONENTES/ALINEARE/CODIGO/alinearE.vhd}

vcom -93 -work work {D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/MD/COMPONENTES/FMTE/COMPONENTES/ALINEARE/QUARTUS/../PRUEBAS/prueba_alinearE.vhd}

vsim -t 1ps -L altera -L lpm -L sgate -L altera_mf -L altera_lnsim -L cycloneiv_hssi -L cycloneiv_pcie_hip -L cycloneiv -L rtl_work -L work -voptargs="+acc"  prueba_alinearE

do D:/FIB_Q8/AC2/LAB4/PROC_SERIE_fmte/MD/COMPONENTES/FMTE/COMPONENTES/ALINEARE/QUARTUS/../PRUEBAS/formato_ventanas.do
