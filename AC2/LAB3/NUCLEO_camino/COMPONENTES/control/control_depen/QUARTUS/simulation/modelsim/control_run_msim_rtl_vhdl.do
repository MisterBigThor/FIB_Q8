transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {D:/FIBQ7/AC2/LAB3.tar/LAB3/NUCLEO_camino/tipos_ctes_pkg/retardos_nucleo_pkg.vhd}
vcom -93 -work work {D:/FIBQ7/AC2/LAB3.tar/LAB3/NUCLEO_camino/tipos_ctes_pkg/cte_tipos_nucleo_pkg.vhd}
vcom -93 -work work {D:/FIBQ7/AC2/LAB3.tar/LAB3/NUCLEO_camino/COMPONENTES/control/componentes_control_pkg/componentes_control_pkg.vhd}
vcom -93 -work work {D:/FIBQ7/AC2/LAB3.tar/LAB3/NUCLEO_camino/COMPONENTES/control/COMPONENTES/registros/CODIGO/reg1.vhd}
vcom -93 -work work {D:/FIBQ7/AC2/LAB3.tar/LAB3/NUCLEO_camino/COMPONENTES/control/COMPONENTES/registros/CODIGO/registro.vhd}
vcom -93 -work work {D:/FIBQ7/AC2/LAB3.tar/LAB3/NUCLEO_camino/COMPONENTES/control/control_depen/CODIGO/control.vhd}

vcom -93 -work work {D:/FIBQ7/AC2/LAB3.tar/LAB3/NUCLEO_camino/COMPONENTES/control/control_depen/QUARTUS/../PRUEBAS/prueba_control.vhd}

vsim -t 1ps -L altera -L lpm -L sgate -L altera_mf -L altera_lnsim -L cycloneiv_hssi -L cycloneiv_pcie_hip -L cycloneiv -L rtl_work -L work -voptargs="+acc"  prueba_control

do D:/FIBQ7/AC2/LAB3.tar/LAB3/NUCLEO_camino/COMPONENTES/control/control_depen/QUARTUS/../PRUEBAS/formato_ventanas.do
