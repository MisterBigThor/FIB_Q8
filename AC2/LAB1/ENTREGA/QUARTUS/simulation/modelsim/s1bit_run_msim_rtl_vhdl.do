transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {D:/FIB_Q8/AC2/LAB1/ENTREGA/CODIGO/s1bit.vhd}

