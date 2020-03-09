--
-- Copyright (c) 2018, UPC
-- All rights reserved.
-- 

library ieee;
use ieee.std_logic_1164.all;
use work.cte_tipos_bcd_pkg.all;
use work.componentes_snBCD_pkg.all;

entity sentBCD is
port (a: in st_ndig_bcd_mas_1;
	b: in st_ndig_bcd_mas_1;
	cen: in std_logic;
	s: out st_ndig_bcd_mas_1;
	irre: out std_logic );
end sentBCD;

architecture estructural of sentBCD is
--senyales	
	signal c0, sumSign : std_logic; 
	signal sum0: st_ndig_bcd;
	

begin

	sumBDC0: snBCD port map(a=>a(7 downto 0), b=>b(7 downto 0), cen=>cen, s=>sum0, csal=>c0);	
	sum1bit: s1bit port map(x=>a(8), y=>a(8), cen=>c0, s=>sumSign);
	s <= sumSign & sum0;
	irre <= ((not a(8)) and (not b(8)) and sumSign) or (a(8) and b(8) and (not sumSign));
end estructural;

