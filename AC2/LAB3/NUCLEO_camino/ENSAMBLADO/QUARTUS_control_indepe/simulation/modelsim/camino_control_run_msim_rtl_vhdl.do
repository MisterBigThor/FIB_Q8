transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/tipos_ctes_pkg/retardos_nucleo_pkg.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/tipos_ctes_pkg/cte_tipos_nucleo_pkg.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/COMPONENTES/multiplexores/CODIGO/multiplexor_1.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/COMPONENTES/control/componentes_control_pkg/componentes_control_pkg.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/COMPONENTES/componentes_nucleo_pkg/componentes_nucleo_pkg.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/COMPONENTES/multiplexores/CODIGO/multiplexor.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/COMPONENTES/BR/CODIGO/br.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/COMPONENTES/Sumador/CODIGO/sumador.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/COMPONENTES/control/COMPONENTES/registros/CODIGO/reg1.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/COMPONENTES/control/COMPONENTES/registros/CODIGO/registro.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/ENSAMBLADO/CODIGO/camino_control.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/COMPONENTES/control/control_indep/CODIGO/control.vhd}

vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/ENSAMBLADO/QUARTUS_control_indepe/../../../UTILIDADES_pkg/impri_BR_pkg/impri_BR_pkg.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/ENSAMBLADO/QUARTUS_control_indepe/../UTILIDADES_pkg/prueba_procedimientos_camino_control.vhd}
vcom -2008 -work work {D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/ENSAMBLADO/QUARTUS_control_indepe/../PRUEBAS_control_indepe/prueba_camino_control.vhd}

vsim -t 1ps -L altera -L lpm -L sgate -L altera_mf -L altera_lnsim -L cycloneiv_hssi -L cycloneiv_pcie_hip -L cycloneiv -L rtl_work -L work -voptargs="+acc"  prueba_camino_control

do D:/FIB_Q8/AC2/LAB3/NUCLEO_camino/ENSAMBLADO/QUARTUS_control_indepe/../PRUEBAS_control_indepe/formato_ventanas.do
