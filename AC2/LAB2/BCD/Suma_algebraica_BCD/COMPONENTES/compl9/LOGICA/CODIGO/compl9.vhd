--
-- Copyright (c) 2018, UPC
-- All rights reserved.
-- 

library ieee;
use ieee.std_logic_1164.all;
use work.cte_tipos_bcd_pkg.all;
use work.retardos_bcd_pkg.all;

entity compl9 is 
port ( X: in st_bcd;
	Z: out st_bcd);
end compl9;

architecture comportamiento of compl9 is
begin

	z(0) <= not x(0);
	z(1) <= x(1);
	z(2) <= x(1) xor x(2);
	z(3) <= (not x(1) and not x(2) and not x(3));

end comportamiento;

