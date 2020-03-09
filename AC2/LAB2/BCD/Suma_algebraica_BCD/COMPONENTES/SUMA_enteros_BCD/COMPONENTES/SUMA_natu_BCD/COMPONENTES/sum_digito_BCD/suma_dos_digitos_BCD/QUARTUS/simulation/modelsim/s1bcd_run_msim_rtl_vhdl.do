transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {D:/FIB_Q8/AC2/LAB2/BCD/tipos_ctes_pkg/retardos_bcd_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB2/BCD/tipos_ctes_pkg/cte_tipos_bcd_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB2/BCD/Suma_algebraica_BCD/COMPONENTES/SUMA_enteros_BCD/COMPONENTES/SUMA_natu_BCD/COMPONENTES/sum_digito_BCD/componentes_dig_BCD_pkg/componentes_digito_bcd_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB2/BCD/Suma_algebraica_BCD/COMPONENTES/SUMA_enteros_BCD/COMPONENTES/SUMA_natu_BCD/COMPONENTES/sum_digito_BCD/COMPONENTES/sumador_binario/CODIGO/snbits.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB2/BCD/Suma_algebraica_BCD/COMPONENTES/SUMA_enteros_BCD/COMPONENTES/SUMA_natu_BCD/COMPONENTES/sum_digito_BCD/COMPONENTES/mayor9/CODIGO/mayor9.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB2/BCD/Suma_algebraica_BCD/COMPONENTES/SUMA_enteros_BCD/COMPONENTES/SUMA_natu_BCD/COMPONENTES/sum_digito_BCD/suma_dos_digitos_BCD/CODIGO/s1bcd.vhd}

vcom -93 -work work {D:/FIB_Q8/AC2/LAB2/BCD/Suma_algebraica_BCD/COMPONENTES/SUMA_enteros_BCD/COMPONENTES/SUMA_natu_BCD/COMPONENTES/sum_digito_BCD/suma_dos_digitos_BCD/QUARTUS/../../../../../../../../../tipos_ctes_pkg/retardos_bcd_pkg.vhd}
vcom -93 -work work {D:/FIB_Q8/AC2/LAB2/BCD/Suma_algebraica_BCD/COMPONENTES/SUMA_enteros_BCD/COMPONENTES/SUMA_natu_BCD/COMPONENTES/sum_digito_BCD/suma_dos_digitos_BCD/QUARTUS/../PRUEBAS/prueba_s1bcd.vhd}

vsim -t 1ps -L altera -L lpm -L sgate -L altera_mf -L altera_lnsim -L cycloneiv_hssi -L cycloneiv_pcie_hip -L cycloneiv -L rtl_work -L work -voptargs="+acc"  prueba_s1bcd

do D:/FIB_Q8/AC2/LAB2/BCD/Suma_algebraica_BCD/COMPONENTES/SUMA_enteros_BCD/COMPONENTES/SUMA_natu_BCD/COMPONENTES/sum_digito_BCD/suma_dos_digitos_BCD/QUARTUS/../PRUEBAS/formato_ventanas.do
