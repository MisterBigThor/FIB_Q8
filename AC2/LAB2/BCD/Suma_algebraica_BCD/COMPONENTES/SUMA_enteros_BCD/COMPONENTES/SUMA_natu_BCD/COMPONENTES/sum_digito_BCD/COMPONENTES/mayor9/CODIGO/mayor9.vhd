--
-- Copyright (c) 2018, UPC
-- All rights reserved.
-- 

library ieee;
use ieee.std_logic_1164.all;
use work.cte_tipos_bcd_pkg.all;
use work.retardos_bcd_pkg.all;

entity mayor9 is 
port (X: in st_bcd_mas_1;
	S: out st_bcd;
	csal: out std_logic);
end mayor9;

architecture comportamiento of mayor9 is
-- senyales
	signal masigual9 : std_logic;
begin

--	S <= (others => '0') after retmayor9;
--	csal <= '0' after retmayor9;
	masigual9 <= (X(4) or (X(3) and X(2)) or (X(3) and X(1))) after retmayor9;
	S(1) <= '0' or masigual9;
	S(2) <= '0' or masigual9;
	S(3) <= '0';
	S(0) <= '0';
	csal <= masigual9;
end comportamiento;


