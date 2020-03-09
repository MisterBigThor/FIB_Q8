--
-- Copyright (c) 2018, UPC
-- All rights reserved.
-- 

library ieee;
use ieee.std_logic_1164.all;
use work.cte_tipos_bcd_pkg.all;
use work.retardos_bcd_pkg.all;
use work.componentes_sum_algebraica_pkg.all;

entity sAlgeBCD is
port (a: in st_ndig_bcd_mas_1; --9 BITS
		b: in st_ndig_bcd_mas_1;
		sumres: in std_logic;
		s: out st_ndig_bcd_mas_1;
		irre: out std_logic);
end sAlgeBCD;

architecture estructural of sAlgeBCD is

signal Z, bcomp: st_ndig_bcd_mas_1; --9 bits -> (signo, BCD1, BCD0)

begin
-- instanciacion compl9 mediante sentencias generate
	
	
	alfa: for i in 0 to ndigitos-1 --0 to 2
		generate
			comparadorI: compl9 port map(	x=>b(((i+1)*num_bcd - 1) downto (i*num_bcd)),z=>Z(((i+1)*num_bcd - 1) downto (i*num_bcd)));
		end generate;
		
	Z(8) <= sumres xor b(8);
-- seleccion operando B
	
	bcomp <= b after retmux when sumres='0' else Z after retmux;

-- instantacion sumador

	sumador: sentBCD port map(a=>a, b=>bcomp, cen=>sumres, s=>s, irre=>irre);

end estructural;
