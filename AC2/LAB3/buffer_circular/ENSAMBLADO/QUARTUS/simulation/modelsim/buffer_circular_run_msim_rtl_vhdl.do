transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/tipos_ctes_pkg/retardos_buffer_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/tipos_ctes_pkg/cte_tipos_buffer_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/COMPONENTES/control_interface/COMPONENTES/acceso/componentes_acceso_pkg/componentes_acceso_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/COMPONENTES/control_interface/componentes_control_interface_pkg/componentes_control_interface_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/componentes_buffer_circular_pkg/componentes_buffer_circular_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/COMPONENTES/BR/CODIGO/br.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/COMPONENTES/control_interface/COMPONENTES/control/CODIGO/control.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/COMPONENTES/control_interface/COMPONENTES/interface/CODIGO/interface.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/ENSAMBLADO/CODIGO/buffer_circular.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/COMPONENTES/control_interface/ENSAMBLADO/CODIGO/controlinterface.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/COMPONENTES/control_interface/COMPONENTES/acceso/ENSAMBLADO/CODIGO/acceso.vhd}

vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/ENSAMBLADO/QUARTUS/../PRUEBAS/procedimientos_prueba_buffer_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB3/buffer_circular/ENSAMBLADO/QUARTUS/../PRUEBAS/prueba_buffer_circular.vhd}

vsim -t 1ps -L altera -L lpm -L sgate -L altera_mf -L altera_lnsim -L cycloneiv_hssi -L cycloneiv_pcie_hip -L cycloneiv -L rtl_work -L work -voptargs="+acc"  prueba_buffer_circular

do D:/FIB_Q8/AC2/LAB3/buffer_circular/ENSAMBLADO/QUARTUS/../PRUEBAS/formato_ventanas.do
