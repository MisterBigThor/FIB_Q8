--
-- Copyright (c) 2018, UPC
-- All rights reserved.
-- 

library ieee;		
use ieee.std_logic_1164.all;		
use work.all;		
		
entity prueba_S4bits is 		

end prueba_S4bits;		
		
architecture prueba of prueba_S4bits is		
		
component S4bits is 		
generic(ret_xor: time := 15 ns; ret_and: time := 10 ns; ret_or: time := 10 ns);
port (A: in std_logic_vector(3 downto 0);
	B: in std_logic_vector(3 downto 0);
	cen: in	std_logic;
	SUM: out std_logic_vector(3 downto 0);
	csal: out std_logic);
end component;				

-- senyales	
	signal Aaux, Baux, SUMaux : std_logic_vector(3 downto 0);
	signal cenaux, csalaux : std_logic;
		
begin	
-- instanciacion y estimulos
	sum4: S4bits port map(A=>Aaux, B=>Baux, cen=>cenaux, SUM=>SUMaux, csal=>csalaux);
	prueba: process
		begin
		Aaux <= "0001";
		Baux <= "0001";
		cenaux <= '0';
		wait for 100 ns;
		Aaux <= "0001";
		Baux <= "0011";
		wait;
		end process;
end prueba;		

